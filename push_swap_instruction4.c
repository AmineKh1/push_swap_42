/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_instruction4.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhouya <akhouya@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 12:31:28 by akhouya           #+#    #+#             */
/*   Updated: 2022/06/11 16:51:24 by akhouya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count(int content, t_list *head)
{
	int	count;

	count = 0;
	while (head != NULL)
	{
		if (content > head->content)
			count = count + 1;
		head = head->next;
	}
	return (count);
}

void	index_list(t_list *lst)
{
	t_list	*h;

	h = (lst);
	while (lst != NULL)
	{	
		(lst)->index = count(lst->content, h);
		lst = lst->next;
	}
}

void	help_place_norme(t_list *l, int max_r, int min_r, t_var *var)
{
	while (l != NULL)
	{
		var->count++;
		if (l->index < max_r && l->index >= min_r)
		{
			var->dflt = 1;
			var->first = var->count;
			break ;
		}
		l = l->next;
	}
}

int	place_of_index(t_list *l, int max_r, int min_r)
{
	t_var	var;

	var.first = 0;
	var.last = 0;
	var.count = 0;
	var.dflt = 0;
	var.i = ft_lstsize(l);
	help_place_norme(l, max_r, min_r, &var);
	if (l != NULL)
		l = l->next;
	while (l != NULL)
	{
		var.count++;
		if (l->index < max_r && l->index >= min_r)
		{
			var.dflt = 1;
			var.last = var.count;
		}
		l = l->next;
	}
	if (var.dflt == 0)
		return (0);
	if (var.first < var.i - var.last)
		return (1);
	return (-1);
}

int	place_of_indexx(t_list *l, int index)
{
	int	j;
	int	count;
	int	dflt;

	dflt = 0;
	j = ft_lstsize(l);
	count = 0;
	while (l != NULL)
	{
		count++;
		if (l->index == index)
		{
			dflt = 1;
			break ;
		}
		l = l->next;
	}
	if (dflt == 0)
		return (0);
	if (count >= j / 2)
		return (1);
	return (-1);
}
