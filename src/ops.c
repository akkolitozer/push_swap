/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hulescur <hulescur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 18:41:09 by hulescur          #+#    #+#             */
/*   Updated: 2026/02/10 19:13:57 by hulescur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	pab(t_stack **one, t_stack **two, int is_a)
{
	t_stack	*temp;

	if (!*one)
		return ;
	temp = *one;
	*one = (*one)->next;
	temp->next = *two;
	*two = temp;
	if (is_a)
		ft_printf("pa\n");
	else
		ft_printf("pb\n");
}

void	sab(t_stack **stack, int is_a)
{
	t_stack *second;
	t_stack *first;

	if (!*stack || !(*stack)->next)
		return ;
	first = *stack;
	second = (*stack)->next;
	first->next = second->next;
	second->next = first;
	*stack = second;
	if (is_a)
		ft_printf("sa\n");
	else
		ft_printf("sb\n");
}

void	rab(t_stack **stack, int is_a)
{
	t_stack *first;
	t_stack *last;
	
	if (!stack)
		return ;
	first = *stack;
	last = *stack;
	while (last->next)
		last = last->next;
	*stack = first->next;
	first ->next = NULL;
	last->next = first;
	if (is_a)
		ft_printf("ra\n");
	else
		ft_printf("rb\n");
}

void	rrab(t_stack **stack, int is_a)
{
	t_stack	*first;
	t_stack *last;
	
	if (!stack)
		return ;
	last = *stack;
	while ((last->next)->next)
		last = last->next;
	first = last->next;
	last->next = NULL;
	first->next = *stack;
	*stack = first;
	if (is_a)
		ft_printf("rra\n");
	else
		ft_printf("rrb\n");
}
