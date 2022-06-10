/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhouya <akhouya@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 03:31:50 by akhouya           #+#    #+#             */
/*   Updated: 2022/06/10 12:07:46 by akhouya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	printlis(t_stacks *f)
{
	ft_putendl_fd("---a", 1);
	while (f->a != NULL)
	{
		ft_putnbr_fd(f->a->index, 2);
		ft_putstr_fd("\n", 2);
		f->a = f->a->next;
	}
	ft_putendl_fd("---b", 2);
	while (f->b != NULL)
	{
		ft_putnbr_fd(f->b->index, 2);
		ft_putstr_fd("\n", 2);
		f->b = f->b->next;
	}
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

int	main(int argc, char *argv[])
{
	t_stacks	*f;
	t_pushswap	p_s;

	p_s.i = 0;
	p_s.j = 0;
	handle_errors(argc, argv, &p_s);
	if (check_list(p_s.list_nbr) == 1)
	{
		ft_lstclear(&p_s.list_nbr);
		ft_putendl_fd("error", 1);
		exit(1);
	}
	f = malloc(sizeof(t_stacks));
	init_var(&p_s, f);
	algo_tob(&p_s, f);
	algo_toa(&p_s, f);
	//printlis(f);
	p_s.list_nbr = p_s.h;
	ft_lstclear(&(f->a));
	ft_lstclear(&(f->b));
	f->a = NULL;
	f->b = NULL;
	free(f);
	f = NULL;
}
