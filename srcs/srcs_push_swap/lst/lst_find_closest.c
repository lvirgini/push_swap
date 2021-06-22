/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_find_closest.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 12:41:15 by lvirgini          #+#    #+#             */
/*   Updated: 2021/06/22 17:43:29 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** find in (l) index of closest min data of (data)
*/
static int	get_good_index(long closest, int i)
{
	if (closest < 0)
		return (-1);
	return (i);
}

int	find_closest_min_data_lst(t_lst *l, int data)
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
			index_closest = get_good_index(closest, i);
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
