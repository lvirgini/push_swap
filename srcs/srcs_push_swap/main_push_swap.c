/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_push_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 16:31:36 by lvirgini          #+#    #+#             */
/*   Updated: 2021/04/17 13:44:33 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int				main(int argc, char *argv[])
{
	t_stack		*a;
	t_stack		*b;

	check_arg(argc);
	a = generate_stack_a_content(argv, argc);
	if (!a)
		return (-1);
	b = malloc_stack(NULL, NULL, 0);
	//print_all_lst(a->first);
	select_algo(a, b, a->size);
	free_stack(a);
	free_stack(b);
	return (0);
}
