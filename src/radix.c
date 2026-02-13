/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hulescur <hulescur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 19:24:47 by hulescur          #+#    #+#             */
/*   Updated: 2026/02/13 14:38:54 by hulescur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	more_r(t_stack *a, int i, int bit)
{
	int	j;

	j = 0;
	while (j < i)
	{
		if (((a->index) >> bit & 1) == 1)
			return (1);
		a = a->next;
		j++;
	}
	return (0);
}

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

int	good_order(t_stack *a)
{
	t_stack	*temp;
	int		i;

	i = 0;
	temp = a;
	while (temp)
	{
		if (temp->index < i)
			return (0);
		i = temp->index;
		temp = temp->next;
	}
	return (1);
}

void	radix(t_stack **a, t_stack **b)
{
	int	i;
	int	bit;
	int	size;
	int	bits;

	bit = -1;
	size = stack_size(*a);
	if (size == 1)
		return ;
	bits = max_bits(size);
	while (++bit <= bits)
	{
		if (good_order(*a))
			return ;
		i = -1;
		while (++i < size && more_r(*a, size - i, bit))
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
