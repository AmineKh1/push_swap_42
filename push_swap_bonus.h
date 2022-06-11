/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhouya <akhouya@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 11:49:57 by akhouya           #+#    #+#             */
/*   Updated: 2022/06/11 12:12:55 by akhouya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H
# include "push_swap.h"

t_list      *rev_round_a_check(t_list *lst);
t_stacks	*round_ab_check(t_stacks *ab);
t_list  	*round_b_check(t_list *lst);
t_list	    *round_a_check(t_list *lst);
t_stacks	*swap_ss_check(t_stacks *ab);
t_list  	*swap_b_check(t_list *lst);
t_list  	*swap_a_check(t_list *lst);
t_stacks	*move2to1_check(t_stacks *ab);
t_stacks	*move1to2_check(t_stacks *ab);
t_stacks	*rev_round2_check(t_stacks *ab);
t_list	    *rev_round_b_check(t_list *lst);
char	    *get_next_line(int fd);
#endif