/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_final_order.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 18:37:47 by lvirgini          #+#    #+#             */
/*   Updated: 2021/04/28 18:38:02 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

/*
** check if stack b is empty and a in order
*/

int			final_checker_order(t_stack *a, t_stack *b)
{
	if (b->size != 0)
		return (false);
	return (check_order(a->first));
}
