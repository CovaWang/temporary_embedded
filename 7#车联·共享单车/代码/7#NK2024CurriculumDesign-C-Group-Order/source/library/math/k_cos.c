/*
 * libm/k_cos.c
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
	one = 1.00000000000000000000e+00,
	C1 = 4.16666666666666019037e-02,
	C2 = -1.38888888888741095749e-03,
	C3 = 2.48015872894767294178e-05,
	C4 = -2.75573143513906633035e-07,
	C5 = 2.08757232129817482790e-09,
	C6 = -1.13596475577881948265e-11;

double __kernel_cos(double x, double y)
{
	double hz, z, r, w;

	z = x * x;
	r = z * (C1 + z * (C2 + z * (C3 + z * (C4 + z * (C5 + z * C6)))));
	hz = (float) 0.5 * z;
	w = one - hz;
	return w + (((one - w) - hz) + (z * r - x * y));
}
