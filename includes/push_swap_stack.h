/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_stack.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 14:59:36 by lvirgini          #+#    #+#             */
/*   Updated: 2021/04/20 17:26:28 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_STACK_H
# define PUSH_SWAP_STACK_H

# include "push_swap.h"

typedef struct s_stack		t_stack;

struct		s_stack
{
	t_lst	*first;
	t_lst	*last;
	int		size;
};

/*
** malloc and free
*/

t_stack		*malloc_stack(t_lst *first, t_lst *last, int size);
void		free_stack(t_stack *st);

/*
** generate all needed for a stack a (lst and checker norme lst)
*/

t_stack		*generate_stack_a_content(char **srcs, int size);

/*
** Utils for algorythms
*/

void	push_first_b_in_order_on_a(t_stack *a, t_stack *b);
void	push_first_a_in_order_on_b(t_stack *a, t_stack *b);
void	push_min_a_in_order_on_b(t_stack *a, t_stack *b);
void	rotate_a_with_minimal_instruction(t_stack *a, int index);
void	rotate_b_with_minimal_instruction(t_stack *b, int index);

#endif
