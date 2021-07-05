/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 16:32:30 by lvirgini          #+#    #+#             */
/*   Updated: 2021/06/22 13:51:35 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

/*
** CHECKER
**
** Checker get as an argument the stack A formatted as a list of integers.
**
**	The first argument is at the top of the stack.
**	If no argument is given checker stops and displays nothing.
**	Checker will then wait and read instructions on the standard input.
**  Each instruction will be followed by ’\n’.
**	Once all the instructions have been read, checker will execute them on A.
**	If after executing those instructions, stack A is actually sorted
** 		and b is empty, then checker must display "OK" followed by a ’\n’*
**		on the standard output. In every
** 	Other case, checker must display "KO" followed by a ’\n’
**		on the standard output.
**	In case of error, Checker display Error followed by a ’\n’
**		on the standard error.
**	Errors include for example: some arguments are not integers,
**		some arguments are bigger than an integer, there are duplicates,
**		an instruction don’t exist and/or is incorrectly formatted.
**
** for checking visual sorts : do
**	t_lst *l = a->first;
**	while (l) {
**		ft_putnbr(l->data);
**		ft_putchar(' ');
**		l = l->next;
**	}
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
	if (get_instructions(a, b) == true)
		ft_putstr("OK\n");
	else
		ft_putstr("KO\n");
	free_stack(a);
	free_stack(b);
	return (0);
}
