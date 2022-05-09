/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhouya <akhouya@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 23:12:50 by akhouya           #+#    #+#             */
/*   Updated: 2022/05/09 19:22:25 by akhouya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

static int	calcule(const char *nptr, int sign, t_list **list_nbr, char **s)
{
	unsigned long	r;

	r = 0;
	while (*nptr >= '0' && *nptr <= '9')
	{
		r = r * 10;
		if ((r > 2147483647 && sign == 1) || (r > 2147483648 && sign == -1))
		{
			ft_lstclear(list_nbr);
			frealltab(s);
			free(s);
			ft_putendl_fd("error", 1);
			exit(1);
		}
		r = r + (*nptr - '0');
		nptr++;
	}
	return ((int)r * sign);
}

int	ft_atoi(const char *nptr, t_list **list_nbr, char **s)
{
	unsigned long	r;
	int				signe;

	r = 0;
	signe = 1;
	while (*nptr == ' ' || *nptr == '\t' || *nptr == '\v' || *nptr == '\r'
		|| *nptr == '\n' || *nptr == '\f')
		nptr++;
	if (*nptr == '-')
	{
		signe = -1;
		nptr++;
	}
	else if (*nptr == '+')
		nptr++;
	r = calcule(nptr, signe, list_nbr, s);
	return (r);
}
