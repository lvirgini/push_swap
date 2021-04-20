/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 16:32:30 by lvirgini          #+#    #+#             */
/*   Updated: 2021/04/20 13:42:12 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

/*
** get the minimum instruction to rotate the min data of stack A;
*/
/*
void	rotate_min_data_in_first(t_stack *a)
{
	int		min_index;

	min_index = find_min_data_lst(a->first);
//	printf("min index = %d		a->size / 2 = %d\n", min_index, a->size/2);
	if (min_index == 0)
		return ;
	else if (min_index > a->size / 2)
		print_and_do_multi(a, NULL, RRA, a->size - min_index);
	else
		print_and_do_multi(a, NULL, RA, min_index);
}

void	rotate_b_for_insert_data(t_stack *b, int data)
{
	t_lst	*l;

	l = b->first;
	while ()
}


void	push_min_in_b(t_stack *a, t_stack *b)
{
	rotate_min_data_in_first(a, b);
	if (b->first)
	{
		find_
	}	

}
void	insertion_sort(t_stack *a, t_stack *b)
{
	push_min_in_b(a, b);
	print_two_stacks(a, b);
	while (a->size > 2 && check_order(a->first))
	{
		//three_datas(a);
		//insert(a, b);
		print_two_stacks(a, b);
	}
}
*/
void	make_test(t_stack *a, t_stack *b)
{
/*	print_two_stacks(a, b);
	rotate_min_data_in_first(a, b);
	print_two_stacks(a, b);
	exit(0);*/

//	insertion_sort(a, b);
	exit(0);
}

int		main(int argc, char *argv[])
{
	t_stack		*a;
	t_stack		*b;

	check_arg(argc);
	a = generate_stack_a_content(argv, argc);
	if (!a)
		return (-1);
	b = malloc_stack(NULL, NULL, 0);

	//make_test(a, b);



	if (get_instructions(a, b) == true)
		ft_putstr("OK\n");
	else
		ft_putstr("KO\n");
	free_stack(a);
	free_stack(b);
	return (0);
}
