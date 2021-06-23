/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_in_order.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 16:28:25 by lvirgini          #+#    #+#             */
/*   Updated: 2021/06/23 10:02:28 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_index_for_push(int data, t_lst *l)
{
	int		index;

	index = find_closest_min_data_lst(l, data);
	if (index == -1)
		index = find_min_data_lst(l) + 1;
	return (index);
}

/*
** get in stack b the closest min from a->first
** rotate b and push a
*/

void	push_first_a_in_order_on_b(t_stack *a, t_stack *b)
{
	int		insert;

	if (b->size >= 1)
	{
		insert = get_index_for_push(a->first->data, b->first);
		rotate_b_with_minimal_instruction(b, insert);
	}
	if (check_order(a->first) == false)
		print_and_do(a, b, PB);
}

void	push_first_b_in_order_on_a(t_stack *a, t_stack *b)
{
	int		insert;

	if (a->size >= 1)
	{
		insert = get_index_for_push(b->first->data, a->first);
		rotate_a_with_minimal_instruction(a, insert);
	}
	print_and_do(a, b, PA);
}

/*
** get in stack b the closest min from a->(min data)
** rotate b and push a
*/

void	push_min_a_in_order_on_b(t_stack *a, t_stack *b)
{
	int		a_min;

	a_min = find_min_data_lst(a->first);
	rotate_a_with_minimal_instruction(a, a_min);
	push_first_a_in_order_on_b(a, b);
}
