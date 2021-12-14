#include "push_swap.h"

int main(int argc,char *argv[])
{
	int i;
	t_list *list_nbr;
	t_list *h;

	i = 1;
	list_nbr = ft_lstnew(ft_atoi(argv[i++]));
	while(--argc > 1)
	{
		h = ft_lstnew(ft_atoi(argv[i++]));
		ft_lstadd_back(&list_nbr, h);
	}

	while(list_nbr != NULL)
	{
		ft_putnbr_fd(list_nbr->content, 1);
		ft_putstr_fd("\n",1);
		list_nbr = list_nbr->next;
	}

}