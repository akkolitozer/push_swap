/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hulescur <hulescur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 15:26:14 by hulescur          #+#    #+#             */
/*   Updated: 2026/02/13 17:25:11 by hulescur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	print_stack(t_stack *a)
{
	if (!a)
		ft_printf("stack empty\n");
	while (a)
	{
		ft_printf("value=%d index=%d\n", a->value, a->index);
		a = a->next;
	}
}

int	main2(t_stack *a, t_stack *b, int ac, char **av)
{
	if (ac < 2)
		return (ft_printf("Error\n Need arguments.\n"));
	else if (ac == 2)
	{
		if (parse_single_string(&a, &b, av[1]))
		{
			free_stacks(a, b);
			return (0);
		}
	}
	else
	{
		if (parse_args(&a, &b, ac - 1, av + 1))
		{
			free_stacks(a, b);
			return (0);
		}
	}
	radix(&a, &b);
	free_stack(a);
	free_stack(b);
	return (0);
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	return (main2(a, b, ac, av));
}
