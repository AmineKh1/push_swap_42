/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhouya <akhouya@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 03:31:50 by akhouya           #+#    #+#             */
/*   Updated: 2022/05/13 12:13:01 by akhouya          ###   ########.fr       */
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
void	printlis(two_list *f)
{
	while (f->a!= NULL)
	{
		ft_putnbr_fd(f->a->index, 2);
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
#include<stdio.h>
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
				list_nbr = ft_lstnew(ft_atoi(s[j], &list_nbr, s));
			else
			{
				h = ft_lstnew(ft_atoi(s[j], &list_nbr, s));
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
	int w;
	int y;
	y = 0;
	w = 0;
	// if(ft_lstsize(f->a) > 5)
	// {
	// 	f->size = ft_lstsize(f->a)/2;
	// 	f->count = ft_lstsize(f->a);
	// 	w = ft_lstsize(f->a)/2;
	// 	while(check_sort(f->a) != 0)
	// 	{
	// 		if(ft_lstsize(f->a) == 2)
	// 		{
	// 			if(f->a->index > f->a->next->index)
	// 				swap(f->a);
	// 			else
	// 				move1to2(f);
	// 			break;
	// 		}
	// 		if(ft_lstsize(f->a) < f->size)
	// 		{
	// 			y = (f->size)%2;
	// 			f->size = (f->size)/2;
	// 			w = (f->count) - (f->size);
	// 		}
	// 		f = instruction_when(f, w);
	// 		i = size+ ft_lstsize(f->a)/2;
	// 		printf("---|%d|---\n",f->size);
	// 		size = midle_index(f->a);
	// 		// size = midle_index(f->a);
	// 		// printf("---%d---|---%d---\n", size, ft_lstsize(f->a)/2);
	// 		// if(f->b->index >= 49)
	// 		// 	break;
	// 	}
	// }
	int p;
	int r;
	int u;
	r = ft_lstsize(f->a);
	p = r/2;
	// while(check_sort(f->a) !=0)
	// {
		// if(ft_lstsize(f->a) == 2)
		// {
		// 	if(f->a->index > f->a->next->index)
		// 		swap(f->a);
		// 	else
		// 		move1to2(f);
		// 	break;
	// 	}
	double o;
	if(ft_lstsize(f->a) <= 100)
		o = 1.36;
	else
		o = 1.215;
	p = o;
	while(check_sort(f->a) != 0 )
	{
		u = p;
		u = r - p;
		while(place_of_index(f->a, u) != -1)
			f = instruction_when(f, u);
		p = p/o;
		//prefcet for p = 1.33 <= 100
	}
		// u = p;
		// u = r - p;
		// while(place_of_index(f->a, u) != -1)
		// {
		// 	f = instruction_when(f, u);
		// }
		// p = p/2;
		
		// u = p;
		// u = r - p;
		// while(place_of_index(f->a, u) != -1)
		// {
		// 	f = instruction_when(f, u);
		// }
		// p = p/2;
		// u = p;
		// u = r - p;
		// while(place_of_index(f->a, u) != -1)
		// {
		// 	f = instruction_when(f, u);
		// }
		// p = p/2;
		// u = p;
		// u = r - p;
		// while(place_of_index(f->a, u) != -1)
		// {
		// 	f = instruction_when(f, u);
		// }
		// p = p/2;
		// u = p;
		// u = r - p;
		// while(place_of_index(f->a, u) != -1)
		// {
		// 	f = instruction_when(f, u);
		// }
		// p = p/2;
		
	// }
	// printf("-----------\n");
	while(f->b!= NULL)
		f = instruction_when_rev(f, big_in_b(f->b));
	// round_ab(f);
	// round_ab(f);
	 printlis(f);
	
	list_nbr = h;
	ft_lstclear(&(f->a));
	ft_lstclear(&(f->b));
	f->a = NULL;
	f->b = NULL;
	free(f);
	f = NULL;
	//system("leaks a.out");

}