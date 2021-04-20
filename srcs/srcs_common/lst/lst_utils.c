/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 12:19:38 by lvirgini          #+#    #+#             */
/*   Updated: 2021/04/20 12:39:40 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** return index of min data
*/

int		find_min_data_lst(t_lst *l)
{
	int		min;
	int		index;

	if (!l)
		return (0);
	index = 0;
	min = l->data;
	while (l->next)
	{
		if (min > l->next->data)
		{
			index++;
			min = l->next->data;
		}
		l = l->next;
	}
	return (index);
}

/*
** return index of max data
*/

int		find_max_data_lst(t_lst *l)
{
	int		max;
	int		index;

	if (!l)
		return (-1);
	index = 1;
	max = l->data;
	while (l->next)
	{
		if (max < l->next->data)
		{
			index++;
			max = l->next->data;
		}
		l = l->next;
	}
	return (index);
}

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
	return(index_smallest_gap);
}

t_lst	*get_first_lst(t_lst *l)
{
	t_lst	*first;

	if (!l)
		return (NULL);
	first = l;
	while (first->prev)
		first = first->prev;
	return (first);
}

t_lst	*get_last_lst(t_lst *l)
{
	t_lst	*last;

	if (!l)
		return (NULL);
	last = l;
	while (last->next)
		last = last->next;
	return (last);
}
