/*
 * reg-alv.h
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
#ifndef __S5P6818_REG_ALV_H__
#define __S5P6818_REG_ALV_H__

#define S5P6818_GPIOALV_BASE					(0xC0010000)

#define GPIOALV_PWRGATEREG						(0x0800)
#define GPIOALV_ASYNCDETECTMODERSTREG0			(0x0804)
#define GPIOALV_ASYNCDETECTMODESETREG0			(0x0808)
#define GPIOALV_LOWASYNCDETECTMODEREADREG		(0x080C)
#define GPIOALV_ASYNCDETECTMODERSTREG1			(0x0810)
#define GPIOALV_ASYNCDETECTMODESETREG1			(0x0814)
#define GPIOALV_HIGHASYNCDETECTMODEREADREG		(0x0818)
#define GPIOALV_DETECTMODERSTREG0				(0x081C)
#define GPIOALV_DETECTMODESETREG0				(0x0820)
#define GPIOALV_FALLDETECTMODEREADREG			(0x0824)
#define GPIOALV_DETECTMODERSTREG1				(0x0828)
#define GPIOALV_DETECTMODESETREG1				(0x082C)
#define GPIOALV_RISEDETECTMODEREADREG			(0x0830)
#define GPIOALV_DETECTMODERSTREG2				(0x0834)
#define GPIOALV_DETECTMODESETREG2				(0x0838)
#define GPIOALV_LOWDETECTMODEREADREG			(0x083C)
#define GPIOALV_DETECTMODERSTREG3				(0x0840)
#define GPIOALV_DETECTMODESETREG3				(0x0844)
#define GPIOALV_HIGHDETECTMODEREADREG			(0x0848)
#define GPIOALV_DETECTENBRSTREG					(0x084C)
#define GPIOALV_DETECTENBSETREG					(0x0850)
#define GPIOALV_DETECTENBREADREG				(0x0854)
#define GPIOALV_INTENBRSTREG					(0x0858)
#define GPIOALV_INTENBSETREG					(0x085C)
#define GPIOALV_INTENBREADREG					(0x0860)
#define GPIOALV_DETECTPENDREG					(0x0864)
#define GPIOALV_SCRATCHRSTREG					(0x0868)
#define GPIOALV_SCRATCHSETREG					(0x086C)
#define GPIOALV_SCRATCHREADREG					(0x0870)
#define GPIOALV_PADOUTENBRSTREG					(0x0874)
#define GPIOALV_PADOUTENBSETREG					(0x0878)
#define GPIOALV_PADOUTENBREADREG				(0x087C)
#define GPIOALV_PADPULLUPRSTREG					(0x0880)
#define GPIOALV_PADPULLUPSETREG					(0x0884)
#define GPIOALV_PADPULLUPREADREG				(0x0888)
#define GPIOALV_PADOUTRSTREG					(0x088C)
#define GPIOALV_PADOUTSETREG					(0x0890)
#define GPIOALV_PADOUTREADREG					(0x0894)
#define GPIOALV_VDDCTRLRSTREG					(0x0898)
#define GPIOALV_VDDCTRLSETREG					(0x089C)
#define GPIOALV_VDDCTRLREADREG					(0x08A0)
#define GPIOALV_CLEARWAKEUPSTATUS				(0x08A4)
#define GPIOALV_SLEEPWAKEUPSTATUS				(0x08A8)
#define GPIOALV_SCRATCHRST1						(0x08AC)
#define GPIOALV_SCRATCHRST2						(0x08B8)
#define GPIOALV_SCRATCHRST3						(0x08C4)
#define GPIOALV_SCRATCHRST4						(0x08D0)
#define GPIOALV_SCRATCHRST5						(0x08DC)
#define GPIOALV_SCRATCHRST6						(0x08E8)
#define GPIOALV_SCRATCHRST7						(0x08F4)
#define GPIOALV_SCRATCHRST8						(0x0900)
#define GPIOALV_SCRATCHSET1						(0x08B0)
#define GPIOALV_SCRATCHSET2						(0x08BC)
#define GPIOALV_SCRATCHSET3						(0x08C8)
#define GPIOALV_SCRATCHSET4						(0x08D4)
#define GPIOALV_SCRATCHSET5						(0x08E0)
#define GPIOALV_SCRATCHSET6						(0x08EC)
#define GPIOALV_SCRATCHSET7						(0x08F8)
#define GPIOALV_SCRATCHSET8						(0x0904)
#define GPIOALV_SCRATCHREAD1					(0x08B4)
#define GPIOALV_SCRATCHREAD2					(0x08C0)
#define GPIOALV_SCRATCHREAD3					(0x08CC)
#define GPIOALV_SCRATCHREAD4					(0x08D8)
#define GPIOALV_SCRATCHREAD5					(0x08E4)
#define GPIOALV_SCRATCHREAD6					(0x08F0)
#define GPIOALV_SCRATCHREAD7					(0x08FC)
#define GPIOALV_SCRATCHREAD8					(0x0908)
#define GPIOALV_VDDOFFDELAYRST					(0x090C)
#define GPIOALV_VDDOFFDELAYSET					(0x0910)
#define GPIOALV_VDDOFFDELAYVAL					(0x0914)
#define GPIOALV_VDDOFFDELAYIME					(0x0918)
#define GPIOALV_GPIOINPUTVALUE					(0x091C)
#define GPIOALV_PMUNISOLATE						(0x0D00)
#define GPIOALV_PMUNPWRUPPRE					(0x0D04)
#define GPIOALV_PMUNPWRUP						(0x0D08)
#define GPIOALV_PMUNPWRUPACK					(0x0D0C)

#endif /* __S5P6818_REG_ALV_H__ */
