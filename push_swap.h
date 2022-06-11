/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhouya <akhouya@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 16:31:53 by akhouya           #+#    #+#             */
/*   Updated: 2022/06/11 12:11:56 by akhouya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "libft/libft.h"

typedef struct s_stacks
{
	struct s_list	*a;
	struct s_list	*b;
}			t_stacks;
typedef struct s_pushswap
{
	char	**s;
	t_list	*list_nbr;
	t_list	*h;
	int		j;
	int		i;
	int		q;
	int		min_r;
	int		max_r;
	int		midle;
}			t_pushswap;
void		index_list(t_list *lst);
int			check_sort(t_list *lst);
t_list		*swap(t_list *lst);
t_list		*swap_a(t_list *lst);
t_list		*swap_b(t_list *lst);
t_stacks	*swap_ss(t_stacks *ab);
t_list		*round_list(t_list *lst);
t_list		*rev_round(t_list *lst);
t_list		*rev_round_b(t_list *lst);
t_stacks	*rev_round2(t_stacks *ab);
t_stacks	*move1to2(t_stacks *ab);
t_stacks	*move2to1(t_stacks *ab);
int			count(int content, t_list *head);
void		index_list(t_list *lst);
int			place_of_index(t_list *l, int max_r, int min_r);
int			place_of_indexx(t_list *l, int index);
int			place_of_inde(t_list *l, int max_r, int min_r);
int			checkswap_b(t_stacks *ab);
int			checkround_b(t_stacks *ab);
int			checkr_round_b(t_stacks *ab);
t_list		*round_a(t_list *lst);
t_list		*round_b(t_list *lst);
t_stacks	*sort_five(t_stacks *ab);
t_stacks	*round_ab(t_stacks *ab);
t_list		*rev_round_a(t_list *lst);
t_stacks	*instruction_when(t_stacks *ab, int index);
t_stacks	*move1to2(t_stacks *ab);
int			midle_index(t_list *a);
t_stacks	*instruction_when_rev(t_stacks *ab, int index, int q);
t_stacks	*move2to1(t_stacks *ab);
int			big_in_b(t_list *a);
void		printlis(t_stacks *f);
t_stacks	*push_to_b(t_stacks *ab, t_pushswap *p_s, int j);
t_stacks	*round_ab(t_stacks *ab);
int			place_of_inde(t_list *l, int max_r, int min_r);
t_stacks	*push_to_a(t_stacks *ab, int max_r);
t_list		*sort_tree(t_list *a);
int			place_of_index(t_list *l, int max_r, int min_r);
void		handle_errors(int argc, char **argv, t_pushswap *p_s);
void		init_var(t_pushswap *p_s, t_stacks *f);
void		algo_tob(t_pushswap *p_s, t_stacks *f);
void		algo_toa(t_pushswap *p_s, t_stacks *f);
void		condition_addinglist(t_pushswap *p_s);
int			strisdigit(char *str);
void		printlis(t_stacks *f);
char		*ft_strjoin_free(char *s, char c);
char		*get_next_line(int fd);
int			check_list(t_list *lst);
#endif