/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lahernan <lahernan@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 11:35:50 by lahernan          #+#    #+#             */
/*   Updated: 2023/05/25 11:35:52 by lahernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"
#include <unistd.h>

int	ft_puthex(unsigned long long num, int capital)
{
	unsigned long long	i;

	i = 0;
	if (num >= 16)
		i += ft_puthex(num / 16, capital);
	if (capital == 0)
		ft_putchar("0123456789abcdef"[num % 16]);
	else
		ft_putchar("0123456789ABCDEF"[num % 16]);
	i++;
	return (i);
}
