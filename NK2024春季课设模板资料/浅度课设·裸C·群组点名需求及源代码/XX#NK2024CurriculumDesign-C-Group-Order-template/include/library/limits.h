/*
 * limits.h
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
#ifndef __ARM32_LIMITS_H__
#define __ARM32_LIMITS_H__

#ifdef __cplusplus
extern "C" {
#endif

/* Number of bits in a 'char' */
#define CHAR_BIT		(8)

/* Minimum and maximum values a 'signed char' can hold */
#define SCHAR_MIN		(-128)
#define SCHAR_MAX		127

/* Minimum and maximum values a 'char' can hold */
#define CHAR_MIN		(-128)
#define CHAR_MAX		127

/* Maximum value an 'unsigned char' can hold (Minimum is 0) */
#define UCHAR_MAX		255


/* Minimum and maximum values a 'signed short int' can hold */
#define SHRT_MIN		(-32768)
#define SHRT_MAX		32767

/* Maximum value an 'unsigned short int' can hold (Minimum is 0) */
#define USHRT_MAX		65535


/* Minimum and maximum values a 'signed int' can hold */
#define INT_MIN			(-INT_MAX - 1)
#define INT_MAX			2147483647

/* Maximum value an 'unsigned int' can hold (Minimum is 0) */
#define UINT_MAX		4294967295U


/* Minimum and maximum values a 'signed long int' can hold */
#define LONG_MIN		(-LONG_MAX - 1L)
#define LONG_MAX		2147483647L

/* Maximum value an 'unsigned long int' can hold (Minimum is 0) */
#define ULONG_MAX		4294967295UL


/* Minimum and maximum values a 'signed long long int' can hold */
#define LLONG_MIN		(-LLONG_MAX - 1LL)
#define LLONG_MAX		9223372036854775807LL

/* Maximum value an 'unsigned long long int' can hold (Minimum is 0) */
#define ULLONG_MAX		18446744073709551615ULL


/* Minimum and maximum values a 'max int' can hold */
#define INTMAX_MIN		LLONG_MIN
#define INTMAX_MAX		LLONG_MAX

/* Maximum value an 'max uint' can hold (Minimum is 0) */
#define UINTMAX_MAX		ULLONG_MAX

#ifdef __cplusplus
}
#endif

#endif /* __ARM32_LIMITS_H__ */
