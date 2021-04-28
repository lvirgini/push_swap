/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_instruction.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 13:21:41 by lvirgini          #+#    #+#             */
/*   Updated: 2021/04/28 19:21:01 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** print solo instruction
*/

static void	print_one_instruction(int instruction)
{
	static char	*guidelines[] = {PRINT_SA, PRINT_SB, PRINT_SS, PRINT_PA,
	PRINT_PB, PRINT_RA, PRINT_RB, PRINT_RR, PRINT_RRA, PRINT_RRB, PRINT_RRR};

	if (instruction < MAX_INSTRUCTION)
		ft_putstr(guidelines[instruction]);
}

/*
** Print and do instruction
*/

void		print_and_do(t_stack *a, t_stack *b, int instruction)
{
	static t_func f[MAX_INSTRUCTION] = {&do_sa, &do_sb, &do_ss, &do_pa, &do_pb,
				&do_ra, &do_rb, &do_rr, &do_rra, &do_rrb, &do_rrr};

	if (instruction < MAX_INSTRUCTION)
	{
		f[instruction](a, b);
		print_one_instruction(instruction);
	}
}

/*
**	print multi instructions
*/

void		print_and_do_multi(t_stack *a, t_stack *b, int instruction,
			int mult)
{
	while (mult-- > 0)
		print_and_do(a, b, instruction);
}
