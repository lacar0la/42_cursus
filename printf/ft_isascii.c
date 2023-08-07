/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lahernan <lahernan@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 15:22:53 by lahernan          #+#    #+#             */
/*   Updated: 2023/04/18 15:22:56 by lahernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

int	ft_isascii(int c)
{
	if (c == '\0')
	{
		return (1);
	}
	else
	{
		if (!(c >= 0 && c <= 127))
		{
			return (0);
		}
	}
	return (1);
}
