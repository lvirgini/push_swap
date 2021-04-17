/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 16:16:12 by lvirgini          #+#    #+#             */
/*   Updated: 2021/04/17 13:00:34 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include "push_swap_define.h"
# include "push_swap_lst.h"
# include "push_swap_stack.h"
# include "push_swap_error.h"
# include "stdio.h" //

typedef void	(*t_func)(t_stack *, t_stack *);

// a SUPPRIMER

void		print_lst(t_lst *l);
void		print_all_lst(t_lst *l);
void		print_two_stacks(t_stack *a, t_stack *b);

/*
** get data
*/

int			is_doublons(t_lst *lst);
void		check_arg(int argc);

/*
** Instruction
*/

int			get_instructions(t_stack *a, t_stack *b);
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


///// TO TRANSLATE INT* TO LST
/*

int			*get_integer_values_with_split(char *s);


**	ALGO


void		get_function_instructions(t_func *f);
void		print_one_instruction(int instruction);
void		print_multi_list(int *list_instructions, int nb_instructions);
void		print_and_do(t_tab *tab, int instruction);
void		select_algo(t_tab *tab, int size);
void		two_datas(t_tab *tab);
void		three_datas(t_tab *tab, int *datas);
void		test_tri(t_tab *tab, int *data, int *a, int *b);
void		insertion_sort( t_tab *tab, int *data, int *a, int *b);
void	 	selection_sort(t_tab *tab, int *data, int *a, int *b);


** final checker


int			final_checker_order(int	*a, int size_b, int size_a);
*/
#endif
