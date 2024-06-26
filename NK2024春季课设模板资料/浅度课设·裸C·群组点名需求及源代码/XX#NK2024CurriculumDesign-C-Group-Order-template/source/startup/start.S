/*
 * start.S
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
.macro irq_save_regs
	sub	sp, sp, #72
	stmia sp, {r0 - r12}
	add	r8, sp, #60
	stmdb r8, {sp, lr}^
	str	lr, [r8, #0]
	mrs	r6, spsr
	str	r6, [r8, #4]
	str	r0, [r8, #8]
	mov	r0, sp
.endm

.macro irq_restore_regs
	ldmia sp, {r0 - lr}^
	mov	r0, r0
	ldr	lr, [sp, #60]
	add	sp, sp, #72
	subs pc, lr, #4
.endm

/*
 * Exception vector table
 */
.text
	.arm

	.global	_start
_start:
	b reset
	ldr pc, _undefined_instruction
	ldr pc, _software_interrupt
	ldr pc, _prefetch_abort
	ldr pc, _data_abort
	ldr pc, _not_used
	ldr pc, _irq
	ldr pc, _fiq

_undefined_instruction:
	.long undefined_instruction
_software_interrupt:
	.long software_interrupt
_prefetch_abort:
	.long prefetch_abort
_data_abort:
	.long data_abort
_not_used:
	.long not_used
_irq:
	.long irq
_fiq:
	.long fiq

	.align 4
/* Magic number(16bytes) - xbootmagicnumber */
	.byte 0x78, 0x62, 0x6f, 0x6f, 0x74, 0x6d, 0x61, 0x67, 0x69, 0x63, 0x6e, 0x75, 0x6d, 0x62, 0x65, 0x72
/* Image start and image end information */
	.long __image_start, __image_end
/* Where the image was linked address */
	.long _start
/* Image sha256 digest */
	.long 0, 0, 0, 0
/* Magic number(16bytes) - xbootmagicnumber */
	.byte 0x78, 0x62, 0x6f, 0x6f, 0x74, 0x6d, 0x61, 0x67, 0x69, 0x63, 0x6e, 0x75, 0x6d, 0x62, 0x65, 0x72

/*
 * The actual reset code
 */
reset:
	/* Set the cpu to svc32 mode */
	mrs r0, cpsr
	bic r0, r0, #0x1f
	orr r0, r0, #0xd3
	msr cpsr, r0

	/* Enable NEON/VFP unit */
	mrc p15, #0, r1, c1, c0, #2
	orr r1, r1, #(0xf << 20)
	mcr p15, #0, r1, c1, c0, #2
	mov r1, #0
	mcr p15, #0, r1, c7, c5, #4
	mov r0, #0x40000000
	fmxr fpexc, r0

	/* Cache init */
	mrc	p15, 0, r0, c0, c0, 0
	and	r1, r0, #0x00f00000
	and	r2, r0, #0x0000000f
	orr r2, r2, r1, lsr #20-4
	cmp r2, #0x30
	mrceq p15, 0, r0, c1, c0, 1
	orreq r0, r0, #0x6
	mcreq p15, 0, r0, c1, c0, 1

	/* Invalidate L1 I/D */
	mov r0, #0
	mcr	p15, 0, r0, c8, c7, 0
	mcr	p15, 0, r0, c7, c5, 0

	/* Disable mmu stuff and caches */
	mrc p15, 0, r0, c1, c0, 0
	bic r0, r0, #0x00002000
	bic r0, r0, #0x00000007
	orr r0, r0, #0x00000002
	orr r0, r0, #0x00000800
	mcr p15, 0, r0, c1, c0, 0

	/* Set Vector Base Address Register */
	ldr r0, =_start
	mcr p15, 0, r0, c12, c0, 0
	mrc p15, 0, r0, c1, c0, 0
	bic r0, #(1<<13)
	mcr p15, 0, r0, c1, c0, 0

	/* Initialize stacks */
	mrs r0, cpsr
	bic r0, r0, #0xdf
	orr r1, r0, #0x1b
	msr cpsr_cxsf, r1
	ldr sp, _stack_und_end

	bic r0, r0, #0xdf
	orr r1, r0, #0x17
	msr cpsr_cxsf, r1
	ldr sp, _stack_abt_end

	bic r0, r0, #0xdf
	orr r1, r0, #0x12
	msr cpsr_cxsf, r1
	ldr sp, _stack_irq_end

	bic r0, r0, #0xdf
	orr r1, r0, #0x11
	msr cpsr_cxsf, r1
	ldr sp, _stack_fiq_end

	bic r0, r0, #0xdf
	orr r1, r0, #0x13
	msr cpsr_cxsf, r1
	ldr sp, _stack_srv_end

	/* Copyself to link address */
	adr r0, _start
	ldr r1, =_start
	cmp r0, r1
	beq 1f
	ldr r0, _image_start
	adr r1, _start
	ldr r2, _image_end
	sub r2, r2, r0
	bl memcpy
1:	nop

	/* Copy data section */
	ldr r0, _data_start
	ldr r3, _image_start
	ldr r1, _data_shadow_start
	sub r1, r1, r3
	adr r3, _start
	add r1, r1 ,r3
	ldr r2, _data_shadow_start
	ldr r3, _data_shadow_end
	sub r2, r3, r2
	bl memcpy

	/* Clear bss section */
	ldr r0, _bss_start
	ldr r2, _bss_end
	sub r2, r2, r0
	mov r1, #0
	bl memset

	/* Call _main */
	ldr r1, =_main
	mov pc, r1
_main:
	mov r0, #1;
	mov r1, #0;
	bl main
	b _main

/*
 * Exception handlers
 */
	.align 5
undefined_instruction:
	b	.

	.align 5
software_interrupt:
	b	.

	.align 5
prefetch_abort:
	b	.

	.align 5
data_abort:
	b	.

	.align 5
not_used:
	b	.

	.align 5
	.global irq
irq:
	ldr	sp, _stack_irq_end
	irq_save_regs
	bl do_irq
	irq_restore_regs

	.align 5
fiq:
	ldr	sp, _stack_fiq_end
	irq_save_regs
	bl do_irq
	irq_restore_regs

/*
 * The location of section
 */
 	.align 4
_image_start:
	.long __image_start
_image_end:
	.long __image_end
_data_shadow_start:
	.long __data_shadow_start
_data_shadow_end:
	.long __data_shadow_end
_data_start:
	.long __data_start
_data_end:
	.long __data_end
_bss_start:
	.long __bss_start
_bss_end:
	.long __bss_end
_stack_und_end:
	.long __stack_und_end
_stack_abt_end:
	.long __stack_abt_end
_stack_irq_end:
	.long __stack_irq_end
_stack_fiq_end:
	.long __stack_fiq_end
_stack_srv_end:
	.long __stack_srv_end
