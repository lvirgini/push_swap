/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 16:32:30 by lvirgini          #+#    #+#             */
/*   Updated: 2021/04/20 17:08:59 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

/*
** find min data in a
** rotate for min data in first list
** push in b in order
*/

void	insertion_sort(t_stack *a, t_stack *b)
{
	print_two_stacks(a, b);
	three_datas(a);
	print_two_stacks(a, b);
	print_and_do(a, b, PA);
	print_two_stacks(a, b);
	while (a->size > 2 && check_order(a->first) == false)
	{
		three_datas(a); 
		print_two_stacks(a, b);
		push_first_a_in_order_on_b(a, b);
		//push_min_in_order_b(a, b);
		print_two_stacks(a, b);
	}
	//two_datas(a);
	rotate_b_with_minimal_instruction(b, find_max_data_lst(b->first));
	print_and_do_multi(a, b, PB, b->size);
	print_two_stacks(a, b);
}


void	make_test(t_stack *a, t_stack *b)
{
	// check rotate min data : the min must be in first index
/*	print_two_stacks(a, b);
	rotate_min_data_in_first(a, b);
	print_two_stacks(a, b);
	exit(0);*/

	// check closest min data
	/*print_two_stacks(a, b);
	int index = find_closest_min_data_lst(a->first, 5);
	printf("index = %d\n", index);
	rotate_min_instruction_for_a(a, index);
	print_two_stacks(a, b);*/

	// push a in order b
	/*print_two_stacks(a, b);
	push_min_a_in_order_b(a, b);
	print_two_stacks(a, b);*/
	
	insertion_sort(a, b);
	if (final_checker_order(a, b) == true)
		ft_putstr("OK\n");
	else
		ft_putstr("KO\n");
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

	make_test(a, b);



	if (get_instructions(a, b) == true)
		ft_putstr("OK\n");
	else
		ft_putstr("KO\n");
	free_stack(a);
	free_stack(b);
	return (0);
}
