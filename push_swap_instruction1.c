/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_instruction1.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhouya <akhouya@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 11:16:53 by akhouya           #+#    #+#             */
/*   Updated: 2022/06/09 11:14:19 by akhouya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*rev_round_b(t_list *lst)
{
	ft_putendl_fd("rrb", 1);
	return (rev_round(lst));
}

t_stacks	*rev_round2(t_stacks *ab)
{
	ab->a = rev_round(ab->a);
	ab->b = rev_round(ab->b);
	ft_putendl_fd("rrr", 1);
	return (ab);
}

t_stacks	*move1to2(t_stacks *ab)
{
	t_list	*a;
	t_list	*b;
	t_list	*tmp;

	a = ab->a;
	b = ab->b;
	tmp = a;
	a = a->next;
	ab->a = a;
	ab->b = tmp;
	tmp->next = b;
	ft_putendl_fd("pb", 1);
	return (ab);
}

t_stacks	*move2to1(t_stacks *ab)
{
	t_list	*tmp;
	t_list	*tmp2;

	tmp = ab->b->next;
	tmp2 = ab->a;
	ab->a = ab->b;
	ab->a->next = tmp2;
	ab->b = tmp;
	ft_putendl_fd("pa", 1);
	return (ab);
}

int	check_sort(t_list *lst)
{
	while (lst->next != NULL && lst->index == (lst->next->index) - 1)
		lst = lst->next;
	if (lst->next == NULL)
		return (0);
	return (1);
}
