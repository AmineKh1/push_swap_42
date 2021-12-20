#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "libft/libft.h"
typedef struct tw_list
{
	struct s_list	*a;
	struct s_list	*b;
}			two_list;
void	index_list(t_list *lst);
int	check_sort(t_list *lst);
void	swap(t_list *lst);
t_list	*round_list(t_list *lst);
t_list	*rev_round(t_list *lst);
int	place_of_index(t_list *l, int index);
two_list	*instruction_when(two_list *ab, int index);
two_list	*move1to2(two_list *ab);
#endif