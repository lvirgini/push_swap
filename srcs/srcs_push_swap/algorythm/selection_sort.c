/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 16:00:20 by lvirgini          #+#    #+#             */
/*   Updated: 2021/04/20 16:41:40 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** SELECTION SORT :
**
**	find the smallest data on the stack
**	rotate and put it first
**	push it on stack
*/

void	selection_sort(t_stack *a, t_stack *b)
{
	int		index;

	while (a->size > 3 && check_order(a->first) == false)
	{
		three_datas(a);
		index = find_min_data_lst(a->first);
		rotate_a_with_minimal_instruction(a, index);
		print_and_do(a, b, PA);
	}
	three_datas(a);
	print_and_do_multi(a, b, PB, b->size);
}