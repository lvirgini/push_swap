/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 20:09:31 by lvirgini          #+#    #+#             */
/*   Updated: 2021/04/16 12:00:14 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_lst(t_lst *l)
{
	printf("%d", l->data);
}

void	print_all_lst(t_lst *lst)
{
	t_lst	*l;

	l = lst;
	while (l)
	{
		printf("|%d| ", l->data);
		l = l->next;
	}
	printf("\n");
}

/*
void	print_tab_int(int	*tab, size_t size)
{
	printf("\t");
	for (size_t i = 0; i < size; i++)
		printf("[%d] ", tab[i]);
	printf("\n");
}


void	print_reverse_tab_int(int	*tab, int up)
{

	printf("\t");
	while (up >= 0)
	{
		printf("[%d] ", tab[up]);
		up--;
	}	
	printf("\n");
}

void	print_tab_char(char **str)
{
	printf("str = \t");
		for (int i = 0; str && str[i]; i++)
			printf("|%s| ", str[i]);
	printf("\n");
}

void	print_2tab_status(t_tab *tab)
{
	printf("A = ");
	print_tab_int(&tab->data[tab->a], tab->size - tab->a);
	printf("B = ");
	print_reverse_tab_int(tab->data, tab->b);
	//printf("ALL = ");
	//print_tab_int(tab->data, tab->size);
	printf("---------------------------------------------- \n");
}*/