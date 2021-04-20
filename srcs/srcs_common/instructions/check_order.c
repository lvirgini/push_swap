/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_order.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 14:00:41 by lvirgini          #+#    #+#             */
/*   Updated: 2021/04/17 13:04:51 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			check_order(t_lst *l)
{
	while (l->next)
	{
		if (l->data > l->next->data)
			return (false);
		l = l->next;
	}
	return (true);
}

int			final_checker_order(t_stack *a, t_stack *b)
{
	if (b->size != 0)
		return (false);
	return (check_order(a->first));
}
