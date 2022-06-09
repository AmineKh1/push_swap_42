/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_instruction.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhouya <akhouya@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 11:03:13 by akhouya           #+#    #+#             */
/*   Updated: 2022/06/09 16:43:45 by akhouya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int check_rrtoa()
t_stacks	*instruction_when_rev(t_stacks *ab, int index, int q)
{
	int	i;

	i = place_of_indexx(ab->b, index);
	if (ab->b->index == index)
		ab = move2to1(ab);
	//else if (ab->b->next->index == index)
	//{
	//	ab->b = swap_b(ab->b);
	//	ab = instruction_when_rev(ab, index, q);
	//}
	else if (ft_lstsize(ab->a) > 0 && ft_lstlast(ab->a)->index == index)
		ab->a = rev_round_a(ab->a);
	else if (ft_lstsize(ab->a) == 0 || ft_lstlast(ab->a)->index == q)
	{
		ab = move2to1(ab);
		if (ft_lstsize(ab->a) != 0)
		{
			ab->a = round_a(ab->a);
		}
		ab = instruction_when_rev(ab, index, q);
	}
	else if (ft_lstlast(ab->a)->index < ab->b->index)
	{
		ab = move2to1(ab);
		ab->a = round_a(ab->a);
		ab = instruction_when_rev(ab, index, q);
	}
	else
	{
		if (i == 1)
			ab->b = rev_round_b(ab->b);
		if (i == -1)
			ab->b = round_b(ab->b);
		ab = instruction_when_rev(ab, index, q);
	}
	return (ab);
}
int check_rr(t_stacks *ab, t_pushswap *p_s)
{
	int i;
	i = place_of_index(ab->a, p_s->max_r, p_s->min_r);
	if (i == 1)
		return 1;
	return 0;
}
t_stacks	*push_to_b(t_stacks *ab, t_pushswap *p_s, int j)
{
	int	i;

	i = place_of_index(ab->a, p_s->max_r, p_s->min_r);
	if (ab->a->index >= p_s->min_r && ab->a->index < p_s->max_r)
	{
		ab = move1to2(ab);
		if (ft_lstsize(ab->b) != 0 && ab->b->index < p_s->midle)
		{
			if (check_rr(ab, p_s) == 1)
				ab = round_ab(ab);
			else
				ab->b = round_b(ab->b);
			
		}
	}
	else
	{
		if (i == -1)
			ab->a = rev_round_a(ab->a);
		if (i == 1)
			ab->a = round_a(ab->a);
		ab = push_to_b(ab, p_s, j);
	}
	return (ab);
}

t_list	*sort_tree(t_list *a)
{
	if (a->index > a->next->index && a->next->index < a->next->next->index)
		a = swap_a(a);
	if (a->next->index > a->next->next->index && a->index < a->next->index)
		a = rev_round_a(a);
	else if (a->index > a->next->index && a->next->index > a->next->next->index)
	{
		a = round_a(a);
		a = swap_a(a);
	}
	return (a);
}

t_list	*sort_five(t_list *a)
{
	if (a->index > a->next->index && a->next->index < a->next->next->index)
		a = swap_a(a);
	if (a->next->index > a->next->next->index && a->index < a->next->index)
		a = rev_round_a(a);
	else if (a->index > a->next->index && a->next->index > a->next->next->index)
	{
		a = round_a(a);
		a = swap_a(a);
	}
	return (a);
}