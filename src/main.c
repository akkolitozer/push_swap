/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hulescur <hulescur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 15:26:14 by hulescur          #+#    #+#             */
/*   Updated: 2026/02/17 19:46:47 by hulescur         ###   ########.fr       */
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
	int	h;

	h = 0;
	if (ac < 2)
		return (ft_printf("Error\n Need arguments.\n"));
	else if (ac == 2)
	{
		h = parse_single_string(&a, &b, av[1]);
		if (h > 0)
			return (0);
	}
	else
	{
		h = parse_args(&a, &b, ac - 1, av + 1);
		if (h > 0)
			return (0);
	}
	if (!h)
		radix(&a, &b);
	free_stacks(a, b);
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
