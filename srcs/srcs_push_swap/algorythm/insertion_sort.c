/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 13:33:40 by lvirgini          #+#    #+#             */
/*   Updated: 2021/04/28 19:12:45 by lvirgini         ###   ########.fr       */
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

static void	optimize_insertion_sort(t_stack *a, t_stack *b)
{
	t_opti op;

	op = optimize_push_to_pop(a, b);
	if (op.total > 3)
		op = check_other_opti(op, a, b);
	if (op.a_index == FIRST)
	{
		push_first_a_in_order_on_b(a, b);
		return ;
	}
	else if (op.a_type_rotate == ROTATE)
	{
		print_and_do_multi(a, b, RR, op.common_rotate);
		if (op.a_rotate > 0)
			print_and_do_multi(a, b, RA, op.a_rotate);
	}
	else
	{
		print_and_do_multi(a, b, RRR, op.common_rotate);
		if (op.a_rotate > 0)
			print_and_do_multi(a, b, RRA, op.a_rotate);
	}
	print_and_do_multi(a, b, op.b_type_rotate == ROTATE ?
			RB : RRB, op.b_rotate);
	print_and_do(a, b, PA);
}

/*
** INSERTION SORT :
*/

void		insertion_sort(t_stack *a, t_stack *b)
{
	three_datas(a);
	print_and_do(a, b, PA);
	while (a->size > 3 && check_order(a->first) == false)
		optimize_insertion_sort(a, b);
	three_datas(a);
	rotate_b_with_minimal_instruction(b, find_max_data_lst(b->first));
	while (b->size > 0)
	{
		if (b->first->data > a->last->data)
			print_and_do(a, b, PB);
		else if (find_closest_min_data_lst(a->first, b->first->data) == -1)
		{
			rotate_a_with_minimal_instruction(a, find_min_data_lst(a->first));
			print_and_do(a, b, PB);
		}
		else
			print_and_do(a, b, RRA);
	}
	rotate_a_with_minimal_instruction(a, find_min_data_lst(a->first));
}
