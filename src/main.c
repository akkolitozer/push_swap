/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hulescur <hulescur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 15:26:14 by hulescur          #+#    #+#             */
/*   Updated: 2026/02/10 19:54:45 by hulescur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

//void print_stack(t_stack *a)
//{
//    while (a)
//    {
//        ft_printf("value=%d index=%d\n", a->value, a->index);
//        a = a->next;
//    }
//}


int	main(int ac, char **av)
{
	t_stack	*a = NULL;
	t_stack *b = NULL;
	if (ac < 2)
		return (ft_printf("Error\n Need arguments.\n"));
	else if (ac == 2)
		parse_single_string(&a, av[1]);
	else
		parse_args(&a, ac - 1, av + 1);
	ft_printf("Total operations: %d\n", radix(&a, &b));
	return (0);
}