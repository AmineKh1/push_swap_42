/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_instruction4.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhouya <akhouya@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 12:31:28 by akhouya           #+#    #+#             */
/*   Updated: 2022/06/09 16:05:08 by akhouya          ###   ########.fr       */
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

int	 place_of_index(t_list *l, int max_r, int min_r)
{
	int	count;
	int	first;
	int	last;
	int	i;
	int dflt;

	first = 0;
	last = 0;
	count = 0;
	dflt = 0;
	i = ft_lstsize(l);
	while (l != NULL)
	{
		count++;
		if (l->index < max_r && l->index >= min_r)
		{
			dflt = 1;
			first = count;
			break ;
		}
		l = l->next;
	}
	if(l != NULL)
		l = l->next;
	while (l != NULL)
	{
		count++;
		if (l->index < max_r && l->index >= min_r)
		{
			dflt = 1;
			last = count;
		}
		l = l->next;
	}
	if (dflt == 0)
		return 0;
	if (first < i - last)
		return (1);
	return (-1);
}

int	place_of_indexx(t_list *l, int index)
{
	int	j;
	int	count;

	j = ft_lstsize(l);
	count = 0;
	while (l != NULL)
	{
		count++;
		if (l->index == index)
			break ;
		l = l->next;
	}
	if (count >= j / 2)
		return (1);
	return (-1);
}

int	place_of_inde(t_list *l, int max_r, int min_r)
{
	int	count;

	count = 0;
	while (l != NULL)
	{
		count++;
		if (l->index <= max_r && l->index >= min_r)
			return (count);
		l = l->next;
	}
	return (-1);
}
