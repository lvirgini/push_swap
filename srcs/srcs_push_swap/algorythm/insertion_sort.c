/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 13:33:40 by lvirgini          #+#    #+#             */
/*   Updated: 2021/05/03 11:45:38 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** INSERTION SORT :
**
** while a is not in right order
** 		push the first element in stack (A) into stack (B) in order
** push all B into A in order.
**
** otpimisation :
**		- get best first number with three data algo
**		- get best push A (first, second or last) or after if needed.
**		- when A is sorted, push ending B on order to A.
*/

void			insertion_sort(t_stack *a, t_stack *b)
{
	three_datas(a);
	print_and_do(a, b, PB);
	while (a->size > 3 && check_order(a->first) == false)
		optimize_insertion_sort(a, b);
	three_datas(a);
	rotate_b_with_minimal_instruction(b, find_max_data_lst(b->first));
	while (b->size > 0)
	{
		if (b->first->data > a->last->data)
			print_and_do(a, b, PA);
		else if (find_closest_min_data_lst(a->first, b->first->data) == -1)
		{
			rotate_a_with_minimal_instruction(a, find_min_data_lst(a->first));
			print_and_do(a, b, PA);
		}
		else
			print_and_do(a, b, RRA);
	}
	rotate_a_with_minimal_instruction(a, find_min_data_lst(a->first));
}
