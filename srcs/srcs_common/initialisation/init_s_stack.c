/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_s_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 11:34:37 by lvirgini          #+#    #+#             */
/*   Updated: 2021/04/30 22:44:40 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_common.h"

/*
** malloc and free for stack
*/

t_stack		*malloc_stack(t_lst *first, t_lst *last, int size)
{
	t_stack *res;

	res = (t_stack *)malloc(sizeof(t_stack));
	if (res == NULL)
	{
		error_push_swap(ERR_MALLOC);
		return (NULL);
	}
	res->first = first;
	res->last = last;
	res->size = size;
	return (res);
}

void		free_stack(t_stack *st)
{
	if (st)
	{
		if (st->first)
			free_all_lst(st->first);
		free(st);
	}
}
