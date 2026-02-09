/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hulescur <hulescur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 15:26:14 by hulescur          #+#    #+#             */
/*   Updated: 2026/02/09 16:04:10 by hulescur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*a = NULL;
	if (ac < 2)
		return (ft_printf("Error\n Need arguments.\n"));
	else if (ac == 2)
		parse_single_string(&a, av[1]);
	else
		parse_args(&a, ac - 1, av + 1);
	return (0);
}