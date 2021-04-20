/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatch_algo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 15:39:31 by lvirgini          #+#    #+#             */
/*   Updated: 2021/04/20 16:40:13 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** select the best algorithm according to the size of tab
*/

void	select_algo(t_stack *a, t_stack *b, int size)
{
	if (size == 1)
		return ;
	else if (size == 2)
		two_datas(a);
	else if (size == 3)
		three_datas(a);
	//else
	//	insertion_sort(tab, tab->data, &tab->a, &tab->b);
/*	else
		test_tri(a, b);*/
	else
		selection_sort(a, b);
}