/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_find.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 12:40:15 by lvirgini          #+#    #+#             */
/*   Updated: 2021/04/20 12:41:05 by lvirgini         ###   ########.fr       */
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