/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hulescur <hulescur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 11:41:59 by hulescur          #+#    #+#             */
/*   Updated: 2026/02/01 16:09:50 by hulescur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static	int	countwords(const char *str, char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] && str[i] == c)
			i++;
		if (str[i] && str[i] != c)
		{
			count++;
			while (str[i] && str[i] != c)
				i++;
		}
	}
	return (count);
}

static char	*ft_fill(const char *str, char c)
{
	char		*sc;
	int			j;
	int			count;

	j = -1;
	count = 0;
	while (str[count] && str[count] != c)
		count++;
	sc = malloc(sizeof(char) * (count + 1));
	if (!sc)
		return (NULL);
	while (str[++j] && str[j] != c)
		sc[j] = str[j];
	sc[j] = 0;
	return (sc);
}

char	**ft_split(const char *str, char c)
{
	char		**strs;
	int			i;
	int			j;

	i = 0;
	j = 0;
	if (!str)
		return (NULL);
	strs = malloc((countwords(str, c) + 1) * sizeof(char *));
	if (!strs)
		return (NULL);
	while (str[i])
	{
		while (str[i] && str[i] == c)
			i++;
		if (str[i] && str[i] != c)
		{
			strs[j++] = ft_fill(str + i, c);
			while (str[i] && str[i] != c)
				i++;
		}
	}
	strs[j] = 0;
	return (strs);
}
