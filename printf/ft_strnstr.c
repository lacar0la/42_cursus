/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lahernan <lahernan@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 13:05:43 by lahernan          #+#    #+#             */
/*   Updated: 2023/04/21 13:05:45 by lahernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	ft_strlen(const char *str)
{
	int	cont;

	cont = 0;
	while (*(str + cont) != '\0')
	{
		cont++;
	}
	return (cont);
}

char	*ft_strnstr(const char *text, const char *to_find, size_t len)
{
	size_t	i;
	size_t	x;
	size_t	lon;
	int		flag;

	flag = 0;
	i = 0;
	lon = ft_strlen(to_find);
	if (to_find[i] == '\0')
		return ((char *)text);
	while (text[i] != '\0' && len > i)
	{
		flag = 0;
		x = 0;
		while (text[i + x] == to_find[x] && x < lon && x + i < len && flag == 0)
			x++;
		if (x > 0)
			flag = 1;
		if (to_find[x] == '\0' && flag == 1)
			return ((char *)&text[i]);
		i++;
	}
	return (NULL);
}
