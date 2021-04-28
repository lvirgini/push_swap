/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_lst.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 14:58:02 by lvirgini          #+#    #+#             */
/*   Updated: 2021/04/28 18:47:39 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_LST_H
# define PUSH_SWAP_LST_H

typedef struct s_lst	t_lst;

struct		s_lst
{
	int		data;
	t_lst	*next;
	t_lst	*prev;
};

/*
** malloc new lst
*/

t_lst		*add_first_lst(int data, t_lst *next);
t_lst		*add_last_lst(int data, t_lst *last);

/*
** free and remove
*/

void		free_all_lst(t_lst	*l);

/*
** utils for lst
*/

t_lst		*get_last_lst(t_lst	*l);
t_lst		*get_first_lst(t_lst *l);
int			find_max_data_lst(t_lst *l);
int			find_min_data_lst(t_lst *l);
int			find_closest_min_data_lst(t_lst *l, int data);

#endif
