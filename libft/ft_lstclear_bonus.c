/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhouya <akhouya@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 22:06:26 by akhouya           #+#    #+#             */
/*   Updated: 2022/06/11 10:41:25 by akhouya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst)
{
	t_list	*l;
	t_list	*next;

	l = *lst;
	if (!lst)
		return ;
	while (l != NULL)
	{
		next = l -> next;
		ft_lstdelone(l);
		l = next;
	}
	*lst = NULL;
}
