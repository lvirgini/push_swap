/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 01:22:04 by lvirgini          #+#    #+#             */
/*   Updated: 2021/04/17 12:49:52 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** last become new last->prev
** first become new last,
** second become new first
*/

#include "push_swap.h"

static void	rotate_lst(t_lst **first, t_lst **last)
{
	(*first)->prev = *last;
	*first = (*first)->next;
	(*last)->next = (*first)->prev;
	*last = (*last)->next;
	(*first)->prev = NULL;
	(*last)->next = NULL;
}

/*
**	ra : rotate a - shift up all elements of stack a by 1.
**	The first element becomes the last one.
*/

void		do_ra(t_stack *a, t_stack *b)
{
	(void)b;
	if (a->size > 1)
		rotate_lst(&a->first, &a->last);
}

/*
**	rb : rotate b - shift up all elements of stack b by 1
**	The first element becomes the last one.
*/

void		do_rb(t_stack *a, t_stack *b)
{
	(void)a;
	if (b->size > 1)
		rotate_lst(&b->first, &b->last);
}

/*
** rr = ra && rb
*/

void		do_rr(t_stack *a, t_stack *b)
{
	do_ra(a, b);
	do_rb(a, b);
}
