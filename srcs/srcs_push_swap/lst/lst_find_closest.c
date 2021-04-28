/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_find_closest.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 12:41:15 by lvirgini          #+#    #+#             */
/*   Updated: 2021/04/28 17:28:46 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** find in (l) index of closest min data of (data)
*/

int		find_closest_min_data_lst(t_lst *l, int data)
{
	int		i;
	int		index_closest;
	long	closest;
	long	current;

	i = 0;
	closest = -1;
	while (l)
	{
		current = (long)data - (long)l->data;
		if (closest < 0)
		{
			closest = current;
			index_closest = closest < 0 ? -1 : i;
		}
		else if (current > 0 && current < closest)
		{
			closest = current;
			index_closest = i;
		}
		i++;
		l = l->next;
	}
	return (index_closest);
}
