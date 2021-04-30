/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 14:50:28 by lvirgini          #+#    #+#             */
/*   Updated: 2021/04/30 22:46:00 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_common.h"

void		print_error(size_t nb)
{
	static char *error[MAX_ERROR] = {
		[ERR_MALLOC] = "Allocation problem : Malloc return NULL\n",
		[ERR_ENTRY_NORM] = "Entry number is not well formated\n",
		[ERR_ENTRY_EMPTY] = "Entry argument is empty\n",
		[ERR_INSTRUCTION] = "The instruction is not valid\n",
		[ERR_DUPLICATE] = "Entry have duplicate values\n",
	};

	ft_putstr(error[nb]);
}

int			error_push_swap(size_t error_nb)
{
	ft_putstr("ERROR :");
	if (error_nb < MAX_ERROR)
		print_error(error_nb);
	else
		ft_putstr("/!\\ error not referenced /!\\\n");
	return (-1);
}

void		exit_error_push_swap(size_t error_nb)
{
	error_push_swap(error_nb);
	exit(0);
}
