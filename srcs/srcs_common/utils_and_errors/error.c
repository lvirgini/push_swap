/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 14:50:28 by lvirgini          #+#    #+#             */
/*   Updated: 2021/06/22 19:26:58 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_common.h"

int	error_push_swap(void)
{
	ft_putstr_fd("Error\n", 2);
	return (-1);
}

void	exit_error_push_swap(void)
{
	error_push_swap();
	exit(-1);
}
