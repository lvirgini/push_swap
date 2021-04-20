/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 13:33:40 by lvirgini          #+#    #+#             */
/*   Updated: 2021/04/20 16:40:21 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


/*
**
INSERTION SORT : 

while stack is not in sort : 

while i < a size
{
	j = i
	while j > 0 && a[j - 1] > a[j]
	{
		swap (a[j], a[j-1]
		j--;
	}
}
*/


/*
** find min data in a
** rotate for min data in first list
** push in b in order
*//*
void	insertion_sort(t_stack *a, t_stack *b)
{
	int		index;

	while (a->size > 3 && check_order(a->first) == false)
	{
		index = find_min_data_lst(a->first);
		rotate_a_with_minimal_instruction(a, index);
		print_and_do(a, b, PA);
	}
	three_datas(a);
	print_and_do_multi(a, b, PB, b->size);
}
*/