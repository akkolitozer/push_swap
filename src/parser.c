/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hulescur <hulescur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 15:26:05 by hulescur          #+#    #+#             */
/*   Updated: 2026/02/10 18:32:57 by hulescur         ###   ########.fr       */
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

int	parse_args(t_stack **a, int ac, char **av)
{
	int	i;
	int	*indexer;

	indexer = index_tab(av);
	i = -1;
	while (++i < ac)
	{
		if (!valid_nb(av[i]))
			return(ft_printf("Error\n Invalid number: %s\n", av[i]));
		append_stack(a, new_node(ft_atoi(av[i]), indexer[i]));
	}
	return (0);
}

int parse_single_string(t_stack **a, char *str)
{
	char	**numbers;
	int 	i;
	int		*indexer;

	numbers = ft_split(str, ' ');
	if (!numbers)
		return (ft_printf("Error\n Failed to split string.\n"));
	indexer = index_tab(numbers);
	if (!indexer)
		return (ft_printf("Error\n Failed to index string.\n"));
	i = -1;
	while (numbers[++i])
	{
		if (!valid_nb(numbers[i]))
		{
			free_tab(numbers);
			return(ft_printf("Error\n Invalid number\n"));
		}
		append_stack(a, new_node(ft_atoi(numbers[i]), indexer[i]));
	}
	free_tab(numbers);
	return (0);
}
