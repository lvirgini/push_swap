/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tri_test.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 11:50:51 by lvirgini          #+#    #+#             */
/*   Updated: 2021/05/03 11:46:26 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** while A is not sorted :
** if	 1 < 2 < last 	: in order : PB
** if last < 1 < 2 		: RRA
** if    2 < 1 < last	: SA
** if last < 2 < 1		: RA
** then PB all.
*/

static int	test_tri_for_a(int first, int second, int last)
{
	if (first < second)
	{
		if (first < last)
			return (PB);
		else
			return (RRA);
	}
	else if (first > last)
		return (RA);
	else
		return (SA);
}

static int	test_tri_for_b(int first, int second, int last)
{
	if (first > second)
	{
		if (first > last)
			return (PA);
		else
			return (RRB);
	}
	else if (first < last)
		return (RB);
	else
		return (SB);
}

static void	print_and_do_test_tri(t_stack *a, t_stack *b, int ia, int ib)
{
	if (ia == PB)
	{
		if (ib != PA && ib != -1)
			print_and_do(a, b, ib);
		print_and_do(a, b, ia);
	}
	else if (ia == SA)
		print_and_do(a, b, test_ss_for_b(b->first) ? SS : ia);
	else if (ia == RA)
		print_and_do(a, b, test_rr_for_b(b->first, b->last) ? RR : ia);
	else if (ia == RRA)
		print_and_do(a, b, test_rrr_for_b(b->first, b->last) ? RRR : ia);
	else
		print_and_do(a, b, ia);
}

void		test_tri(t_stack *a, t_stack *b)
{
	int	ia;
	int ib;

	while (final_checker_order(a, b) == false)
	{
		while (check_order(a->first) == false)
		{
			ia = test_tri_for_a(a->first->data, a->first->next->data,
			a->last->data);
			ib = -1;
			if (b->size > 1)
				ib = test_tri_for_b(b->first->data, b->first->next->data,
				b->last->data);
			print_and_do_test_tri(a, b, ia, ib);
		}
		if (b->size > 0)
		{
			ib = b->size == 1 ? PA : test_tri_for_b(b->first->data,
			b->first->next->data, b->last->data);
			print_and_do(a, b, ib);
		}
	}
	while (b->size > 0)
		print_and_do(a, b, PA);
}
