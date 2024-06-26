/*
 * reg-dpc.h
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
#ifndef __S5P6818_REG_DPC_H__
#define __S5P6818_REG_DPC_H__

#define S5P6818_DPC0_BASE			(0xC0102000)
#define S5P6818_DPC1_BASE			(0xC0102400)

#define DPC_HTOTAL					(0x8f8)
#define DPC_HSWIDTH					(0x8fc)
#define DPC_HASTART					(0x900)
#define DPC_HAEND					(0x904)
#define DPC_VTOTAL					(0x908)
#define DPC_VSWIDTH					(0x90c)
#define DPC_VASTART					(0x910)
#define DPC_VAEND					(0x914)
#define DPC_CTRL0					(0x918)
#define DPC_CTRL1					(0x91c)
#define DPC_EVTOTAL					(0x920)
#define DPC_EVSWIDTH				(0x924)
#define DPC_EVASTART				(0x928)
#define DPC_EVAEND					(0x92c)
#define DPC_CTRL2					(0x930)
#define DPC_VSEOFFSET				(0x934)
#define DPC_VSSOFFSET				(0x938)
#define DPC_EVSEOFFSET				(0x93c)
#define DPC_EVSSOFFSET				(0x940)
#define DPC_DELAY0					(0x944)
#define DPC_DELAY1					(0x978)
#define DPC_MPUTIME0				(0x97c)
#define DPC_POLCTRL					(0x9a4)
#define DPC_CLKENB					(0xbc0)
#define DPC_CLKGEN0L				(0xbc4)
#define DPC_CLKGEN0H				(0xbc8)
#define DPC_CLKGEN1L				(0xbcc)
#define DPC_CLKGEN1H				(0xbd0)

/* Just for primary */
#define DPC_MPUTIME1				(0x980)
#define DPC_MPUWRDATAL				(0x984)
#define DPC_MPUINDEX				(0x988)
#define DPC_MPUSTATUS				(0x98c)
#define DPC_MPUDATAH				(0x990)
#define DPC_MPURDATAL				(0x994)
#define DPC_CMDBUFFERDATAL			(0x99c)
#define DPC_CMDBUFFERDATAH			(0x9a0)
#define DPC_PADPOSITION0			(0x9a8)
#define DPC_PADPOSITION1			(0x9ac)
#define DPC_PADPOSITION2			(0x9b0)
#define DPC_PADPOSITION3			(0x9b4)
#define DPC_PADPOSITION4			(0x9b8)
#define DPC_PADPOSITION5			(0x9bc)
#define DPC_PADPOSITION6			(0x9c0)
#define DPC_PADPOSITION7			(0x9c4)
#define DPC_RGBMASK0				(0x9c8)
#define DPC_RGBMASK1				(0x9cc)
#define DPC_RGBSHIFT				(0x9d0)
#define DPC_DATAFLUSH				(0x9d4)

/* Just for secondary */
#define DPC_UPSCALECON0 			(0x948)
#define DPC_UPSCALECON1 			(0x94c)

#endif /* __S5P6818_REG_DPC_H__ */
