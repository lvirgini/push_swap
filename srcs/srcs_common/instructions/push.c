/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 19:15:50 by lvirgini          #+#    #+#             */
/*   Updated: 2021/05/03 11:43:28 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_common.h"

/*
** to_push become to_push->next
** to_pop become to_push
*/

static void	push(t_stack *to_push, t_stack *st)
{
	t_lst	*tmp;

	tmp = to_push->first;
	to_push->first = to_push->first->next;
	if (to_push->first)
		to_push->first->prev = NULL;
	tmp->next = st->first;
	if (st->first)
		st->first->prev = tmp;
	st->first = tmp;
}

/*
**	pa : push a
**	take the first element at the top of b and put it at the top of a.
**	Do nothing if b is empty.
**
** here shift pointers to the right.
*/

void		do_pb(t_stack *a, t_stack *b)
{
	if (a->size > 0)
	{
		push(a, b);
		a->size -= 1;
		b->size += 1;
		if (a->size == 0)
			a->last = NULL;
		if (b->size == 1)
			b->last = b->first;
	}
}

/*
** 	pb : push b
**	take the first element at the top of a and put it at the top of b
**	Do nothing if a is empty.
**
** here shift pointers to the left
*/

void		do_pa(t_stack *a, t_stack *b)
{
	if (b->size > 0)
	{
		push(b, a);
		a->size += 1;
		b->size -= 1;
		if (b->size == 0)
			b->last = NULL;
		if (a->size == 1)
			a->last = a->first;
	}
}
