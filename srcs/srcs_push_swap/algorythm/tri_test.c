/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tri_test.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 11:50:51 by lvirgini          #+#    #+#             */
/*   Updated: 2021/04/23 11:41:27 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** if	 1 < 2 < last 	: in order : PA
** if last < 1 < 2 		: RRA
** if 2 < 1 < last		: SA
** if last < 2 < 1		: RA
*/

int		test_tri_for_a(int first, int second, int last)
{
	if (first < second)
	{
		if (first < last)
			return (PA);
		else
			return (RRA);
	}
	else if (first > last)
		return (RA);
	else
		return (SA);
}

int		test_tri_for_b(int first, int second, int last)
{
	if (first > second)
	{
		if (first > last)
			return (PB);
		else
			return (RRB);
	}
	else if (first < last)
		return (RB);
	else
		return (SB);
}

void		test_tri(t_stack *a, t_stack *b)
{
	int	ia;
	int ib;

	while (final_checker_order(a, b) == false)
	{
		while(check_order(a->first) == false)
		{
			ia = test_tri_for_a(a->first->data, a->first->next->data, a->last->data);
			ib = -1;
			if (b->size > 1)
				ib = test_tri_for_b(b->first->data, b->first->next->data, b->last->data);
			if (ia == PA)
			{
				if (ib != PB && ib != -1)
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
		ib = b->size > 1 ? test_tri_for_b(b->first->data, b->first->next->data, b->last->data) : PB;
		print_and_do(a, b, ib);
	}
	while (b->size > 0)
		print_and_do(a, b, PB);
}



/*
void		test_triold(t_tab *tab, int *data, int *a, int *b)
{
	while (final_checker_order(data, 0, tab->size) == false)
	{
		while(final_checker_order(&data[*a], 0, tab->size - *a) == false)
		{
			if (data[*a] < data[*a + 1])
			{
				if (data[*a] < data[tab->size - 1])	// a0 < (a1  aend)
					print_and_do(tab, PA);
				else								// aend < a0 < a1
					print_and_do(tab, *b > 0 && data[*b] > data[0] ? RRR : RRA);
			}
			else if (data[*a] > data[tab->size - 1])	// (a1 a end) < a0
				print_and_do(tab,*b > 0 && data[*b] < data[0] ? RR : RA);
			else								// a1 < a0 < aend
				print_and_do(tab, *b > 0 && data[*b] < data[*b - 1] ? SS : SA);
		}
		if (*b >= 0)
		{
			if (data[*b] < data[*b - 1])		// b0 < b1
			{
				if (data[*b] < data[0])		// b0 < (b1 bend)									
					print_and_do(tab, data[*b - 1] > data[0] ? RB : SB);	// b0 < b1 < bend
				else
					print_and_do(tab, SB);						// bend < b0 < b1
			}
			else if (data[*b] < data[0])
				print_and_do(tab, RRB);
			print_and_do(tab, PB);
		}
	}
	while (tab->b > 0)
		print_and_do(tab, PB);
}*/