/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/03 11:59:08 by kporceil          #+#    #+#             */
/*   Updated: 2026/09/03 12:51:41 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <stdio.h>
#include "memory.h"
#include "cpu.h"

uint16_t memory[MEMORY_MAX];
uint16_t reg[R_COUNT];

int
main(int argc, char* argv[])
{

	if (argc < 2)
	{
		printf("lc3 [image-file1] ...\n");
		return (2);
	}

	for (int i = 1; i < argc; ++i)
	{
		if (read_image(argv[i]) == -1)
		{
			printf("failed to load image: %s\n", argv[i]);
			return (1);
		}
	}
	// TODO: Load arguments
	// TODO: setup

	enum { PC_START = 0x3000};
	reg[R_PC] = PC_START;

	int running = 1;

	while (running)
	{
		uint16_t instr = mem_read(reg[R_PC]++);
		uint16_t op = instr >> 12;

		switch (op)
		{
			case OP_ADD:
				//TODO: add
				break;
			case OP_AND:
				//TODO: and
				break;
			case OP_NOT:
				//TODO: not
				break;
			case OP_BR:
				//TODO: br
				break;
			case OP_JMP:
				//TODO: jmp
				break;
			case OP_JSR:
				//TODO: jsr
				break;
			case OP_LD:
				//TODO: ld
				break;
			case OP_LDI:
				//TODO: ldi
				break;
			case OP_LDR:
				//TODO: ldr
				break;
			case OP_LEA:
				//TODO: lea
				break;
			case OP_ST:
				//TODO: st
				break;
			case OP_STI:
				//TODO: sti
				break;
			case OP_STR:
				//TODO: str
				break;
			case OP_TRAP:
				//TODO: trap
				break;
			case OP_RES:
			case OP_RTI:
			default:
				//TODO: bad opcode
				break;
		}
	}

	return (0);
}
