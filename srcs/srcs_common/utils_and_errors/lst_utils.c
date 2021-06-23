/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 12:19:38 by lvirgini          #+#    #+#             */
/*   Updated: 2021/06/23 09:53:13 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_common.h"

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
