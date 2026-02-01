/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hulescur <hulescur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 15:26:14 by hulescur          #+#    #+#             */
/*   Updated: 2026/02/01 16:03:46 by hulescur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int ac, char **av)
{
	if (ac < 2)
		return (ft_putstr("Error\n Not enough arguments.\n"));
	parse_single_string(av[1]);
	// else if (ac == 2)
	// 	parse_single_string(av[1]);
	// else
	// 	parse_args(ac - 1, av + 1);
	return (0);
}