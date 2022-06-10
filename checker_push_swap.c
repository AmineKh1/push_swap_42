/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_push_swap.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhouya <akhouya@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 13:45:25 by akhouya           #+#    #+#             */
/*   Updated: 2022/06/10 14:41:31 by akhouya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
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
}