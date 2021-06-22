/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 01:21:57 by lvirgini          #+#    #+#             */
/*   Updated: 2021/06/21 21:30:05 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_common.h"

/*
** last->prev become new last
** last become new first,
** first become new second
*/

static void	inverse_rotate_lst(t_lst **first, t_lst **last)
{
	(*last)->next = *first;
	*last = (*last)->prev;
	(*first)->prev = (*last)->next;
	*first = (*first)->prev;
	(*first)->prev = NULL;
	(*last)->next = NULL;
}

/*
** 	rra : reverse rotate a
**	shift down all elements of stack a by 1.
** 	The last element becomes the first one.
*/

void	do_rra(t_stack *a, t_stack *b)
{
	(void)b;
	if (a->size > 1)
		inverse_rotate_lst(&a->first, &a->last);
}

/*
** 	rrb : reverse rotate b
**	shift down all elements of stack b by 1.
**	The last element becomes the first one.
*/

void	do_rrb(t_stack *a, t_stack *b)
{
	(void)a;
	if (b->size > 1)
		inverse_rotate_lst(&b->first, &b->last);
}

/*
** rrr = rra && rrb
*/

void	do_rrr(t_stack *a, t_stack *b)
{
	do_rra(a, b);
	do_rrb(a, b);
}
