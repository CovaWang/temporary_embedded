/*
 * libm/log10.c
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

#include <math.h>

static const double
	two54 = 1.80143985094819840000e+16,
	ivln10 = 4.34294481903251816668e-01,
	log10_2hi = 3.01029995663611771306e-01,
	log10_2lo = 3.69423907715893078616e-13;

static const double zero = 0.0;

double log10(double x)
{
	double y, z;
	s32_t i, k, hx;
	u32_t lx;

	EXTRACT_WORDS(hx,lx,x);

	k = 0;
	if (hx < 0x00100000)
	{
		if (((hx & 0x7fffffff) | lx) == 0)
			return -two54 / zero;
		if (hx < 0)
			return (x - x) / zero;
		k -= 54;
		x *= two54;
		GET_HIGH_WORD(hx,x);
	}
	if (hx >= 0x7ff00000)
		return x + x;
	k += (hx >> 20) - 1023;
	i = ((u32_t) k & 0x80000000) >> 31;
	hx = (hx & 0x000fffff) | ((0x3ff - i) << 20);
	y = (double) (k + i);
	SET_HIGH_WORD(x,hx);
	z = y * log10_2lo + ivln10 * log(x);
	return z + y * log10_2hi;
}
