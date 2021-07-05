/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_push_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 16:31:36 by lvirgini          #+#    #+#             */
/*   Updated: 2021/06/23 10:00:38 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** PUSH SWAP :
** receive as an argument the stack A formatted as a list of integers.
** The first argument is at the top of the stack.
** The program display the smallest list of instructions possible to sort
** the stack A, the smallest number being at the top.
** sort instructions are separared by a ’\n’.
*/

int	main(int argc, char *argv[])
{
	t_stack		*a;
	t_stack		*b;

	if (argc < 2)
		return (0);
	a = generate_stack_a_content(argv, argc);
	if (!a)
		return (-1);
	b = malloc_stack(NULL, NULL, 0);
	if (!b)
	{
		free_stack(a);
		return (-1);
	}
	select_algo(a, b, a->size);
	free_stack(a);
	free_stack(b);
	return (0);
}
