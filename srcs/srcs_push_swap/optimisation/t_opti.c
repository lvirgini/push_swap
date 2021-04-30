/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_opti.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 15:30:00 by lvirgini          #+#    #+#             */
/*   Updated: 2021/04/30 22:53:53 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** total = total instruction needed.
** return the min t_opti total instruction.
*/

static void		get_total_rotate_opti(t_opti *op)
{
	if (op->b_type_rotate == op->a_type_rotate)
	{
		while (op->b_rotate > 0 && op->a_rotate > 0)
		{
			op->common_rotate++;
			op->b_rotate--;
			op->a_rotate--;
		}
	}
	op->total = op->common_rotate + op->a_rotate + op->b_rotate;
}

/*
** t_opti : search for the best element that requires the least number of
**		instructions between the first, the second and the last element
**		to push into lst(to pop)
*/

t_opti			generate_t_opti(int data, int a_index, int a_size,
									t_stack *b)
{
	t_opti		ret;

	ret.a_index = a_index;
	ret.b_index = get_index_for_push(data, b->first);
	ret.a_type_rotate = get_type_of_rotation(a_index, a_size / 2);
	ret.b_type_rotate = get_type_of_rotation(ret.b_index, b->size / 2);
	ret.b_rotate = get_min_instruction_for_rotate(ret.b_type_rotate,
				ret.b_index, b->size);
	ret.a_rotate = get_min_instruction_for_rotate(ret.a_type_rotate,
				a_index, a_size);
	if (ret.a_type_rotate == INVERSE_ROTATE)
		ret.a_rotate++;
	ret.common_rotate = 0;
	get_total_rotate_opti(&ret);
	return (ret);
}

static t_opti	get_the_best_next_opti(t_lst *l[2], t_stack *b, int l_size,
			int index)
{
	t_opti	from_first;
	t_opti	from_last;

	from_first = generate_t_opti(l[0]->data, index, l_size, b);
	from_last = generate_t_opti(l[1]->data, l_size - index + 1, l_size, b);
	if (from_first.total > from_last.total)
		return (from_last);
	return (from_first);
}

t_opti			check_other_opti(t_opti op, t_stack *a, t_stack *b)
{
	t_opti	better;
	t_opti	tmp;
	int		i;
	t_lst	*from_first;
	t_lst	*from_last;

	i = 2;
	from_first = a->first->next->next;
	from_last = a->last->prev;
	better = get_the_best_next_opti((t_lst *[2]){from_first, from_last}, b,
		a->size, i);
	i = 3;
	while (i < op.total && (i * 2) <= a->size)
	{
		from_first = from_first->next;
		from_last = from_last->prev;
		tmp = get_the_best_next_opti((t_lst *[2]){from_first, from_last}, b,
			a->size, i);
		if (better.total > tmp.total)
			better = tmp;
		i++;
	}
	if (better.total < op.total)
		return (better);
	return (op);
}
