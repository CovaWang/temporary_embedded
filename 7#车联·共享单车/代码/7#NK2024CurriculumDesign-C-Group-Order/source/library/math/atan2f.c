/*
 * libm/atan2f.c
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

static const float
	tiny = 1.0e-30,
	zero = 0.0,
	pi_o_4 = 7.8539818525e-01,
	pi_o_2 = 1.5707963705e+00,
	pi = 3.1415927410e+00,
	pi_lo = -8.7422776573e-08;

float atan2f(float y, float x)
{
	float z;
	s32_t k, m, hx, hy, ix, iy;

	GET_FLOAT_WORD(hx,x);
	ix = hx & 0x7fffffff;
	GET_FLOAT_WORD(hy,y);
	iy = hy & 0x7fffffff;
	if ((ix > 0x7f800000) || (iy > 0x7f800000))
		return x + y;
	if (hx == 0x3f800000)
		return atanf(y);
	m = ((hy >> 31) & 1) | ((hx >> 30) & 2);

	if (iy == 0)
	{
		switch (m)
		{
		case 0:
		case 1:
			return y;
		case 2:
			return pi + tiny;
		case 3:
			return -pi - tiny;
		}
	}

	if (ix == 0)
		return (hy < 0) ? -pi_o_2 - tiny : pi_o_2 + tiny;

	if (ix == 0x7f800000)
	{
		if (iy == 0x7f800000)
		{
			switch (m)
			{
			case 0:
				return pi_o_4 + tiny;
			case 1:
				return -pi_o_4 - tiny;
			case 2:
				return (float) 3.0 * pi_o_4 + tiny;
			case 3:
				return (float) -3.0 * pi_o_4 - tiny;
			}
		}
		else
		{
			switch (m)
			{
			case 0:
				return zero;
			case 1:
				return -zero;
			case 2:
				return pi + tiny;
			case 3:
				return -pi - tiny;
			}
		}
	}

	if (iy == 0x7f800000)
		return (hy < 0) ? -pi_o_2 - tiny : pi_o_2 + tiny;

	k = (iy - ix) >> 23;
	if (k > 60)
		z = pi_o_2 + (float) 0.5 * pi_lo;
	else if (hx < 0 && k < -60)
		z = 0.0;
	else
		z = atanf(fabsf(y / x));
	switch (m)
	{
	case 0:
		return z;
	case 1:
	{
		u32_t zh;
		GET_FLOAT_WORD(zh,z);
		SET_FLOAT_WORD(z,zh ^ 0x80000000);
	}
		return z;
	case 2:
		return pi - (z - pi_lo);
	default:
		return (z - pi_lo) - pi;
	}
}
