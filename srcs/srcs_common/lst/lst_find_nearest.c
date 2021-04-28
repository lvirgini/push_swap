/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_find_nearest.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 12:41:15 by lvirgini          #+#    #+#             */
/*   Updated: 2021/04/26 15:12:01 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		find_nearest_data_lst(t_lst *l, int data) //////
{
	int		i;
	int		index_smallest_gap;
	int		smallest_gap;
	int		curr_gap;
	
	i = 0;
	index_smallest_gap = 0;
	smallest_gap = ft_abs(data - l->data);
	l = l->next;
	while(l)
	{
		curr_gap = ft_abs(data - l->data);
		if (curr_gap < smallest_gap)
		{
			smallest_gap = curr_gap;
			index_smallest_gap = i;
		}
		i++;
		l = l->next;
	}
	return (index_smallest_gap);
}

int		find_closest_min_data_lst(t_lst *l, int data)
{
	int		i;
	int		index_closest;
	int		closest;
	int		current;
	
	i = 0;
	closest = -1;
	while (l && closest < 0)
	{
		closest = data - l->data;
		l = l->next;
		i++;
	}
	index_closest = closest < 0 ? -1 : i - 1;
	while(l)
	{
		current = data - l->data;
		if (current > 0 && current < closest)
		{
			closest = current;
			index_closest = i;
		}
		i++;
		l = l->next;
	}
	return (index_closest);
}
