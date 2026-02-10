/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorttab.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hulescur <hulescur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 17:04:09 by hulescur          #+#    #+#             */
/*   Updated: 2026/02/10 18:28:58 by hulescur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	tab_size(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

int	*index_tab(char **tab)
{
	int	i;
	int	j;
	int	index;
	int	*sorted;

	sorted = malloc(sizeof(int) * (tab_size(tab)));
	if (!sorted)
		return (NULL);
	i = -1;
	while (tab[++i])
	{
		j = -1;
		index = 1;
		while (tab[++j])
		{
			if (atoi(tab[i]) > atoi(tab[j]))
				index++;
		}
		sorted[i] = index; 
	}
	return (sorted);
}

// int main(int ac, char **av)
// {
// 	if (ac >= 2)
// 	{
// 		int i = 0;
// 		av++;
// 		int *tab = index_tab(av);
// 		while (av[i])
// 		{
// 			ft_printf("%d // index : %d // nombre : %d\n-------\n", i + 1, tab[i], atoi(av[i]));
// 			i++;
// 		}
// 	}
// }