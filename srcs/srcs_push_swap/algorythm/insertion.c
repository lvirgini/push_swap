/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 13:33:40 by lvirgini          #+#    #+#             */
/*   Updated: 2021/04/20 11:27:23 by lvirgini         ###   ########.fr       */
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

void	push_min_in_b(t_stack *a, t_stack *b)
{
	int		min_index;

	min_index = find_min_data_lst(a->first);
	if (min_index > a->size / 2)
		print_and_do_multi(a, b, RRA, a->size - min_index);
	else
		print_and_do_multi(a, b, RA, min_index);
}

void	insertion_sort(t_stack *a, t_stack *b)
{
	push_min_in_b(a, b);
	while (a->size > 2 && check_order(a->first))
	{
		three_datas(a);
		insert_in_b(a, b);
	}
}
/*
void	optimize_min_max(t_tab *tab, int *data, int size)
{
	int		min;
	int		max;

	min = index_min(data, size);
	max = index_max(data, size);

	if (size - min) < (size - max))

}*/

void	push_min_in_b(t_tab *tab, int *data, int size)
{
	int 	min;

	min = index_min(data, size);
	if (min < size / 2)
	{
		while (min-- >= 0)
			print_and_do(tab, RA);
	}
	else
	{
		while ( min++ < size)
			print_and_do(tab, RRA);
	}
	print_and_do(tab, PA);
}

/*
** data[a] to push in b

si b n'a qu'un element
push a
si b0 < b1 sb
 tant que b > data[a]
	i++; 

si i < b / 2
	rotate ra
else 
	rotate rra
*/

void	push_sort_in_b(t_tab *tab, int *data, int *a, int *b)
{
	int		i;
	int		to_do;

	if (*b == 0)
	{
		print_and_do(tab, PA);
		//if (data[0] < data[1])
		//	print_and_do(tab, data[*a] > data[tab->size] ? RRR : RR);
	}
	else
	{
		i = 0;
		while (data[*b - i] > data[*a])
			i++;
		if (i < tab->size + 1 / 2)
		{
			while (i-- > 0)
				print_and_do(tab, RB);
			}
		else
		{
			while ( i++ < tab->size)
				print_and_do(tab, RRB);
		}
		
		print_and_do(tab, PA);
	}
}

void 	selection_sort(t_tab *tab, int *data, int *a, int *b)
{

	while(final_checker_order(data, 0, tab->size) == false)
	{
		while (final_checker_order(&data[*a], 0, tab->size - *a) == false)
		{
			push_min_in_b(tab, &data[*a], tab->size - *a);
		}
		while (*b > -1)
			print_and_do(tab, PB);

	}






	
}

void	insertion_sort( t_tab *tab, int *data, int *a, int *b)
{

//	optimize_min_max(tab, int *data);
	if (final_checker_order(data, 0, tab->size))
		return ;
	push_min_in_b(tab, data, tab->size);
	while(final_checker_order(&data[*a], 0, tab->size - *a) == false)
	{
		push_sort_in_b(tab, data, a, b);
	}
	while (*b > -1)
	{
		print_and_do(tab, PB);
	//	if (final_checker_order(&data[*a], 0, tab->size - *a) == false)
	}
		
}

/*

	while(final_checker_order(&data[*a], a, tab->size - *a) == false)
	{
		while (data[*a] > data[tab->size - 1])
			print_and_do(tab, RA);
		if (data[*a] > data[*a + 1])
			print_and_do(tab, SA);
		if (*b >= 0 && data[*a] < data[*b])
		{
			put_sort_in_b(tab)
			print_and_do(tab, PB);
			print_and_do(tab, SA);
		}
		else
			print_and_do(tab, PA);
	}
	while (*b > 0)
		print_and_do(tab, PB);
}
*/