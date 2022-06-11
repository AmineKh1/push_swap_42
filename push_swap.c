/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhouya <akhouya@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 03:31:50 by akhouya           #+#    #+#             */
/*   Updated: 2022/06/11 16:52:13 by akhouya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
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
	init_var(&p_s, f);
}
