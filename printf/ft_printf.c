/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lahernan <lahernan@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 11:54:11 by lahernan          #+#    #+#             */
/*   Updated: 2023/05/23 11:54:13 by lahernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"
#include <stdarg.h>
#include <stdio.h>

int	ft_conversion(va_list ap, const char str, int count)
{
	if (str == 'c')
		count += ft_putchar(va_arg(ap, int));
	else if (str == 's')
		count += ft_putstr(va_arg(ap, char *));
	else if (str == 'p')
		count += ft_putdec(va_arg(ap, unsigned long));
	else if (str == 'd' || str == 'i')
		count += ft_putnbr(va_arg(ap, int));
	else if (str == 'u')
		count += ft_putnbr_unsigned(va_arg(ap, unsigned int));
	else if (str == 'x')
		count += ft_puthex(va_arg(ap, unsigned int), 0);
	else if (str == 'X')
		count += ft_puthex(va_arg(ap, unsigned int), 1);
	else if (str == '%')
		count += ft_putchar('%');
	return (count);
}

int	ft_printf(const char *str, ...)
{
	int		sln;
	int		i;
	va_list	ap;
	int		count;

	va_start(ap, str);
	sln = 0;
	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			sln += ft_conversion(ap, str[i + 1], count);
			i++;
		}
		else
		{
			sln += ft_putchar(str[i]);
		}
		i++;
	}
	va_end(ap);
	return (sln);
}
