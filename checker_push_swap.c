/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_push_swap.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhouya <akhouya@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 13:45:25 by akhouya           #+#    #+#             */
/*   Updated: 2022/06/11 14:01:37 by akhouya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"
#include<string.h>
t_list	*swap_b_check(t_list *lst)
{
    if (ft_lstsize(lst) < 2)
        return lst;
	lst = swap(lst);
	return (lst);
}

int main(int argc, char **argv)
{
    t_stacks	*f;
	t_pushswap	p_s;
	char *s;

	p_s.i = 0;
	p_s.j = 0;
	handle_errors(argc, argv, &p_s);
	if (check_list(p_s.list_nbr) == 1)
	{
		ft_putendl_fd("Error", 1);
		exit(1);
	}
	f = malloc(sizeof(t_stacks));
	index_list(p_s.list_nbr);
	p_s.h = p_s.list_nbr;
	f->a = p_s.list_nbr;
	f->b = NULL;
	s = get_next_line(0);
	while(s != NULL)
	{
		if (strcmp(s, "sa"))
		{
			write(1, "s",1);
			f->a = swap_a_check(f->a);
		}
		else if(strcmp(s, "sb"))
		{
			f->b = swap_b_check(f->b);
		}
		else if(strcmp(s, "ss"))
		{
			f = swap_ss_check(f);
		}
		else if(strcmp(s, "ra"))
		{
			f->a = round_a_check(f->a);
		}
		else if(strcmp(s, "rb"))
			f->b = round_b_check(f->b);
		else if(strcmp(s, "rr"))
			f = round_ab_check(f);
		else if(strcmp(s, "rra"))
		{
			write(1, "r",1);
			f->a = rev_round_a_check(f->a);
		}
		else if(strcmp(s, "rrb"))
			f->b = rev_round_b_check(f->b);
		else if(strcmp(s, "rrr"))
			f = rev_round2_check(f);
		else
		{
			ft_putendl_fd("Error", 1);
			exit(1);
		}
		free(s);
		s = get_next_line(0);
	}
	if(check_sort(f->a) == 0)
		ft_putendl_fd("OK", 1);
	else
		ft_putendl_fd("KO", 1);
	printlis(f);
}