/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorttab.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hulescur <hulescur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 17:04:09 by hulescur          #+#    #+#             */
/*   Updated: 2026/02/11 15:52:20 by hulescur         ###   ########.fr       */
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
	{
		ft_printf("Failed to index stack\n");
		return (NULL);
	}
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
