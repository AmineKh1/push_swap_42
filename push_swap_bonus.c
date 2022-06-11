/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhouya <akhouya@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 13:45:25 by akhouya           #+#    #+#             */
/*   Updated: 2022/06/11 17:31:55 by akhouya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

t_list	*swap_b_check(t_list *lst)
{
	if (ft_lstsize(lst) < 2)
		return (lst);
	lst = swap(lst);
	return (lst);
}

void	compare_exit(char *s)
{
	void	(*s);

	ft_putendl_fd("Error", 1);
	exit(1);
}

void	compare(t_stacks *f, char *s)
{
	if (ft_memcmp(s, "sa\n", 3) == 0)
		f->a = swap_a_check(f->a);
	else if (ft_memcmp(s, "sb\n", 3) == 0)
		f->b = swap_b_check(f->b);
	else if (ft_memcmp(s, "ss\n", 3) == 0)
		f = swap_ss_check(f);
	else if (ft_memcmp(s, "ra\n", 3) == 0)
		f->a = round_a_check(f->a);
	else if (ft_memcmp(s, "rb\n", 3) == 0)
		f->b = round_b_check(f->b);
	else if (ft_memcmp(s, "rr\n", 3) == 0)
		f = round_ab_check(f);
	else if (ft_memcmp(s, "rra\n", 4) == 0)
		f->a = rev_round_a_check(f->a);
	else if (ft_memcmp(s, "rrb\n", 4) == 0)
		f->b = rev_round_b_check(f->b);
	else if (ft_memcmp(s, "rrr\n", 4) == 0)
		f = rev_round2_check(f);
	else if (ft_memcmp(s, "pb\n", 3) == 0)
		f = move1to2_check(f);
	else if (ft_memcmp(s, "pa\n", 3) == 0)
		f = move2to1_check(f);
	else
		compare_exit(s);
}

void	handle_error_checker(t_stacks *f)
{
	char	*s;

	s = get_next_line(0);
	while (s != NULL)
	{
		compare(f, s);
		free(s);
		s = get_next_line(0);
	}
}

int	main(int argc, char **argv)
{
	t_stacks	*f;
	t_pushswap	p_s;

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
	handle_error_checker(f);
	if (check_sort(f->a) == 0)
		ft_putendl_fd("OK", 1);
	else
		ft_putendl_fd("KO", 1);
}
