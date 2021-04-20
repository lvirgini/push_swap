/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_in_order.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 16:28:25 by lvirgini          #+#    #+#             */
/*   Updated: 2021/04/20 17:09:51 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** get in stack b the closest min from a->first
** rotate b and push a
*/

void	push_first_a_in_order_on_b(t_stack *a, t_stack *b)
{
	int insert;

	if (b->size >= 1)
	{
		insert = find_closest_min_data_lst(b->first, a->first->data);
		if (insert == -1)
		{
			printf("INSERT -1 %%%%%%%%%%%%%%%%%%%%%%%%%%\n");
			insert = find_min_data_lst(b->first) + 1;
		}
		rotate_b_with_minimal_instruction(b, insert);
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
