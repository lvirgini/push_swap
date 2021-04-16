/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 18:31:41 by lvirgini          #+#    #+#             */
/*   Updated: 2021/04/16 16:23:31 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** check all values in lst to find duplicate
*/

static int		is_duplicate_data(t_lst *lst)
{
	t_lst	*i;
	t_lst	*j;

	i = lst;
	while (i)
	{
		j = i->next;
		while (j)
		{
			if (i->data == j->data)
				return (true);
			j = j->next;
		}
		i = i->next;
	}
	return (false);
}

/*
** get integer values with atoi
** if is good integer(atoi i return true or false) -> return malloc(lst)
*/

static t_lst	*atoi_to_lst(char *src, t_lst *last)
{
	int		data;

	if (ft_atoi_i(src, &data) == false)
	{
		error_push_swap(ERR_ENTRY_NORM);
		return (NULL);
	}
	return (add_last_lst(data, last));
}

/*
** get all values into lst *
*/

static t_lst	*get_all_values_to_lst(char **src, int size)
{
	int		i;
	t_lst	*l;
	t_lst	*first;

	i = 1;
	first = atoi_to_lst(src[i], NULL);
	if (!first)
		return (NULL);
	l = first;
	while (++i < size)
	{
		l->next = atoi_to_lst(src[i], l);
		if (!l->next)
		{
			free_all_lst(first);
			return (NULL);
		}
		l = l->next;
	}
	return (first);
}

/*
**	get integers from each string && store them in lst in stack a
**
** 		char *(srcs) : all character string already split
**					which must be convert into int
**		check if duplicate value
**		return : generate stack a
*/

t_stack			*generate_stack_a_content(char **srcs, int size)
{
	t_stack		*a;
	t_lst		*l;

	l = get_all_values_to_lst(srcs, size);
	if (!l)
		return (NULL);
	if (is_duplicate_data(l) == true)
	{
		free_all_lst(l);
		error_push_swap(ERR_DUPLICATE);
		return (NULL);
	}
	a = malloc_stack(l, get_last_lst(l), size);
	if (!a)
	{
		free_all_lst(l);
		return (NULL);
	}
	return (a);
}
