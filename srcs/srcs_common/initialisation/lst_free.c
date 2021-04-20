/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 11:29:01 by lvirgini          #+#    #+#             */
/*   Updated: 2021/04/16 15:08:56 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** free (last)
** return last->prev
*/

t_lst			*remove_last_lst(t_lst *last)
{
	t_lst	*prev;

	if (!last)
		return (NULL);
	prev = last->prev;
	if (prev)
		prev->next = NULL;
	free(last);
	return (prev);
}

/*
** free(first)
** return (first->next);
*/

t_lst			*remove_first_lst(t_lst *first)
{
	t_lst	*next;

	if (!first)
		return (NULL);
	next = first->next;
	if (next)
		next->prev = NULL;
	free(first);
	return (next);
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
