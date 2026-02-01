/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hulescur <hulescur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 15:26:05 by hulescur          #+#    #+#             */
/*   Updated: 2026/02/01 16:41:28 by hulescur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	valid_nb(const char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
		i++;
	if (str[i] != '\0')
		return (0);
	return (1);
}

int parse_single_string(char *str)
{
	char **numbers;
	int i;
	// int nb;

	numbers = ft_split(str, ' ');
	if (!numbers)
		return (ft_printf("Error\n Failed to split string.\n"));
	i = -1;
	while (numbers[++i])
	{
		if (!valid_nb(numbers[i]))
		{
			ft_printf("Error\n Invalid number: %s\n", numbers[i]);
			free_tab(numbers);
			return (1);
		}
	}
	return (0);
}
