/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_checker_bonus1.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhouya <akhouya@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 12:00:27 by akhouya           #+#    #+#             */
/*   Updated: 2022/06/11 16:58:40 by akhouya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

t_stacks	*swap_ss_check(t_stacks *ab)
{
	ab->a = swap_a_check(ab->a);
	ab->b = swap_b_check(ab->b);
	return (ab);
}

t_list	*round_a_check(t_list *lst)
{
	if (ft_lstsize(lst) < 2)
		return (lst);
	return (round_list(lst));
}

t_list	*round_b_check(t_list *lst)
{
	if (ft_lstsize(lst) < 2)
		return (lst);
	return (round_list(lst));
}

t_stacks	*round_ab_check(t_stacks *ab)
{
	ab->a = round_a_check(ab->a);
	ab->b = round_b_check(ab->b);
	return (ab);
}

t_list	*rev_round_a_check(t_list *lst)
{
	if (ft_lstsize(lst) < 2)
		return (lst);
	return (rev_round(lst));
}
