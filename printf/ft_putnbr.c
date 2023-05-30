/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lahernan <lahernan@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 11:37:27 by lahernan          #+#    #+#             */
/*   Updated: 2023/05/25 11:37:29 by lahernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"
#include <stdlib.h>
#include <unistd.h>

int	ft_putnbr(int n)
{
	char	*sln;
	int		i;

	sln = ft_itoa(n);
	i = ft_putstr(sln);
	free(sln);
	return (i);
}
