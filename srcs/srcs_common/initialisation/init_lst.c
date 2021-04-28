/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_lst.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 11:29:01 by lvirgini          #+#    #+#             */
/*   Updated: 2021/04/28 18:35:48 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_common.h"

/*
** Create lst
*/

static t_lst	create_lst(int data, t_lst *next, t_lst *prev)
{
	t_lst	l;

	l.data = data;
	l.next = next;
	l.prev = prev;
	return (l);
}

/*
** malloc and free t_lst : (double lst);
**
**	add = first
*/

t_lst			*add_first_lst(int data, t_lst *next)
{
	t_lst	*add;

	add = (t_lst *)malloc(sizeof(t_lst));
	if (add == NULL)
	{
		error_push_swap(ERR_MALLOC);
		return (NULL);
	}
	*add = create_lst(data, next, NULL);
	return (add);
}

/*
** add = last
*/

t_lst			*add_last_lst(int data, t_lst *last)
{
	t_lst	*add;

	add = (t_lst *)malloc(sizeof(t_lst));
	if (add == NULL)
	{
		error_push_swap(ERR_MALLOC);
		return (NULL);
	}
	*add = create_lst(data, NULL, last);
	if (last)
		last->next = add;
	return (add);
}

/*
** free all l and next l;
*/

void			free_all_lst(t_lst *l)
{
	t_lst *tmp;

	while (l)
	{
		tmp = l->next;
		free(l);
		l = tmp;
	}
}
