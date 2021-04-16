/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_stack.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 14:59:36 by lvirgini          #+#    #+#             */
/*   Updated: 2021/04/16 15:04:54 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_STACK_H
# define PUSH_SWAP_STACK_H

# include "push_swap.h"

typedef struct s_stack		t_stack;

struct		s_stack
{
	t_lst	*data;
	t_lst	*last;
	int		size;
};

t_stack		*malloc_stack(t_lst *data, t_lst *last, int size);
void		free_stack(t_stack *st);

#endif
