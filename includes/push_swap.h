/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 16:16:12 by lvirgini          #+#    #+#             */
/*   Updated: 2021/04/29 14:13:13 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include "push_swap_common.h"

typedef struct s_opti	t_opti;

enum	e_opti_list
{
	FIRST = 0,
	SECOND,
	LAST,
};

struct		s_opti
{
	int b_type_rotate;
	int a_type_rotate;
	int a_index;
	int b_index;
	int b_rotate;
	int	a_rotate;
	int common_rotate;
	int total;
};

/*
** Instruction
*/
void		print_and_do_multi(t_stack *a, t_stack *b, int instruction,
				int mult);
void		print_and_do(t_stack *a, t_stack *b, int instruction);

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

int			get_type_of_rotation(int index, int half_size);
int			get_min_instruction_for_rotate(int type, int index, int size);
int			get_index_for_push(int data, t_lst	*l);
t_opti		generate_t_opti(int data, int a_index, int a_size,
									t_stack *b);
t_opti		check_other_opti(t_opti op, t_stack *a, t_stack *b);
void		optimize_insertion_sort(t_stack *a, t_stack *b);

/*
** int			*get_integer_values_with_split(char *s);
*/

#endif
