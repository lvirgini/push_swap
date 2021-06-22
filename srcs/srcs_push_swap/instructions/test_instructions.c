/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_instructions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 11:27:01 by lvirgini          #+#    #+#             */
/*   Updated: 2021/06/22 17:08:02 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	test_ss_for_b(t_lst *l)
{
	if (l && l->next)
	{
		if (l->data < l->next->data)
			return (SS);
	}
	return (SA);
}

int	test_rr_for_b(t_lst *l, t_lst *last)
{
	if (l && last)
	{
		if (l->data < last->data)
			return (RR);
	}
	return (RA);
}

int	test_rrr_for_b(t_lst *l, t_lst *last)
{
	if (l && last)
	{
		if (l->data > last->data)
			return (RRR);
	}
	return (RRA);
}
