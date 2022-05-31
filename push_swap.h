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
	int				size;
	int				count;
}			two_list;
void	index_list(t_list *lst);
int	check_sort(t_list *lst);
t_list	*swap(t_list *lst);
t_list	*round_list(t_list *lst);
t_list	*rev_round(t_list *lst);
two_list	*instruction_when(two_list *ab, int index);
two_list	*move1to2(two_list *ab);
int	midle_index(t_list *a);
two_list	*instruction_when_rev(two_list *ab, int index, int j, int h);
two_list	*move2to1(two_list *ab);
int	big_in_b(t_list *a);
void	printlis(two_list *f);
two_list	*push_to_b(two_list *ab, int min_r, int max_r, int midle, int j);
two_list	*round_ab(two_list *ab);
int	place_of_inde(t_list *l, int max_r, int min_r);
two_list	*push_to_a(two_list *ab, int max_r);
t_list	*sort_tree(t_list *a);
int	place_of_index(t_list *l, int max_r, int min_r);
#endif