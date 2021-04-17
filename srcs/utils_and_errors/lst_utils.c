/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 12:19:38 by lvirgini          #+#    #+#             */
/*   Updated: 2021/04/17 13:17:21 by lvirgini         ###   ########.fr       */
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
	index = 1;
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
		return (0);
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
