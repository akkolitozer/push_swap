/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hulescur <hulescur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 19:24:47 by hulescur          #+#    #+#             */
/*   Updated: 2026/02/10 19:57:58 by hulescur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	stack_size(t_stack *stack)
{
	int	size;

	size = 0;
	while (stack)
	{
		size++;
		stack = stack->next;
	}
	return (size);
}

int	max_bits(int n)
{
	int	bit;
	
	bit = 0;
	while ((n - 1) >> bit)
		bit++;
	return (bit);
}

void	radix(t_stack **a, t_stack **b)
{
	int	i;
	int	bit;
	int size;
	int bits;

	bit = -1;
	size = stack_size(*a);
	bits = max_bits(size);
	while (++bit < bits)
	{
		i = -1;
		while (++i < size)
		{
			if ((((*a)->index) >> bit & 1) == 1)
				rab(a, 1);
			else
				pab(a, b, 0);
		}
		while (*b)
			pab(b, a, 1);
	}
}
