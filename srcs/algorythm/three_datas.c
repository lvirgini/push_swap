/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_datas.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 13:32:22 by lvirgini          #+#    #+#             */
/*   Updated: 2021/04/17 13:32:01 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	three_data_132(t_stack *a)
{
	print_and_do(a, NULL, RRA);
	print_and_do(a, NULL, SA);
}

static void	three_data_321(t_stack *a)
{
	print_and_do(a, NULL, RA);
	print_and_do(a, NULL, SA);
}

static void	three_data_312(t_stack *a)
{
	print_and_do(a, NULL, RA);
}

static void	three_data_231(t_stack *a)
{
	print_and_do(a, NULL, RRA);
}

void		three_datas(t_stack *a)
{
	int	first;
	int	second;
	int	last;

	first = a->first->data;
	second = a->first->next->data;
	last = a->last->data;
	if (first < second && second < last)
		;
	else if (first > second && second > last)
		three_data_321(a);
	else if (first < second && second > last)
	{
		if (first < last)
			three_data_132(a);
		else
			three_data_231(a);
	}
	else if (first > second && second < last)
	{
		if (first > last)
			three_data_312(a);
		else
			print_and_do(a, NULL, SA);
	}
}
