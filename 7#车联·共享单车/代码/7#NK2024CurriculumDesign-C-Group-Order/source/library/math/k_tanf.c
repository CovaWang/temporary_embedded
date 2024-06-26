/*
 * libm/k_tanf.c
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

static const double T[] = {
	0x15554d3418c99f.0p-54,
	0x1112fd38999f72.0p-55,
	0x1b54c91d865afe.0p-57,
	0x191df3908c33ce.0p-58,
	0x185dadfcecf44e.0p-61,
	0x1362b9bf971bcd.0p-59,
};

float __kernel_tandf(double x, int iy)
{
	double z, r, w, s, t, u;

	z = x * x;

	r = T[4] + z * T[5];
	t = T[2] + z * T[3];
	w = z * z;
	s = z * x;
	u = T[0] + z * T[1];
	r = (x + s * u) + (s * w) * (t + w * r);
	if (iy == 1)
		return r;
	else
		return -1.0 / r;
}
