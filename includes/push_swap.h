/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hulescur <hulescur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 15:26:35 by hulescur          #+#    #+#             */
/*   Updated: 2026/02/10 19:49:29 by hulescur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include "ft_printf.h"
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int				value;
	int 			index;
	struct s_stack	*next;
}					t_stack;

int		parse_single_string(t_stack **a, char *str);
int		parse_args(t_stack **a, int ac, char **av);
void	free_tab(char **tab);
void	append_stack(t_stack **stack, t_stack *new);
t_stack	*new_node(int value, int index);
int		*index_tab(char **tab);
void	pab(t_stack **one, t_stack **two, int is_a);
void	sab(t_stack **stack, int is_a);
void	rab(t_stack **stack, int is_a);
void	rrab(t_stack **stack, int is_a);
void	radix(t_stack **a, t_stack **b);

#endif