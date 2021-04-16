/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 16:16:12 by lvirgini          #+#    #+#             */
/*   Updated: 2021/04/16 16:07:14 by lvirgini         ###   ########.fr       */
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

//typedef void	(*t_func)(t_tab *);

// a SUPPRIMER

void		print_lst(t_lst *l);
void		print_all_lst(t_lst *l);

/*
** get data
*/

int			is_doublons(t_lst *lst);
void		check_arg(int argc);




///// TO TRANSLATE INT* TO LST
/*

int			*get_integer_values_with_split(char *s);


** basics operations authorized for push_swap


void		swap_int(int *a, int *b);
void		rotate_data(int *data, int begin, int max);
void		inverse_rotate_data(int *data, int begin, int max);


** make instructions


void		get_function_instructions(t_func *f);
int			get_instructions(t_tab *tab);
void		do_sa(t_tab *tab);
void		do_sb(t_tab *tab);
void		do_ss(t_tab *tab);
void		do_pa(t_tab *tab);
void		do_pb(t_tab *tab);
void		do_ra(t_tab *tab);
void		do_rb(t_tab *tab);
void		do_rr(t_tab *tab);
void		do_rra(t_tab *tab);
void		do_rrb(t_tab *tab);
void		do_rrr(t_tab *tab);


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
