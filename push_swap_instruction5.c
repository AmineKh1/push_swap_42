/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_instruction5.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhouya <akhouya@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 12:49:55 by akhouya           #+#    #+#             */
/*   Updated: 2022/06/08 13:40:30 by akhouya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	midle_index(t_list *a)
{
	int	j;

	j = a->index;
	while (a->next != NULL)
	{	
		if (j > a->next->index)
			j = a->next->index;
		a = a->next;
	}
	return (j);
}

int	big_in_b(t_list *a)
{
	int	j;

	j = a->index;
	while (a->next != NULL)
	{
		if (j < a->next->index)
			j = a->next->index;
		a = a->next;
	}
	return (j);
}

int	checkswap_b(t_stacks *ab)
{
	if (ab->b == NULL)
		return (1);
	if (ab->b->next == NULL)
		return (1);
	if (ab->b->next->index == big_in_b(ab->b))
		return (0);
	return (1);
}

int	checkround_b(t_stacks *ab)
{
	if (ab->b == NULL)
		return (1);
	if (ab->b->next == NULL)
		return (1);
	if (place_of_indexx(ab->b, big_in_b(ab->b)) < ft_lstsize(ab->b) / 2
		&& ab->b->index != big_in_b(ab->b) && ft_lstsize(ab->b) > 2)
		return (0);
	return (1);
}

int	checkr_round_b(t_stacks *ab)
{
	if (ab->b == NULL)
		return (1);
	if (ab->b->next == NULL)
		return (1);
	if (place_of_indexx(ab->b, big_in_b(ab->b)) > ft_lstsize(ab->b) / 2
		&& ft_lstsize(ab->b) > 2 && ab->b->index != big_in_b(ab->b))
		return (0);
	return (1);
}
