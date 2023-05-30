/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lahernan <lahernan@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 15:49:45 by lahernan          #+#    #+#             */
/*   Updated: 2023/05/25 15:49:48 by lahernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"
#include <stdlib.h>
#include <unistd.h>

int	ft_putnbr_unsigned(unsigned int n)
{
	char	*sln;
	int		i;

	sln = ft_itoa_unsigned(n);
	i = ft_putstr(sln);
	free(sln);
	return (i);
}
