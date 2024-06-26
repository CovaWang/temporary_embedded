/*
 * kernel/graphic/maps/software/sw_point.c
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

#include <graphic/maps/software.h>

bool_t map_software_point(struct surface_t * surface, s32_t x, s32_t y, u32_t c, enum blend_mode mode)
{
	s32_t minx, miny;
	s32_t maxx, maxy;

	if (!surface)
		return FALSE;

	if (!surface->pixels)
		return FALSE;

	if (surface->info.bits_per_pixel < 8)
		return FALSE;

	minx = surface->clip.x;
	maxx = surface->clip.x + surface->clip.w - 1;
	miny = surface->clip.y;
	maxy = surface->clip.y + surface->clip.h - 1;

	if (x < minx || x > maxx || y < miny || y > maxy)
	{
		return TRUE;
	}

	if(mode == BLEND_MODE_REPLACE)
	{
		surface_sw_set_pixel(surface, x, y, c);
	}
	else if(mode == BLEND_MODE_ALPHA)
	{
		surface_sw_set_pixel_with_alpha(surface, x, y, c);
	}
	else
	{
		return FALSE;
	}

	return TRUE;
}
