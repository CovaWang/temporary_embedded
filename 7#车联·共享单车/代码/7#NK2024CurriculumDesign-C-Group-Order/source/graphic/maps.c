/*
 * kernel/graphic/maps.c
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

#include <types.h>
#include <stddef.h>
#include <graphic/maps.h>
#include <graphic/maps/software.h>

bool_t surface_set_maps(struct surface_maps * maps)
{
	if(!maps)
		return FALSE;

	if(!maps->point)
		maps->point = map_software_point;

	if(!maps->hline)
		maps->hline = map_software_hline;

	if(!maps->vline)
		maps->vline = map_software_vline;

	if(!maps->fill)
		maps->fill = map_software_fill;

	if(!maps->blit)
		maps->blit = map_software_blit;

	if(!maps->scale)
		maps->scale = map_software_scale;

	if(!maps->rotate)
		maps->rotate = map_software_rotate;

	return TRUE;
}
