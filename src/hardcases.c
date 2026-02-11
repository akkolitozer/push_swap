/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hardcases.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hulescur <hulescur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 13:57:03 by hulescur          #+#    #+#             */
/*   Updated: 2026/02/11 15:52:55 by hulescur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	get_pos_lower(t_stack **stack)
{
	t_stack	*temp;
	int		i;
	int		pos;
	int		lower;

	temp = *stack;
	i = 0;
	lower = temp->index;
	while (temp)
	{
		if (temp->index < lower)
		{
			lower = temp->index;
			pos = i;
		}
		temp = temp->next;
		i++;
	}
	return (pos);
}

void	lower_on_top(t_stack **stack, int pos)
{
	if (pos > 2)
	{
		while (pos++ < 5)
			rrab(stack, 1);
	}
	else if (pos < 3)
	{
		while (pos-- > 0)
			rab(stack, 1);
	}
}

void	sort_three(t_stack **stack)
{
	int	first;
	int	second;
	int	third;

	first = (*stack)->index;
	second = (*stack)->next->index;
	third = (*stack)->next->next->index;
	if (first > second && first > third && second > third)
	{
		sab(stack, 1);
		rrab(stack, 1);
	}
	else if (first > second && !(first > third))
		sab(stack, 1);
	else if (first > second && first > third)
		rab(stack, 1);
	else if (!(first > second) && first > third)
		rrab(stack, 1);
	else if (!(first > second || first > third) && second > third)
	{
		sab(stack, 1);
		rab(stack, 1);
	}
}

void	sort_five(t_stack **a, t_stack **b)
{
	lower_on_top(a, get_pos_lower(a));
	pab(a, b, 0);
	lower_on_top(a, get_pos_lower(a));
	pab(a, b, 0);
	sort_three(a);
	pab(b, a, 1);
	pab(b, a, 1);
}

int	hardc(t_stack **a, t_stack **b, int i)
{
	int	first;
	int	second;

	if (i == 2)
	{
		first = (*a)->index;
		second = (*a)->next->index;
		if (first > second)
			sab(a, 1);
	}
	else if (i == 3)
		sort_three(a);
	else if (i == 5)
		sort_five(a, b);
	return (1);
}
