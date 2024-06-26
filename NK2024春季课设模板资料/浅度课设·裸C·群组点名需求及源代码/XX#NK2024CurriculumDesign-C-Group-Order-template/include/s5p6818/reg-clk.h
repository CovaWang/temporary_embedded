/*
 * reg-clk.h
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
#ifndef __S5P6818_REG_CLK_H__
#define __S5P6818_REG_CLK_H__

/*
 * Clock Generator Level 0
 */
#define S5P6818_CLK_CODA960CLKENB				(0xC00C0000 + 0x7000)
#define S5P6818_CLK_CRYPTOCLKENB				(0xC00C0000 + 0x6000)
#define S5P6818_CLK_I2C0CLKENB					(0xC00A0000 + 0xE000)
#define S5P6818_CLK_I2C1CLKENB					(0xC00A0000 + 0xF000)
#define S5P6818_CLK_I2C2CLKENB					(0xC00B0000 + 0x0000)
#define S5P6818_CLK_GPUCLKENB					(0xC00C0000 + 0x3000)
#define S5P6818_CLK_MPEGTSICLKENB				(0xC00C0000 + 0xB700)
#define S5P6818_CLK_PDMCLKENB					(0xC00C0000 + 0xB000)
#define S5P6818_CLK_SCALERCLKENB				(0xC00B0000 + 0x6000)
#define S5P6818_CLK_DEINTERLACECLKENB			(0xC00B0000 + 0x5000)
#define S5P6818_CLK_MLC0CLKENB					(0xC0100000 + 0x23C0)
#define S5P6818_CLK_MLC1CLKENB					(0xC0100000 + 0x27C0)

/*
 * Clock Generator Level 1
 */
#define S5P6818_CLK_MIPICSICLKENB				(0xC00C0000 + 0xA000)
#define S5P6818_CLK_MIPICSICLKGEN0L				(0xC00C0000 + 0xA004)
#define S5P6818_CLK_PPMCLKENB					(0xC00C0000 + 0x4000)
#define S5P6818_CLK_PPMCLKGEN0L					(0xC00C0000 + 0x4004)
#define S5P6818_CLK_PWM0CLKENB					(0xC00B0000 + 0xA000)
#define S5P6818_CLK_PWM1CLKENB					(0xC00B0000 + 0xE000)
#define S5P6818_CLK_PWM2CLKENB					(0xC00B0000 + 0xF000)
#define S5P6818_CLK_PWM3CLKENB					(0xC00C0000 + 0x0000)
#define S5P6818_CLK_TIMER0CLKENB				(0xC00B0000 + 0x9000)
#define S5P6818_CLK_TIMER1CLKENB				(0xC00B0000 + 0xB000)
#define S5P6818_CLK_TIMER2CLKENB				(0xC00B0000 + 0xC000)
#define S5P6818_CLK_TIMER3CLKENB				(0xC00B0000 + 0xD000)
#define S5P6818_CLK_PWM0CLKGEN0L				(0xC00B0000 + 0xA004)
#define S5P6818_CLK_PWM1CLKGEN0L				(0xC00B0000 + 0xE004)
#define S5P6818_CLK_PWM2CLKGEN0L				(0xC00B0000 + 0xF004)
#define S5P6818_CLK_PWM3CLKGEN0L				(0xC00C0000 + 0x0004)
#define S5P6818_CLK_TIMER0CLKGEN0L				(0xC00B0000 + 0x9004)
#define S5P6818_CLK_TIMER1CLKGEN0L				(0xC00B0000 + 0xB004)
#define S5P6818_CLK_TIMER2CLKGEN0L				(0xC00B0000 + 0xC004)
#define S5P6818_CLK_TIMER3CLKGEN0L				(0xC00B0000 + 0xD004)
#define S5P6818_CLK_SDMMC0CLKENB				(0xC00C0000 + 0x5000)
#define S5P6818_CLK_SDMMC1CLKENB				(0xC00C0000 + 0xC000)
#define S5P6818_CLK_SDMMC2CLKENB				(0xC00C0000 + 0xD000)
#define S5P6818_CLK_SDMMC0CLKGEN0L				(0xC00C0000 + 0x5004)
#define S5P6818_CLK_SDMMC1CLKGEN0L				(0xC00C0000 + 0xC004)
#define S5P6818_CLK_SDMMC2CLKGEN0L				(0xC00C0000 + 0xD004)
#define S5P6818_CLK_SPDIFTXCLKENB				(0xC00B0000 + 0x8000)
#define S5P6818_CLK_SPDIFTXCLKGEN0L				(0xC00B0000 + 0x8004)
#define S5P6818_CLK_SSP0CLKENB					(0xC00A0000 + 0xC000)
#define S5P6818_CLK_SSP1CLKENB					(0xC00A0000 + 0xD000)
#define S5P6818_CLK_SSP2CLKENB					(0xC00A0000 + 0x7000)
#define S5P6818_CLK_SSP0CLKGEN0L				(0xC00A0000 + 0xC004)
#define S5P6818_CLK_SSP1CLKGEN0L				(0xC00A0000 + 0xD004)
#define S5P6818_CLK_SSP2CLKGEN0L				(0xC00A0000 + 0x7004)
#define S5P6818_CLK_UART0CLKENB					(0xC00A0000 + 0x9000)
#define S5P6818_CLK_UART1CLKENB					(0xC00A0000 + 0x8000)
#define S5P6818_CLK_UART2CLKENB					(0xC00A0000 + 0xA000)
#define S5P6818_CLK_UART3CLKENB					(0xC00A0000 + 0xB000)
#define S5P6818_CLK_UART4CLKENB					(0xC0060000 + 0xE000)
#define S5P6818_CLK_UART5CLKENB					(0xC0080000 + 0x4000)
#define S5P6818_CLK_UART0CLKGEN0L				(0xC00A0000 + 0x9004)
#define S5P6818_CLK_UART1CLKGEN0L				(0xC00A0000 + 0x8004)
#define S5P6818_CLK_UART2CLKGEN0L				(0xC00A0000 + 0xA004)
#define S5P6818_CLK_UART3CLKGEN0L				(0xC00A0000 + 0xB004)
#define S5P6818_CLK_UART4CLKGEN0L				(0xC0060000 + 0xE004)
#define S5P6818_CLK_UART5CLKGEN0L				(0xC0080000 + 0x4004)
#define S5P6818_CLK_VIP0CLKENB					(0xC00C0000 + 0x1000)
#define S5P6818_CLK_VIP1CLKENB					(0xC00C0000 + 0x2000)
#define S5P6818_CLK_VIP0CLKGEN0L				(0xC00C0000 + 0x1004)
#define S5P6818_CLK_VIP1CLKGEN0L				(0xC00C0000 + 0x2004)

/*
 * Clock Generator Level 2
 */
#define S5P6818_CLK_GMACCLKENB					(0xC00C0000 + 0x8000)
#define S5P6818_CLK_GMACCLKGEN0L				(0xC00C0000 + 0x8004)
#define S5P6818_CLK_GMACCLKGEN1L				(0xC00C0000 + 0x800C)
#define S5P6818_CLK_I2S0CLKENB					(0xC00B0000 + 0x2000)
#define S5P6818_CLK_I2S1CLKENB					(0xC00B0000 + 0x3000)
#define S5P6818_CLK_I2S2CLKENB					(0xC00B0000 + 0x4000)
#define S5P6818_CLK_I2S0CLKGEN0L				(0xC00B0000 + 0x2004)
#define S5P6818_CLK_I2S1CLKGEN0L				(0xC00B0000 + 0x3004)
#define S5P6818_CLK_I2S2CLKGEN0L				(0xC00B0000 + 0x4004)
#define S5P6818_CLK_I2S0CLKGEN1L				(0xC00B0000 + 0x200C)
#define S5P6818_CLK_I2S1CLKGEN1L				(0xC00B0000 + 0x300C)
#define S5P6818_CLK_I2S2CLKGEN1L				(0xC00B0000 + 0x400C)
#define S5P6818_CLK_USBHOSTOTGCLKENB			(0xC0060000 + 0xB000)
#define S5P6818_CLK_USBHOSTOTGCLKGEN0L			(0xC0060000 + 0xB004)
#define S5P6818_CLK_USBHOSTOTGCLKGEN1L			(0xC0060000 + 0xB00C)
#define S5P6818_CLK_DPC0CLKENB					(0xC0100000 + 0x2BC0)
#define S5P6818_CLK_DPC1CLKENB					(0xC0100000 + 0x2FC0)
#define S5P6818_CLK_DPC0CLKGEN0L				(0xC0100000 + 0x2BC4)
#define S5P6818_CLK_DPC1CLKGEN0L				(0xC0100000 + 0x2FC4)
#define S5P6818_CLK_DPC0CLKGEN1L				(0xC0100000 + 0x2BCC)
#define S5P6818_CLK_DPC1CLKGEN1L				(0xC0100000 + 0x2FCC)
#define S5P6818_CLK_LVDSCLKENB					(0xC0100000 + 0x8000)
#define S5P6818_CLK_LVDSCLKGEN0L				(0xC0100000 + 0x8004)
#define S5P6818_CLK_LVDSCLKGEN1L				(0xC0100000 + 0x800C)
#define S5P6818_CLK_HDMICLKENB					(0xC0100000 + 0x9000)
#define S5P6818_CLK_HDMICLKGEN0L				(0xC0100000 + 0x9004)
#define S5P6818_CLK_HDMICLKGEN1L				(0xC0100000 + 0x900C)
#define S5P6818_CLK_MIPIDSICLKENB				(0xC0100000 + 0x5000)
#define S5P6818_CLK_MIPIDSICLKGEN0L				(0xC0100000 + 0x5004)
#define S5P6818_CLK_MIPIDSICLKGEN1L				(0xC0100000 + 0x500C)

#endif /* __S5P6818_REG_CLK_H__ */
