/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_instruction2.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhouya <akhouya@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 11:03:08 by akhouya           #+#    #+#             */
/*   Updated: 2022/06/08 11:12:00 by akhouya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*swap(t_list *lst)
{
	t_list	*h;
	t_list	*g;

	h = lst->next->next;
	g = lst;
	lst = lst->next;
	lst->next = g;
	lst->next->next = h;
	return (lst);
}

t_list	*swap_a(t_list *lst)
{
	lst = swap(lst);
	ft_putendl_fd("sa", 1);
	return (lst);
}

t_list	*swap_b(t_list *lst)
{
	lst = swap(lst);
	ft_putendl_fd("sb", 1);
	return (lst);
}

t_stacks	*swap_ss(t_stacks *ab)
{
	ab->a = swap(ab->a);
	ab->b = swap(ab->b);
	ft_putendl_fd("ss", 1);
	return (ab);
}

t_list	*round_list(t_list *lst)
{
	t_list	*h;

	ft_lstlast(lst)->next = lst;
	h = lst->next;
	lst->next = NULL;
	return (h);
}
