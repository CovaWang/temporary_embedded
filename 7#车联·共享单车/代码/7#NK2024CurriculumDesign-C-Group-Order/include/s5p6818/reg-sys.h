/*
 * reg-sys.h
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
#ifndef __S5P6818_REG_SYS_H__
#define __S5P6818_REG_SYS_H__

#define S5P6818_SYS_CLKMODEREG0			(0xC0010000 + 0x0000)
#define S5P6818_SYS_CLKMODEREG1			(0xC0010000 + 0x0004)

#define S5P6818_SYS_PLLSETREG0			(0xC0010000 + 0x0008)
#define S5P6818_SYS_PLLSETREG1			(0xC0010000 + 0x000C)
#define S5P6818_SYS_PLLSETREG2			(0xC0010000 + 0x0010)
#define S5P6818_SYS_PLLSETREG3			(0xC0010000 + 0x0014)

#define S5P6818_SYS_CLKDIVREG0			(0xC0010000 + 0x0020)
#define S5P6818_SYS_CLKDIVREG1			(0xC0010000 + 0x0024)
#define S5P6818_SYS_CLKDIVREG2			(0xC0010000 + 0x0028)
#define S5P6818_SYS_CLKDIVREG3			(0xC0010000 + 0x002C)
#define S5P6818_SYS_CLKDIVREG4			(0xC0010000 + 0x0030)
#define S5P6818_SYS_CLKDIVREG5			(0xC0010000 + 0x0034)
#define S5P6818_SYS_CLKDIVREG6			(0xC0010000 + 0x0038)
#define S5P6818_SYS_CLKDIVREG7			(0xC0010000 + 0x003C)
#define S5P6818_SYS_CLKDIVREG8			(0xC0010000 + 0x0040)

#define S5P6818_SYS_PLLSETREG0_SSCG		(0xC0010000 + 0x0048)
#define S5P6818_SYS_PLLSETREG1_SSCG		(0xC0010000 + 0x004C)
#define S5P6818_SYS_PLLSETREG2_SSCG		(0xC0010000 + 0x0050)
#define S5P6818_SYS_PLLSETREG3_SSCG		(0xC0010000 + 0x0054)

#define S5P6818_SYS_GPIOWAKEUPPRISEENB	(0xC0010000 + 0x0200)
#define S5P6818_SYS_GPIOWAKEUPFALLENB	(0xC0010000 + 0x0204)
#define S5P6818_SYS_GPIORSTENB			(0xC0010000 + 0x0208)
#define S5P6818_SYS_GPIOWKENB			(0xC0010000 + 0x020C)
#define S5P6818_SYS_GPIOINTENB			(0xC0010000 + 0x0210)
#define S5P6818_SYS_GPIOINTPEND			(0xC0010000 + 0x0214)

#define S5P6818_SYS_RESETSTATUS			(0xC0010000 + 0x0218)
#define S5P6818_SYS_INTENABLE			(0xC0010000 + 0x021C)
#define S5P6818_SYS_INTPEND				(0xC0010000 + 0x0220)
#define S5P6818_SYS_PWRCONT				(0xC0010000 + 0x0224)
#define S5P6818_SYS_PWRMODE				(0xC0010000 + 0x0228)
#define S5P6818_SYS_RSTCONFIG			(0xC0010000 + 0x023C)

#define S5P6818_SYS_IP_RSTCON0			(0xC0010000 + 0x2000)
#define S5P6818_SYS_IP_RSTCON1			(0xC0010000 + 0x2004)
#define S5P6818_SYS_IP_RSTCON2			(0xC0010000 + 0x2008)

#endif /* __S5P6818_REG_WDG_H__ */
