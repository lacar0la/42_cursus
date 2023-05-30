/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putdec.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lahernan <lahernan@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 19:17:34 by lahernan          #+#    #+#             */
/*   Updated: 2023/05/24 19:17:36 by lahernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"
#include <stdio.h>
#include <unistd.h>

int	ft_putdec(unsigned long dec)
{
	int	i;

	i = 2;
	write(1, "0x", 2);
	i += ft_puthex(dec, 0);
	return (i);
}
