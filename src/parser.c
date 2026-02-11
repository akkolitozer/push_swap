/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hulescur <hulescur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 15:26:05 by hulescur          #+#    #+#             */
/*   Updated: 2026/02/11 15:51:30 by hulescur         ###   ########.fr       */
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

int	parse_args(t_stack **a, t_stack **b, int ac, char **av)
{
	int	i;
	int	ret;
	int	*indexer;

	ret = 0;
	indexer = index_tab(av);
	i = -1;
	while (++i < ac)
	{
		if (!valid_nb(av[i]))
			return (ft_printf("Error\n Invalid numbers.\n"));
		append_stack(a, new_node(ft_atoi(av[i]), indexer[i]));
	}
	if (ac == 2 || ac == 5 || ac == 3)
		ret += hardc(a, b, ac);
	free(indexer);
	return (ret);
}

int	parse_single_string(t_stack **a, t_stack **b, char *str)
{
	char	**numbers;
	int		i;
	int		*indexer;
	int		ret;

	ret = 0;
	numbers = ft_split(str);
	if (!numbers)
		return (ft_printf("Error\n Failed to split string.\n"));
	indexer = index_tab(numbers);
	i = -1;
	while (numbers[++i])
	{
		if (!valid_nb(numbers[i]))
			return (ft_printf("Error\n Invalid numbers.\n"));
		append_stack(a, new_node(ft_atoi(numbers[i]), indexer[i]));
	}
	if (countwords(str) == 2 || countwords(str) == 3 || countwords(str) == 5)
		ret += hardc(a, b, countwords(str));
	free(indexer);
	free_tab(numbers);
	return (ret);
}
