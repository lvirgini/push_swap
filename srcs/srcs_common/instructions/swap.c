/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 18:22:03 by lvirgini          #+#    #+#             */
/*   Updated: 2021/04/30 22:45:44 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_common.h"

/*
** swap two values of two int *
*/

void		swap_int(int *a, int *b)
{
	int		tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/*
**	instruction sa : swap a
**  swap the first 2 elements at the top of stack a.
**	Do nothing if there is only one or no elements).
*/

void		do_sa(t_stack *a, t_stack *b)
{
	(void)b;
	if (a->size > 1)
		swap_int(&a->first->data, &a->first->next->data);
}

/*
** instruction sb : swap b
** 	swap the first 2 elements at the top of stack b.
**	Do nothing if there is only one or no elements).
*/

void		do_sb(t_stack *a, t_stack *b)
{
	(void)a;
	if (b->size > 1)
		swap_int(&b->first->data, &b->first->next->data);
}

/*
** instruction ss = sa + sb
*/

void		do_ss(t_stack *a, t_stack *b)
{
	do_sa(a, b);
	do_sb(a, b);
}
