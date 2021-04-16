/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_error.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 14:41:54 by lvirgini          #+#    #+#             */
/*   Updated: 2021/04/04 18:34:37 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_ERROR_H
# define PUSH_SWAP_ERROR_H

# define MAX_ERROR 5

enum	e_error
{
	ERR_MALLOC,
	ERR_ENTRY_NORM,
	ERR_ENTRY_EMPTY,
	ERR_INSTRUCTION,
	ERR_DUPLICATE,
};

int			error_push_swap(size_t error_nb);
void		exit_error_push_swap(size_t error_nb);

#endif
