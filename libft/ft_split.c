/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hulescur <hulescur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 11:41:59 by hulescur          #+#    #+#             */
/*   Updated: 2026/02/11 15:31:17 by hulescur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	is_space(char c)
{
	if ((c >= 9 && c <= 13) || c == ' ')
		return (1);
	return (0);
}

int	countwords(const char *str)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] && is_space(str[i]))
			i++;
		if (str[i] && !is_space(str[i]))
		{
			count++;
			while (str[i] && !is_space(str[i]))
				i++;
		}
	}
	return (count);
}

static char	*ft_fill(const char *str)
{
	char		*sc;
	int			j;
	int			count;

	j = -1;
	count = 0;
	while (str[count] && !is_space(str[count]))
		count++;
	sc = malloc(sizeof(char) * (count + 1));
	if (!sc)
		return (NULL);
	while (str[++j] && !is_space(str[j]))
		sc[j] = str[j];
	sc[j] = 0;
	return (sc);
}

char	**ft_split(const char *str)
{
	char		**strs;
	int			i;
	int			j;

	i = 0;
	j = 0;
	if (!str)
		return (NULL);
	strs = malloc((countwords(str) + 1) * sizeof(char *));
	if (!strs)
		return (NULL);
	while (str[i])
	{
		while (str[i] && is_space(str[i]))
			i++;
		if (str[i] && !is_space(str[i]))
		{
			strs[j++] = ft_fill(str + i);
			while (str[i] && !is_space(str[i]))
				i++;
		}
	}
	strs[j] = 0;
	return (strs);
}
