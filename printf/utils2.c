/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hulescur <hulescur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 13:44:57 by hulescur          #+#    #+#             */
/*   Updated: 2026/02/01 16:25:59 by hulescur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_putptr(void *ptr, char *base)
{
	int							size;
	unsigned long long			address;

	if (ptr == NULL)
		return (ft_putstr("(nil)"));
	address = (unsigned long long) ptr;
	size = 0;
	size += ft_putstr("0x");
	size += ft_putnbr_base(address, base);
	return (size);
}
