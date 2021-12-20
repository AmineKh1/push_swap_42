/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhouya <akhouya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 03:31:50 by akhouya           #+#    #+#             */
/*   Updated: 2021/12/20 07:40:51 by akhouya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	strisdigit(char *str)
{
	int k;
	k = 1;
	if (ft_strlen(str) == 0)
		return 0;
	while(*str && k == 1)
	{
		k = ft_isdigit(*str++);
	}
	return k;
}
int check_list(t_list *lst)
{
	t_list *h;
	while(lst != NULL)
	{
		h = lst->next;
		while(h != NULL)
		{
			if (lst->content == h->content)
				return 1;
			h = h->next;
		}
		lst = lst->next;
	}
	return 0;
}
// t_list	*index(t_list *in)
// {
	
// }
int main(int argc,char *argv[])
{
	int i;
	t_list *list_nbr;
	t_list *h;
	char **s;
	int j;

	i = 0;
	j = 0;
	while (++i <  argc)
	{
		j = -1;
		s = ft_split(argv[i], ' ');
		while  (s[++j] != NULL)
		{
			if (strisdigit(s[j]) == 0)
			{
				ft_lstclear(&list_nbr);
				frealltab(s);
				free(s);
				ft_putendl_fd("error", 1);
				// system("leaks a.out");
				return 0;
			}
			if(i == 1 && j == 0)
				list_nbr = ft_lstnew(ft_atoi(s[j], list_nbr, s));
			else
			{
				h = ft_lstnew(ft_atoi(s[j], list_nbr, s));
				ft_lstadd_back(&list_nbr, h);
			}	
		}
		frealltab(s);
		free(s);
	}
	if (check_list(list_nbr) == 1)
	{
		ft_lstclear(&list_nbr);
		ft_putendl_fd("error", 1);
		// system("leaks a.out");
		exit(0);
	}
	index_list(list_nbr);
	h = list_nbr;
	if(check_sort(list_nbr) == 0)
		ft_putendl_fd("list is sort", 1);
	else
		ft_putendl_fd("list is not sort", 1);
	// swap(list_nbr);
	// list_nbr = rev_round(list_nbr);
	t_list *k;
	k = NULL;
	two_list *f;
	f = malloc(sizeof(two_list));
	f->a = list_nbr;
	f->b = k;
	f = instruction_when(f, 2);
	// f = move1to2(f);
	while (f->a!= NULL)
	{
		ft_putnbr_fd(f->a->index, 1);
		ft_putstr_fd("\n",1);
		f->a = f->a->next;
	}
	ft_putendl_fd("---", 1);
	while (f->b!= NULL)
	{
		ft_putnbr_fd(f->b->index, 1);
		ft_putstr_fd("\n",1);
		f->b = f->b->next;
	}

	list_nbr = h;
	ft_lstclear(&list_nbr);
	// system("leaks a.out");
}