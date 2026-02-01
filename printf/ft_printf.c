/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hulescur <hulescur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 13:44:56 by hulescur          #+#    #+#             */
/*   Updated: 2026/02/01 16:25:51 by hulescur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	handle_format(va_list *args, char format)
{
	int	size;

	size = 0;
	if (format == 'c')
		size += ft_putchar(va_arg(*args, int));
	else if (format == 's')
		size += ft_putstr(va_arg(*args, char *));
	else if (format == 'd' || format == 'i')
		size += ft_putnbr(va_arg(*args, int));
	else if (format == 'u')
		size += ft_putnbr_unsigned(va_arg(*args, unsigned int));
	else if (format == 'x')
		size += ft_putnbr_base(va_arg(*args, unsigned int), "0123456789abcdef");
	else if (format == 'X')
		size += ft_putnbr_base(va_arg(*args, unsigned int), "0123456789ABCDEF");
	else if (format == 'p')
		size += ft_putptr(va_arg(*args, void *), "0123456789abcdef");
	else if (format == '%')
		size += ft_putchar('%');
	return (size);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		size;

	size = 0;
	if (!str)
		return (-1);
	va_start(args, str);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			if (*str)
				size += handle_format(&args, *str);
		}
		else
		size += ft_putchar(*str);
		if (*str)
		str++;
	}
	va_end(args);
	if (size < 0)
		return (-1);
	else
		return (size);
}

// int	main()
// {
// 	printf(" /// printf : %d\n",
// 		 printf("ouais %s %d %p %q %%% ", "chut", 16, 0));
// 	printf(" /// ft_printf : %d\n",
// 		 ft_printf("ouais %s %d %p %q %%% ", "chut", 16, 0));
// 	return (0);
// }