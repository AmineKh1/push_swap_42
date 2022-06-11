/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhouya <akhouya@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 16:54:15 by akhouya           #+#    #+#             */
/*   Updated: 2022/06/11 16:55:03 by akhouya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
