/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_checker_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhouya <akhouya@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 11:46:32 by akhouya           #+#    #+#             */
/*   Updated: 2022/06/11 16:57:35 by akhouya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

t_list	*rev_round_b_check(t_list *lst)
{
	if (ft_lstsize(lst) < 2)
		return (lst);
	return (rev_round(lst));
}

t_stacks	*rev_round2_check(t_stacks *ab)
{
	ab->a = rev_round_a_check(ab->a);
	ab->b = rev_round_b_check(ab->b);
	return (ab);
}

t_stacks	*move1to2_check(t_stacks *ab)
{
	t_list	*a;
	t_list	*b;
	t_list	*tmp;

	if (!ab->a)
		return (ab);
	a = ab->a;
	b = ab->b;
	tmp = a;
	a = a->next;
	ab->a = a;
	ab->b = tmp;
	tmp->next = b;
	return (ab);
}

t_stacks	*move2to1_check(t_stacks *ab)
{
	t_list	*tmp;
	t_list	*tmp2;

	if (!ab->b)
		return (ab);
	tmp = ab->b->next;
	tmp2 = ab->a;
	ab->a = ab->b;
	ab->a->next = tmp2;
	ab->b = tmp;
	return (ab);
}

t_list	*swap_a_check(t_list *lst)
{
	if (ft_lstsize(lst) < 2)
		return (lst);
	lst = swap(lst);
	return (lst);
}
