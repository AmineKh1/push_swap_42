/* ************************************************************************************************ */
/*                                                                                                  */
/*                                                        :::   ::::::::   ::::::::  :::::::::::    */
/*   push_swap_instruction.c                           :+:+:  :+:    :+: :+:    :+: :+:     :+:     */
/*                                                      +:+         +:+        +:+        +:+       */
/*   By: akhouya <akhouya@student.1337.ma>             +#+      +#++:      +#++:        +#+         */
/*                                                    +#+         +#+        +#+      +#+           */
/*   Created: Invalid date        by                 #+#  #+#    #+# #+#    #+#     #+#             */
/*   Updated: 2022/06/11 15:52:21 by akhouya      ####### ########   ########      ###.ma           */
/*                                                                                                  */
/* ************************************************************************************************ */

#include "push_swap.h"
#include <stdio.h>

t_stacks	*instruction_when_rev(t_stacks *ab, int index, int q)
{
	int	i;

	i = place_of_indexx(ab->b, index);
	if (ab->b->index == index)
	{
		ab = move2to1(ab);
	}
	else if (ab->b->next != NULL && ab->b->next->index == index)
	{
		ab->b = swap_b(ab->b);
		ab = instruction_when_rev(ab, index, q);
	}
	else if (ft_lstsize(ab->a) > 0 && ft_lstlast(ab->a)->index == index)
	{
		if(place_of_indexx(ab->b, --index) == 1 && ft_lstsize(ab->b) > 1)
		{
			ab = rev_round2(ab);
		}
		else
			ab->a = rev_round_a(ab->a);
	}
	else if (ft_lstsize(ab->a) == 0 || ft_lstlast(ab->a)->index == q)
	{
		ab = move2to1(ab);
		if (ft_lstsize(ab->a) != 0)
			ab->a = round_a(ab->a);
		ab = instruction_when_rev(ab, index, q);
	}
	else if (ft_lstlast(ab->a)->index < ab->b->index)
	{
		ab = move2to1(ab);
		if(place_of_indexx(ab->b, index) == -1)
			ab = round_ab(ab);
		else
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
			if (check_rr(ab, p_s) == 1 && ft_lstsize(ab->a) > 1)
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
