/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_find_min_max.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 12:40:15 by lvirgini          #+#    #+#             */
/*   Updated: 2021/04/28 19:09:08 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** return index of min data
*/

int		find_min_data_lst(t_lst *l)
{
	int		min;
	int		i;
	int		index;

	if (!l)
		return (0);
	i = 0;
	index = 0;
	min = l->data;
	while (l->next)
	{
		i++;
		if (min > l->next->data)
		{
			index = i;
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
	int		i;
	int		index;

	if (!l)
		return (-1);
	i = 0;
	index = 0;
	max = l->data;
	while (l->next)
	{
		i++;
		if (max < l->next->data)
		{
			index = i;
			max = l->next->data;
		}
		l = l->next;
	}
	return (index);
}
