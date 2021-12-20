#include "push_swap.h"

void	swap(t_list *lst)
{
	int content;
	int index;
	
	content = lst->content;
	index = lst->index;
	lst->content = lst->next->content;
	lst->index = lst->next->index;
	lst->next->content = content;
	lst->next->index = index;
	


}

void	swap_ss(t_list *lst_a, t_list *lst_b)
{
	swap(lst_a);
	swap(lst_b);
}

t_list	*round_list(t_list *lst)
{
	t_list	*h;

	ft_lstlast(lst)->next = lst;
	h = lst->next;
	lst->next = NULL;
	return h;
}

two_list	*round_ab(t_list *lst_a, t_list *lst_b)
{
	two_list	*ab;
	ab->a = round_list(lst_a);
	ab->b = round_list(lst_b);
	return (ab);
}

t_list	*rev_round(t_list *lst)
{
	t_list	*h;
	t_list	*j;
	j = ft_lstlast(lst);
	h = ft_lstbeforelast(lst);
	ft_lstlast(lst)->next = lst;
	h->next = NULL;
	return j;
}

two_list	*rev_round2(t_list *lst_a, t_list *lst_b)
{
	two_list	*ab;
	ab->a = rev_round(lst_a);
	ab->b = rev_round(lst_b);
	return (ab);
}

two_list	*move1to2(two_list *ab)
{
	t_list	*a;
	t_list	*b;
	a = ab->a;
	b = ab->b;
	t_list *tmp;
	tmp = a;
	a  = a->next;
	ab->a = a;
	ab->b = tmp;
	tmp->next = b;
	return ab;
}

int	check_sort(t_list *lst)
{
	while(lst->next != NULL && lst->index == (lst->next->index) - 1)
	{
		lst = lst->next;
	}
	if (lst->next == NULL)
		return 0;
	return 1;
}
int	count(int content, t_list *head)
{
	int count;
	count = 0;
	while(head != NULL)
	{
		if(content > head->content)
		{
			count = count + 1;
		}
		head = head->next;
	}
	return count;
}
void	index_list(t_list *lst)
{
	t_list *h;
	h = (lst);
	while(lst != NULL)
	{	
		(lst)->index = count(lst->content, h);
	
		lst = lst->next;
	}
}
/*
t_list	*sort_3(t_list *lst)
{
	
}*/
int	place_of_index(t_list *l, int index)
{
	int count;
	count = 0;
	while(l != NULL)
	{
		count++;
		if(l->index < index)
		{
			return count;
		}
		l = l->next;
	}
	return -1;
}
int	midle_index(t_list *a)
{
	int j;
	j= a->index;
	while(a->next != NULL)
	{
		
		if(j > a->next->index)
		{
			
			j = a->next->index;
		}
		a = a->next;
	}
	// i = i - j;
	return j;
}
two_list	*instruction_when(two_list *ab, int index)
{
	
	int g = place_of_index(ab->a, index);
	// ft_putnbr_fd(g,1);
	// ft_putendl_fd("----", 1);
	if(ab->a->index < index)
	{
		ab = move1to2(ab);
		// ab = instruction_when(ab, index);
	}
	else if(ab->a->next->index < index)
	{
		swap(ab->a);
		ab = instruction_when(ab,index);
	}
	else if(place_of_index(ab->a, index) < ft_lstsize(ab->a)/2 && place_of_index(ab->a, index) != -1)
	{
		// printf("-1-\n");
		ab->a = round_list(ab->a);
		ab = instruction_when(ab, index);
	}
	else if(place_of_index(ab->a, index) >= ft_lstsize(ab->a)/2 && place_of_index(ab->a,index) != -1)
	{
		// printf("-2-\n");
		ab->a = rev_round(ab->a);
		ab = instruction_when(ab, index);
	}
	// else if (check_sort(ab->a) != 0)
	// 	ab = instruction_when(ab, ft_lstsize(ab->a)/2);
	return ab;
}
// totalement 3akes dyal li lfo9
