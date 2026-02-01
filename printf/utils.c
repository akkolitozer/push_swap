/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hulescur <hulescur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 13:44:56 by hulescur          #+#    #+#             */
/*   Updated: 2026/02/01 16:29:41 by hulescur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_putnbr(int n)
{
	int		size;

	size = 0;
	if (n == -2147483648)
		return (ft_putstr("-2147483648"));
	if (n < 0)
	{
		size += ft_putchar('-');
		n *= -1;
	}
	if (n >= 10)
		size += ft_putnbr(n / 10);
	size += ft_putchar((n % 10) + '0');
	return (size);
}

int	ft_putnbr_unsigned(unsigned int n)
{
	int		size;

	size = 0;
	if (n >= 10)
		size += ft_putnbr_unsigned(n / 10);
	size += ft_putchar((n % 10) + '0');
	return (size);
}

int	ft_putnbr_base(unsigned long long nbr, char *base)
{
	int					size;
	unsigned long long	base_len;

	size = 0;
	base_len = 0;
	while (base[base_len])
		base_len++;
	if (nbr >= base_len)
		size += ft_putnbr_base(nbr / base_len, base);
	size += ft_putchar(base[nbr % base_len]);
	return (size);
}
