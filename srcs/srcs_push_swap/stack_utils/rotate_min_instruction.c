/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_min_instruction.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 15:55:53 by lvirgini          #+#    #+#             */
/*   Updated: 2021/04/20 16:00:06 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
