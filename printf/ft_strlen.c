/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lahernan <lahernan@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 16:27:38 by lahernan          #+#    #+#             */
/*   Updated: 2023/04/18 16:27:42 by lahernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <unistd.h>

size_t	ft_strlen(const char *str)
{
	int	cont;

	cont = 0;
	while (*((char *)str + cont) != '\0')
	{
		cont++;
	}
	return (cont);
}
