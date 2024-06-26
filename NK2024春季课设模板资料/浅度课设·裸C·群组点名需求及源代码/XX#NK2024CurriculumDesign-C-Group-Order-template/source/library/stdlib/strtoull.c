/*
 * libc/stdlib/strtoull.c
 *
 * Copyright (C) 2015-2018 BeiJing OURS Education Technology Co., Ltd.
 * Copyright (C) 2017 Tangle.Xu. All rights reserved.
 *
 * Official site: http://www.ourselec.com
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, you can access it online at
 * http://www.gnu.org/licenses/gpl-2.0.html.
 *
 * Author: Tangle.Xu <420724072@qq.com>
 * Date: 2017.05
 * Version: v0.1
 *
 */

#include <ctype.h>
#include <errno.h>
#include <limits.h>
#include <stdlib.h>

/*
 * Convert a string to an unsigned long long.
 *
 * Ignores 'locale' stuff.  Assumes that the upper and lower case
 * alphabets and digits are each contiguous.
 */
unsigned long long strtoull(const char * nptr, char ** endptr, int base)
{
	const char * s;
	unsigned long long acc, cutoff;
	int c;
	int neg, any, cutlim;

	s = nptr;
	do {
		c = (unsigned char) *s++;
	} while (isspace(c));

	if (c == '-')
	{
		neg = 1;
		c = *s++;
	}
	else
	{
		neg = 0;
		if (c == '+')
			c = *s++;
	}

	if ((base == 0 || base == 16) && c == '0' && (*s == 'x' || *s == 'X'))
	{
		c = s[1];
		s += 2;
		base = 16;
	}

	if (base == 0)
		base = c == '0' ? 8 : 10;

	switch (base)
	{
    case 4:
    	cutoff = ULLONG_MAX / 4;
        cutlim = ULLONG_MAX % 4;
        break;

    case 8:
    	cutoff = ULLONG_MAX / 8;
        cutlim = ULLONG_MAX % 8;
        break;

    case 10:
    	cutoff = ULLONG_MAX / 10;
        cutlim = ULLONG_MAX % 10;
        break;

    case 16:
    	cutoff = ULLONG_MAX / 16;
        cutlim = ULLONG_MAX % 16;
        break;

	default:
		cutoff = ULLONG_MAX / base;
		cutlim = ULLONG_MAX % base;
		break;
	}

	for (acc = 0, any = 0;; c = (unsigned char) *s++)
	{
		if (isdigit(c))
			c -= '0';
		else if (isalpha(c))
			c -= isupper(c) ? 'A' - 10 : 'a' - 10;
		else
			break;

		if (c >= base)
			break;

		if (any < 0)
			continue;

		if (acc > cutoff || (acc == cutoff && c > cutlim))
		{
			any = -1;
			acc = ULLONG_MAX;
			errno = ERANGE;
		}
		else
		{
			any = 1;
			acc *= (unsigned long long) base;
			acc += c;
		}
	}

	if (neg && any > 0)
		acc = -acc;

	if (endptr != 0)
		*endptr = (char *) (any ? s - 1 : nptr);

	return (acc);
}

