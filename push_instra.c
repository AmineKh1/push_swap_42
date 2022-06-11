/* ************************************************************************************************ */
/*                                                                                                  */
/*                                                        :::   ::::::::   ::::::::  :::::::::::    */
/*   push_instra.c                                     :+:+:  :+:    :+: :+:    :+: :+:     :+:     */
/*                                                      +:+         +:+        +:+        +:+       */
/*   By: akhouya <akhouya@student.1337.ma>             +#+      +#++:      +#++:        +#+         */
/*                                                    +#+         +#+        +#+      +#+           */
/*   Created: Invalid date        by                 #+#  #+#    #+# #+#    #+#     #+#             */
/*   Updated: 2022/06/11 15:56:26 by akhouya      ####### ########   ########      ###.ma           */
/*                                                                                                  */
/* ************************************************************************************************ */


#include "push_swap.h"

t_list	*sort_tree(t_list *a)
{
	if (ft_lstsize(a) == 2 && a->index > a->next->index)
	{
		a = swap_a(a);
		return (a);
	}
	if (a->index > a->next->index && a->next->index < a->next->next->index)
	{
		a = swap_a(a);
		a = sort_tree(a);
	}
	if (a->next->index > a->next->next->index && a->index < a->next->index)
	{
		a = rev_round_a(a);
		a = sort_tree(a);
	}
	else if (a->index > a->next->index && a->next->index > a->next->next->index)
	{
		a = round_a(a);
		a = swap_a(a);
	}
	return (a);
}

t_stacks	*sort_five(t_stacks *ab)
{
	while (ft_lstsize(ab->a) > 3)
	{
		if (ab->a->index == 4 || ab->a->index == 0)
			ab = move1to2(ab);
		else if (ab->a->next->index == 4 || ab->a->next->index == 0)
			ab->a = swap_a(ab->a);
		else
			ab->a = rev_round_a(ab->a);
	}
	ab->a = sort_tree(ab->a);
	while (ab->b != NULL)
	{
		ab = move2to1(ab);
		if (ab->a->index == 4)
			ab->a = round_a(ab->a);
	}
	return (ab);
}

int	check_list(t_list *lst)
{
	t_list	*h;

	while (lst != NULL)
	{
		h = lst->next;
		while (h != NULL)
		{
			if (lst->content == h->content)
				return (1);
			h = h->next;
		}
		lst = lst->next;
	}
	return (0);
}

int	strisdigit(char *str)
{
	int	k;

	k = 1;
	if (ft_strlen(str) == 0)
		return (0);
	if (*str == '-' && *(str + 1) != '\0')
	{
		str++;
		k = 1;
	}
	while (*str && k == 1)
		k = ft_isdigit(*str++);
	return (k);
}
