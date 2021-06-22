/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_opti_insertion_sort.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 21:34:06 by lvirgini          #+#    #+#             */
/*   Updated: 2021/06/22 17:29:32 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Optimize Push A to B for Insertion Sort :
** carreful : st must have more are egal than 3 values.
** generate three easy possibilities for push with the minimal instruction.
**
** ex : index :
** A = 0 1 2 3 ...... 3 2 1
**
** check index 0 : get nb instructions
** while nb_instruction-- check index 1++
** get the index with minimum instruction and push a into b.
*/

static t_opti	ret_optimize_push_to_pop(t_opti first, t_opti second,
				t_opti last)
{
	if (first.total <= second.total)
	{
		if (first.total <= last.total)
			return (first);
		return (last);
	}
	if (second.total < last.total)
		return (second);
	return (last);
}

static t_opti	optimize_push_to_pop(t_stack *st, t_stack *to_pop)
{
	t_opti	first;
	t_opti	second;
	t_opti	last;

	first = generate_t_opti(st->first->data, FIRST, st->size, to_pop);
	first.total = first.b_rotate;
	if (first.b_index == 0)
		return (first);
	second = generate_t_opti(st->first->next->data, SECOND, st->size, to_pop);
	last = generate_t_opti(st->last->data, st->size, st->size, to_pop);
	return (ret_optimize_push_to_pop(first, second, last));
}

static int	get_good_b_rotate(int type_rotate)
{
	if (type_rotate == ROTATE)
		return (RB);
	return (RRB);
}

void	optimize_insertion_sort(t_stack *a, t_stack *b)
{
	t_opti	op;

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
	print_and_do_multi(a, b, get_good_b_rotate(op.b_type_rotate), op.b_rotate);
	print_and_do(a, b, PB);
}
