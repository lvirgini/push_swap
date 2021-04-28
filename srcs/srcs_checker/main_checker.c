/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 16:32:30 by lvirgini          #+#    #+#             */
/*   Updated: 2021/04/28 15:32:25 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	printer_get_instruction(t_stack *a, t_stack *b)
{
	if (get_verbose_instructions(a, b) == true)
		ft_putstr("OK\n");
	else
		ft_putstr("KO\n");
	exit(0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 13:33:40 by lvirgini          #+#    #+#             */
/*   Updated: 2021/04/22 12:48:56 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


/*
**
INSERTION SORT : 

while stack is not in sort : 

while i < a size
{
	j = i
	while j > 0 && a[j - 1] > a[j]
	{
		swap (a[j], a[j-1]
		j--;
	}
}
*/

/*
** return rotate or inverse rotate
*/
/*
int				get_type_of_rotation(int index, int half_size)
{
	if (index > half_size)
		return (INVERSE_ROTATE);
	return (ROTATE);
}

int			get_min_instruction_for_rotate(int type, int index, int size)
{
	if (type == INVERSE_ROTATE || type == RRA || type == RRB)
		return (size - index);
	else
		return (index);
}	

t_opti 		get_t_opti_insert_sort(int data, int half_size, int size, t_lst *to_pop)
{
	t_opti		ret;

	ret.index = get_index_for_push(data, to_pop);
	printf("INDEX = %d\n", ret.index);
	ret.rotate = get_type_of_rotation(ret.index, half_size);
	ret.nb_rotate = get_min_instruction_for_rotate(ret.rotate, ret.index, size);
	return (ret);
}


t_opti	ret_optimize_push_to_pop(t_opti first, t_opti second, t_opti last)
{
	first.list = FIRST;
	second.list = SECOND;
	last.list = LAST;

	if (first.total <= second.total)	//	f < s
	{
		if (first.total <= last.total)	//	f < (s & l)
			return (first);
		return (last);					//	l < f < s
	}
	if (second.total < last.total)
		return (second);				//	s <	(f & l)
	return (last);
}
// st->size >= 3 && pas dans l'ordre
t_opti		optimize_push_to_pop(t_stack *st, t_lst *to_pop, int size)
{
	t_opti	first;
	t_opti	second;
	t_opti	last;
	int 	half_size;

	half_size = size / 2;
	first = get_t_opti_insert_sort(st->first->data, half_size, size, to_pop);
	first.list = FIRST;
	if (first.index == 0)
		return (first);
	second = get_t_opti_insert_sort(st->first->next->data, half_size, size, to_pop);
	last =  get_t_opti_insert_sort(st->last->data, half_size, size, to_pop);
	second.list = SECOND;
	last.list = LAST;
	second.total = second.rotate == ROTATE ? second.nb_rotate : second.nb_rotate + 1;
	last.total = last.rotate == INVERSE_ROTATE ? last.nb_rotate : last.nb_rotate + 1;
	first.total = first.nb_rotate;
	printf("first = %d\n second = %d\n last = %d\n", first.total, second.total, last.total);
	return (ret_optimize_push_to_pop(first, second, last));
}

void	optimize_insertion_sort(t_stack *a, t_stack *b)
{
	t_opti op;

	print_two_stacks(a, b);
	op = optimize_push_to_pop(a, b->first, b->size);
	if (op.list == FIRST)
		printf("FIRST\n");
	else if (op.list == SECOND)
	{
		printf("SECOND\n");
		if (op.total == op.nb_rotate)
		{
			print_and_do(a, b, RR);
			op.nb_rotate --;
		}
		else
			print_and_do(a, b, RA);
	}
	else
	{
		printf("LAST\n");
		if (op.total == op.nb_rotate)
		{
			print_and_do(a, b, RRR);
			op.nb_rotate --;
		}
		else
			print_and_do(a, b, RRA);
	}
	print_and_do_multi(a, b, op.rotate == ROTATE ? RB : RRB, op.nb_rotate);
	print_and_do(a, b, PA);
	print_two_stacks(a, b);

}

void	test_insertion_sort(t_stack *a, t_stack *b)
{
	print_two_stacks(a, b);
	three_datas(a);
	print_and_do(a, b, PA);
	print_two_stacks(a, b);
	while (a->size > 2 && check_order(a->first) == false)
	{
		optimize_insertion_sort(a, b);
	}
	while (b->size > 0)
	{
		push_first_b_in_order_on_a(a, b);
	//	if (b->first->data > a->last->data)
	//		print_and_do(a, b, RRA);
	//	print_and_do(a, b, PB);
	}
	while (a->last->data < a->first->data)
		print_and_do(a, b, RRA);
	print_two_stacks(a, b);

//	rotate_b_with_minimal_instruction(b, find_max_data_lst(b->first));
//	while (b->first && a->first->data < b->first->data)
//	{
//		push_first_b_in_order_on_a(a, b);
//		rotate_a_with_minimal_instruction(a, find_min_data_lst(a->first));
//	}
//	print_and_do_multi(a, b, PB, b->size);
}*/

void	make_test(t_stack *a, t_stack *b)
{
	// check rotate min data : the min must be in first index
/*	print_two_stacks(a, b);
	rotate_min_data_in_first(a, b);
	print_two_stacks(a, b);
	exit(0);*/

	// check closest min data
	/*print_two_stacks(a, b);
	int index = find_closest_min_data_lst(a->first, 5);
	printf("index = %d\n", index);
	rotate_min_instruction_for_a(a, index);
	print_two_stacks(a, b);*/

	// push a in order b
	/*print_two_stacks(a, b);
	push_min_a_in_order_b(a, b);
	print_two_stacks(a, b);*/
	
//	test_insertion_sort(a, b);

	if (final_checker_order(a, b) == true)
		ft_putstr("OK\n");
	else
		ft_putstr("KO\n");
	exit(0);
}

int		main(int argc, char *argv[])
{
	t_stack		*a;
	t_stack		*b;

	check_arg(argc);
	a = generate_stack_a_content(argv, argc);
	if (!a)
		return (-1);
	b = malloc_stack(NULL, NULL, 0);


	
//	make_test(a, b);
//	print_two_stacks(a, b);
//	printer_get_instruction(a, b);

	if (get_instructions(a, b) == true)
		ft_putstr("OK\n");
	else
		ft_putstr("KO\n");
	free_stack(a);
	free_stack(b);
	return (0);
}
