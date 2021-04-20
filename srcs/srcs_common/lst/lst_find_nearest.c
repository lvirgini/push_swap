/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_find_nearest.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 12:41:15 by lvirgini          #+#    #+#             */
/*   Updated: 2021/04/20 13:35:32 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int		find_nearest_data_lst(t_lst *l, int data)
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
	int		curr;
	
	i = 0;
	index_closest = 0;
	closest = data;
	l = l->next;
	while(l)
	{
		curr = data - l->data;
		if (curr_gap > 0 && curr < closest)
		{
			closest = curr_gap;
			index_smallest_gap = i;
		}
		i++;
		l = l->next;
	}
	return (index_smallest_gap);
}