/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_instruction3.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhouya <akhouya@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 11:12:18 by akhouya           #+#    #+#             */
/*   Updated: 2022/06/08 11:16:20 by akhouya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*round_a(t_list *lst)
{
	ft_putendl_fd("ra", 1);
	return (round_list(lst));
}

t_list	*round_b(t_list *lst)
{
	ft_putendl_fd("rb", 1);
	return (round_list(lst));
}

t_stacks	*round_ab(t_stacks *ab)
{
	ab->a = round_list(ab->a);
	ab->b = round_list(ab->b);
	ft_putendl_fd("rr", 1);
	return (ab);
}

t_list	*rev_round(t_list *lst)
{
	t_list	*h;
	t_list	*j;

	j = ft_lstlast(lst);
	h = ft_lstbeforelast(lst);
	ft_lstlast(lst)->next = lst;
	h->next = NULL;
	return (j);
}

t_list	*rev_round_a(t_list *lst)
{
	ft_putendl_fd("rra", 1);
	return (rev_round(lst));
}
