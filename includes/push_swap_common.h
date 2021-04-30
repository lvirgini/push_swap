/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_common.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 18:24:04 by lvirgini          #+#    #+#             */
/*   Updated: 2021/04/30 22:52:02 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_COMMON_H
# define PUSH_SWAP_COMMON_H

# include "libft.h"
# include "push_swap_define.h"
# include "push_swap_error.h"
# include "push_swap_lst.h"
# include "push_swap_stack.h"

typedef void	(*t_func)(t_stack *, t_stack *);

/*
** get data
*/

int			is_doublons(t_lst *lst);
void		check_arg(int argc);

/*
** do instructions
*/

void		do_sa(t_stack *a, t_stack *b);
void		do_sb(t_stack *a, t_stack *b);
void		do_ss(t_stack *a, t_stack *b);
void		do_pa(t_stack *a, t_stack *b);
void		do_pb(t_stack *a, t_stack *b);
void		do_ra(t_stack *a, t_stack *b);
void		do_rb(t_stack *a, t_stack *b);
void		do_rr(t_stack *a, t_stack *b);
void		do_rra(t_stack *a, t_stack *b);
void		do_rrb(t_stack *a, t_stack *b);
void		do_rrr(t_stack *a, t_stack *b);

/*
** checker
*/

int			final_checker_order(t_stack *a, t_stack *b);
int			check_order(t_lst *l);

#endif
