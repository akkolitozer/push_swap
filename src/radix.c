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

//int	more_p(t_stack *a, int i, int bit)
//{
//	while (a && a->index != i)
//		a = a->next;
//	while (a)
//	{
//		if (((a->index) >> bit & 1) == 0)
//			return (1);
//		a = a->next;
//	}
//	return (0);
//}

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

int	radix(t_stack **a, t_stack **b)
{
	int	i;
	int	bit;
	int size;
	int bits;
	int	count = 0;

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
			count++;
		}
		while (*b)
		{
			pab(b, a, 1);
			count++;
		}
	}
	return (count);
}
