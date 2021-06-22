/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_order.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 14:00:41 by lvirgini          #+#    #+#             */
/*   Updated: 2021/06/21 21:29:37 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_common.h"

/*
** check if the list is sorted in ascending order
*/

int	check_order(t_lst *l)
{
	while (l && l->next)
	{
		if (l->data > l->next->data)
			return (false);
		l = l->next;
	}
	return (true);
}

/*
** check if stack b is empty and a in order
*/

int	final_checker_order(t_stack *a, t_stack *b)
{
	if (b->size != 0)
		return (false);
	return (check_order(a->first));
}
