/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 16:16:12 by lvirgini          #+#    #+#             */
/*   Updated: 2021/04/28 15:01:19 by lvirgini         ###   ########.fr       */
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

typedef struct s_opti	t_opti;

enum	e_opti_list
{
	
	FIRST = 0,
	SECOND,
	LAST,
};

struct s_opti
{
	int a_list;
	int b_type_rotate;
	int a_type_rotate;
	int a_index;
	int b_index;
	int b_rotate;
	int	a_rotate;
	int common_rotate;
	int total;
};


// a SUPPRIMER

void		print_lst(t_lst *l);
void		print_this_lst(t_lst *l, int index);
void		print_all_lst(t_lst *l);
void		print_two_stacks(t_stack *a, t_stack *b);
int			get_verbose_instructions(t_stack *a, t_stack *b);

/*
** get data
*/

int			is_doublons(t_lst *lst);
void		check_arg(int argc);

/*
** Instruction
*/
void		print_and_do_multi(t_stack *a, t_stack *b, int instruction,
				int mult);
void		print_one_instruction(int instruction); // static ?
void		print_and_do(t_stack *a, t_stack *b, int instruction);
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
** test for double instruction
*/

int			test_rrr_for_a(t_lst *l, t_lst *last);
int			test_rrr_for_b(t_lst *l, t_lst *last);
int			test_rr_for_a(t_lst *l, t_lst *last);
int			test_rr_for_b(t_lst *l, t_lst *last);
int			test_ss_for_a(t_lst *l);
int			test_ss_for_b(t_lst *l);

/*
** checker
*/

int			final_checker_order(t_stack *a, t_stack *b);
int			check_order(t_lst *l);

/*
** Algo
*/

void		select_algo(t_stack *a, t_stack *b, int size);
void		two_datas(t_stack *a);
void		three_datas(t_stack *a);
void		test_tri(t_stack *a, t_stack *b);
void		selection_sort(t_stack *a, t_stack *b);
void		insertion_sort(t_stack *a, t_stack *b);

/*
** optimisation and usefull help for algo
*/
void			get_total_rotate_opti(t_opti *op);
int			get_type_of_rotation(int index, int half_size);
int			get_min_instruction_for_rotate(int type, int index, int size);
int			get_index_for_push(int data, t_lst	*l);
t_opti		optimize_push_to_pop(t_stack *st, t_stack *to_pop, int size);
t_opti		check_other_opti(t_opti op, t_stack *a, t_stack *b);

///// TO TRANSLATE INT* TO LST
/*
** int			*get_integer_values_with_split(char *s);
*/

#endif
