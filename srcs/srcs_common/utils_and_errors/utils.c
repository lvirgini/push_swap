/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 15:27:35 by lvirgini          #+#    #+#             */
/*   Updated: 2021/07/05 15:42:09 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_common.h"

int	str_is_digits(char *str)
{
	size_t	i;

	i = 0;
	if (str[i] == '-')
	{
		i++;
		if (!ft_isdigit(str[i]))
			return (false);
	}
	while (str && str[i])
	{
		if (!ft_isdigit(str[i]))
			return (false);
		i++;
	}
	return (true);
}
