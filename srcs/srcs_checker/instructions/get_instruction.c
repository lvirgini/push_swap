/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_instruction.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 23:50:04 by lvirgini          #+#    #+#             */
/*   Updated: 2021/04/17 18:58:16 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		is_instruction(char *line)
{
	static const char	*guidelines[] = {STR_SA, STR_SB, STR_SS, STR_PA,
		STR_PB, STR_RA, STR_RB, STR_RR, STR_RRA, STR_RRB, STR_RRR};
	size_t				i;

	i = 0;
	while (i < 11)
	{
		if (ft_strcmp(line, guidelines[i]) == 0)
		{
			return (i);
		}
		i++;
	}
	return (-1);
}

static void		get_function_instructions(t_func *f)
{
	f[SA] = &do_sa;
	f[SB] = &do_sb;
	f[SS] = &do_ss;
	f[PA] = &do_pa;
	f[PB] = &do_pb;
	f[RA] = &do_ra;
	f[RB] = &do_rb;
	f[RR] = &do_rr;
	f[RRA] = &do_rra;
	f[RRB] = &do_rrb;
	f[RRR] = &do_rrr;
}

/*
** Get instruction from entry standard
** check if the instruction exist
** execute the instruction
** return to checker_order
*/

int				get_instructions(t_stack *a, t_stack *b)
{
	char	*line;
	int		instruction;
	t_func	f[11];

	get_function_instructions(f);
	while (get_next_line(0, &line) > 0)
	{
		instruction = is_instruction(line);
		free(line);
		if (instruction == -1)
		{
			free_stack(a);
			free_stack(b);
			exit_error_push_swap(ERR_INSTRUCTION);
		}
		f[instruction](a, b);
		//print_two_stacks(a, b);
	}
	free(line);
	return (final_checker_order(a, b));
}
