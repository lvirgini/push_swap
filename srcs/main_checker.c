/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 16:32:30 by lvirgini          #+#    #+#             */
/*   Updated: 2021/04/17 18:58:10 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		main(int argc, char *argv[])
{
	t_stack		*a;
	t_stack		*b;

	check_arg(argc);
	a = generate_stack_a_content(argv, argc);
	if (!a)
		return (-1);
	b = malloc_stack(NULL, NULL, 0);
	if (get_instructions(a, b) == true)
		ft_putstr("OK\n");
	else
		ft_putstr("KO\n");
	free_stack(a);
	free_stack(b);
	return (0);
}
