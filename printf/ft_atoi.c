/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lahernan <lahernan@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 15:17:20 by lahernan          #+#    #+#             */
/*   Updated: 2023/03/28 15:17:23 by lahernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <unistd.h>

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	output;

	i = 1;
	sign = 0;
	output = 0;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	while (*str == 45 || *str == 43)
	{
		if (*str == 45)
			i = -1;
		str++;
		sign++;
	}
	while ((*str >= 48 && *str <= 57))
	{
		output = output * 10 + (*str - 48);
		str++;
	}
	if (sign > 1)
		return (0);
	return (output * i);
}
