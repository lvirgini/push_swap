/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatch_algo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 15:39:31 by lvirgini          #+#    #+#             */
/*   Updated: 2021/07/10 14:29:24 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** select the best algorithm according to the size of tab
*/

void	select_algo(t_stack *a, t_stack *b, int size)
{
	if (size == 1 || check_order(a->first) == true)
		return ;
	else if (size == 2)
		two_datas(a);
	else if (size == 3)
		three_datas(a);
	else if (size < 7)
		test_tri(a, b);
	else
		insertion_sort(a, b);
}
