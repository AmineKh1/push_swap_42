/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhouya <akhouya@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 16:04:22 by akhouya           #+#    #+#             */
/*   Updated: 2022/06/10 15:11:08 by akhouya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	condition_addinglist(t_pushswap *p_s)
{
	if (p_s->i == 1 && p_s->j == 0)
	{
		p_s->list_nbr = ft_lstnew(ft_atoi(p_s->s[p_s->j],
					&p_s->list_nbr, p_s->s));
	}
	else
	{	
		p_s->h = ft_lstnew(ft_atoi(p_s->s[p_s->j],
					&p_s->list_nbr, p_s->s));
		ft_lstadd_back(&p_s->list_nbr, p_s->h);
	}
}

void	handle_errors(int argc, char **argv, t_pushswap *p_s)
{
	while (++p_s->i < argc)
	{
		p_s->j = -1;
		p_s->s = ft_split(argv[p_s->i], ' ');
		while (p_s->s[++p_s->j] != NULL)
		{
			if (strisdigit(p_s->s[p_s->j]) == 0)
			{
				ft_lstclear(&p_s->list_nbr);
				frealltab(p_s->s);
				free(p_s->s);
				ft_putendl_fd("error", 1);
				exit(1);
			}
			condition_addinglist(p_s);
		}
		frealltab(p_s->s);
		free(p_s->s);
	}
}

void	init_var(t_pushswap *p_s, t_stacks *f)
{
	index_list(p_s->list_nbr);
	p_s->h = p_s->list_nbr;
	f->a = p_s->list_nbr;
	f->b = NULL;
	p_s->i = ft_lstsize(f->a);
	if(p_s->i <= 3)
	{
		f->a = sort_tree(f->a);
	}
	else if(p_s->i == 5)
		f = sort_five(f);
	else
	{
		p_s->midle = p_s->i / 2;
		if (p_s->i <= 150)
			p_s->j = 13;
		else
			p_s->j = 36;
		p_s->max_r = p_s->midle + p_s->j;
		p_s->min_r = p_s->midle - p_s->j;
		algo_tob(p_s, f);
		algo_toa(p_s, f);
	}
}

void	algo_tob(t_pushswap *p_s, t_stacks *f)
{
	while (f->a != NULL)
	{
		if (p_s->i < p_s->j * 2)
		{
			if (p_s->i == 1)
				p_s->j = 1;
			else
				p_s->j = p_s->i / 2;
		}
		while (ft_lstsize(f->a) > p_s->i - (p_s->j * 2) && f->a != NULL)
			f = push_to_b(f, p_s, p_s->j * 2);
		p_s->min_r = p_s->min_r - p_s->j;
		p_s->max_r = p_s->max_r + p_s->j;
		p_s->i = ft_lstsize(f->a);
	}	
}

void	algo_toa(t_pushswap *p_s, t_stacks *f)
{
	p_s->max_r = ft_lstsize(f->b) - 1;
	p_s->q = big_in_b(f->b);
	while (f->b != NULL)
		f = instruction_when_rev(f, p_s->max_r--, p_s->q);
	while (check_sort(f->a) != 0)
		f->a = rev_round_a(f->a);
}
