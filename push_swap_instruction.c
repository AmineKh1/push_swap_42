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
void	swap_a(t_list *lst)
{
	swap(lst);
	ft_putendl_fd("sa", 1);
}
void	swap_b(t_list *lst)
{
	swap(lst);
	ft_putendl_fd("sb", 1);
}
void	swap_ss(t_list *lst_a, t_list *lst_b)
{
	swap(lst_a);
	swap(lst_b);
	ft_putendl_fd("ss", 1);
}

t_list	*round_list(t_list *lst)
{
	t_list	*h;

	ft_lstlast(lst)->next = lst;
	h = lst->next;
	lst->next = NULL;
	return h;
}
t_list	*round_a(t_list *lst)
{
	ft_putendl_fd("ra", 1);
	return (round_list(lst));
	
}
t_list	*round_b(t_list *lst)
{
	ft_putendl_fd("rb", 1);
	return (round_list(lst));
	
}
two_list	*round_ab(t_list *lst_a, t_list *lst_b)
{
	two_list	*ab;

	ab->a = round_list(lst_a);
	ab->b = round_list(lst_b);
	ft_putendl_fd("rr", 1);
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
t_list	*rev_round_a(t_list *lst)
{
	ft_putendl_fd("rra", 1);
	return (rev_round(lst));
}
t_list	*rev_round_b(t_list *lst)
{
	ft_putendl_fd("rrb", 1);
	return (rev_round(lst));
}
two_list	*rev_round2(t_list *lst_a, t_list *lst_b)
{
	two_list	*ab;

	ab->a = rev_round(lst_a);
	ab->b = rev_round(lst_b);
	ft_putendl_fd("rrr", 1);
	return (ab);
}

two_list	*move1to2(two_list *ab)
{
	t_list	*a;
	t_list	*b;
	t_list *tmp;

	a = ab->a;
	b = ab->b;
	
	tmp = a;
	a  = a->next;
	ab->a = a;
	ab->b = tmp;
	tmp->next = b;
	ft_putendl_fd("pb", 1);
	return ab;
}
two_list	*move2to1(two_list *ab)
{
	t_list	*a;
	t_list	*b;
	t_list *tmp;

	a = ab->a;
	b = ab->b;
	tmp = b;
	b  = b->next;
	ab->b = b;
	ab->a = tmp;
	tmp->next = a;
	ft_putendl_fd("pa", 1);
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
	return j;
}
int	big_in_b(t_list *a)
{
	int j;
	j= a->index;
	while(a->next != NULL)
	{
		
		if(j < a->next->index)
		{
			
			j = a->next->index;
		}
		a = a->next;
	}
	return j;
}

int	checkswap_b(two_list	*ab)
{
	if(ab->b == NULL)
		return 1;
	if(ab->b->next == NULL)
		return 1;
	if(ab->b->next->index == big_in_b(ab->b))
		return 0;
	return 1;
}
int checkround_b(two_list *ab)
{
	if(ab->b == NULL)
		return 1;
	if(ab->b->next == NULL)
		return 1;
	if(place_of_index(ab->b, big_in_b(ab->b)) > ft_lstsize(ab->b)/2 && ft_lstsize(ab->b) > 2)
		return 0;
	return 1;
}
int checkr_round_b(two_list *ab)
{
	if(ab->b == NULL)
		return 1;
	if(ab->b->next == NULL)
		return 1;
	// if(place_of_index(ab->b, big_in_b(ab->b)) < ft_lstsize(ab->b) && ft_lstsize(ab->b) > 2 && place_of_index(ab->b, big_in_b(ab->b)) != -1 )
	// 	return 0;
	return 1;

}
two_list	*instruction_when(two_list *ab, int index)
{
	if(ab->a->index < index)
	{
		ab = move1to2(ab);

	}
	else if(ab->a->next->index < index)
	{
		if(checkswap_b(ab) == 0)
			swap_ss(ab->a,ab->b);
		else
			swap_a(ab->a);
		ab = instruction_when(ab,index);
	}
	else if(place_of_index(ab->a, index) < ft_lstsize(ab->a)/2 && place_of_index(ab->a, index) != -1)
	{
		if(checkround_b(ab) == 0)
			round_ab(ab->a,ab->b);
		else
			ab->a = round_a(ab->a);
		ab = instruction_when(ab, index);
	}
	else if(place_of_index(ab->a, index) >= ft_lstsize(ab->a)/2 && place_of_index(ab->a,index) != -1)
	{
		if(checkr_round_b(ab) == 0)
			rev_round2(ab->a, ab->b);
		else
			ab->a = rev_round_a(ab->a);
		ab = instruction_when(ab, index);
	}
	return ab;
}

two_list	*instruction_when_rev(two_list *ab, int index)
{
	if(ab->b->index == ab->a->index - 1)
		ab = move2to1(ab);
	else if( ab->b->next->index == index)
	{
		swap_b(ab->b);
		ab = instruction_when_rev(ab, index);
	}
	else if(place_of_index(ab->b, index) > ft_lstsize(ab->b)/2 && place_of_index(ab->b, index) != -1)
	{
		ab->b = round_b(ab->b);
		ab = instruction_when_rev(ab, index);
	}
	else if(place_of_index(ab->b, index) <= ft_lstsize(ab->b)/2)
	{
		ab->b = rev_round_b(ab->b);
		ab = instruction_when_rev(ab, index);
	}
	return ab;
}
