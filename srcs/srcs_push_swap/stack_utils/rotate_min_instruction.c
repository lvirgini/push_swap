/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_min_instruction.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 15:55:53 by lvirgini          #+#    #+#             */
/*   Updated: 2021/04/28 15:20:59 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** return rotate or inverse rotate
*/

int				get_type_of_rotation(int index, int half_size)
{
	if (index > half_size)
		return (INVERSE_ROTATE);
	return (ROTATE);
}

/*
** return number of necessary rotation 
*/

int			get_min_instruction_for_rotate(int type, int index, int size)
{
	if (type == INVERSE_ROTATE || type == RRA || type == RRB)
		return (size - index);
	else
		return (index);
}

/*
** for stack a
** get the minimal instructions for rotate index (RA or RRA)
*/

void	rotate_a_with_minimal_instruction(t_stack *a, int index)
{
	if (index == 0)
		return ;
	else if (index > a->size / 2)
		print_and_do_multi(a, NULL, RRA, a->size - index);
	else
		print_and_do_multi(a, NULL, RA, index);
}

/*
** for stack b
** get the minimal instructions for rotate index (RB or RRB)
*/

void	rotate_b_with_minimal_instruction(t_stack *b, int index)
{
	if (index == 0)
		return ;
	else if (index > b->size / 2)
		print_and_do_multi(NULL, b, RRB, b->size - index);
	else
		print_and_do_multi(NULL, b, RB, index);
}

/*

static void	rotate_st_with_minimal_instruction(t_stack *st, int index, int rr, int r)
{
	if (index == 0)
		return ;
	else if (index > st->size / 2)
		print_and_do_multi(NULL, st, rr, st->size - index);
	else
		print_and_do_multi(NULL, st, r, index);
}


void	rotate_b_with_minimal_instruction(t_stack *b, int index)
{
	rotate_st_with_minimal_instruction(b, index, RRB, RB);
}


void	rotate_a_with_minimal_instruction(t_stack *a, int index)
{
	rotate_st_with_minimal_instruction(a, index, RRA, RA);
}*/