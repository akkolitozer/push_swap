/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hulescur <hulescur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 11:50:07 by hulescur          #+#    #+#             */
/*   Updated: 2026/02/13 14:39:17 by hulescur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include "libft.h"
# include "push_swap.h"
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

int			ft_atoi(const char *str);
int			ft_putchar(char c);
int			ft_putstr(char *s);
char		**ft_split(char const *s);
char		*ft_strdup(const char *s1);
int			countwords(const char *str);
size_t		ft_strlen(const char *str);

#endif