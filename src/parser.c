/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hulescur <hulescur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 15:26:05 by hulescur          #+#    #+#             */
/*   Updated: 2026/02/20 17:16:04 by hulescur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	checkdup(t_stack *stack)
{
	t_stack	*temp;
	t_stack	*temp2;

	temp = stack;
	while (temp)
	{
		temp2 = temp->next;
		while (temp2)
		{
			if (temp->value == temp2->value)
				return (1);
			temp2 = temp2->next;
		}
		temp = temp->next;
	}
	return (0);
}

void	init_vars(int *var1, int *var2)
{
	*var1 = 0;
	*var2 = 0;
}

int	parse_args(t_stack **a, t_stack **b, int ac, char **av)
{
	int	*indexer;
	int	i;
	int	ret;
	int	error;

	init_vars(&ret, &error);
	indexer = index_tab(av);
	i = -1;
	while (++i < ac)
	{
		append_stack(a, new_node(ft_atoi(av[i], &error), indexer[i]));
		if (error)
			return (error_exit(*a, *b, NULL, indexer));
	}
	if (checkdup(*a))
		return (error_exit(*a, *b, NULL, indexer));
	if (ac == 2 || ac == 5 || ac == 3)
		ret += hardc(a, b, ac);
	free(indexer);
	return (ret);
}

int	parse_single_string(t_stack **a, t_stack **b, char *str)
{
	char	**numbers;
	int		*indexer;
	int		i;
	int		ret;
	int		error;

	init_vars(&ret, &error);
	numbers = ft_split(str);
	if (!numbers)
		return (ft_printf("Error\n"));
	indexer = index_tab(numbers);
	i = -1;
	while (numbers[++i])
	{
		append_stack(a, new_node(ft_atoi(numbers[i], &error), indexer[i]));
		if (error)
			return (error_exit(*a, *b, numbers, indexer));
	}
	if (checkdup(*a))
		return (error_exit(*a, *b, numbers, indexer));
	if (countwords(str) == 2 || countwords(str) == 3 || countwords(str) == 5)
		ret += hardc(a, b, countwords(str));
	free(indexer);
	free_tab(numbers);
	return (ret);
}
