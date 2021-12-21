/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhouya <akhouya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 03:31:50 by akhouya           #+#    #+#             */
/*   Updated: 2021/12/21 19:37:16 by akhouya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	strisdigit(char *str)
{
	int k;
	k = 1;
	if (ft_strlen(str) == 0)
		return 0;
	if(*str == '-' && *(str + 1) != '\0')
	{
		str++;
		k = 1;
	}
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

int main(int argc,char *argv[])
{
	
	t_list *list_nbr;
	t_list *h;
	t_list *k;
	two_list *f;
	char **s;
	int j;
	int size;
	int i;

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
	// if(check_sort(list_nbr) == 0)
	// 	ft_putendl_fd("list is sort", 1);
	// else
	// 	ft_putendl_fd("list is not sort", 1);
	
	k = NULL;
	
	f = malloc(sizeof(two_list));
	f->a = list_nbr;
	f->b = k;
	
	size = 0;
	if(ft_lstsize(f->a) > 5)
	{
		while(check_sort(f->a) != 0)
		{
			if(ft_lstsize(f->a) == 2 && f->a->index > f->a->next->index)
			{
				swap(f->a);
				break;
			}
			f = instruction_when(f, size + ft_lstsize(f->a)/2);
			size = midle_index(f->a);
		}
	}
	while(f->b!= NULL)
		f = instruction_when_rev(f, big_in_b(f->b));

	// while (f->a!= NULL)
	// {
	// 	ft_putnbr_fd(f->a->index, 2);
	// 	ft_putstr_fd("\n",1);
	// 	f->a = f->a->next;
	// }
	// ft_putendl_fd("---", 1);
	// while (f->b!= NULL)
	// {
	// 	ft_putnbr_fd(f->b->index, 1);
	// 	ft_putstr_fd("\n",1);
	// 	f->b = f->b->next;
	// }

	list_nbr = h;
	ft_lstclear(&(f->a));
	ft_lstclear(&(f->b));
	f->a = NULL;
	f->b = NULL;
	free(f);
	f = NULL;
	// system("leaks a.out");

}