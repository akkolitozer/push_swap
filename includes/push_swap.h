/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hulescur <hulescur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 15:26:35 by hulescur          #+#    #+#             */
/*   Updated: 2026/02/09 16:06:36 by hulescur         ###   ########.fr       */
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
	struct s_stack	*next;
}					t_stack;

typedef struct s_tab
{
	int	index;
	int	value;
}					t_tab;

int		parse_single_string(t_stack **a, char *str);
int		parse_args(t_stack **a, int ac, char **av);
void	free_tab(char **tab);
void	append_stack(t_stack **stack, t_stack *new);
t_stack	*new_node(int value);

#endif