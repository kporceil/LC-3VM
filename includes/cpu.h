/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cpu.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/03 12:00:00 by kporceil          #+#    #+#             */
/*   Updated: 2026/09/03 12:06:07 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CPU_H
# define CPU_H

enum //Registers
{
	R_R0 = 0,
	R_R1,
	R_R2,
	R_R3,
	R_R4,
	R_R5,
	R_R6,
	R_R7,
	R_PC,
	R_COND,
	R_COUNT,
};

enum //opcode
{
	OP_BR = 0,
	OP_ADD,
	OP_LD,
	OP_ST,
	OP_JSR,
	OP_AND,
	OP_LDR,
	OP_STR,
	OP_RTI,
	OP_NOT,
	OP_LDI,
	OP_STI,
	OP_JMP,
	OP_RES,
	OP_LEA,
	OP_TRAP,
};

enum //conditions flags
{
	FL_POS = 1 << 0,
	FL_ZRO = 1 << 1,
	FL_NEG = 1 << 2,
};

#endif
