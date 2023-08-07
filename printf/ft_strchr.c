/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lahernan <lahernan@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 11:14:47 by lahernan          #+#    #+#             */
/*   Updated: 2023/04/19 11:14:49 by lahernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdio.h>
#include <string.h>

char	*ft_strchr(const char *str, int c)
{
	int	i;

	i = 0;
	if (*str == '\0')
		return ((char *)str);
	while (*(str + i) != '\0')
	{
		if (*(str + i) == (char)c)
		{
			return ((char *)(str + i));
		}
		i++;
	}
	if (*(str + i) == (char)c)
		return ((char *)(str + i));
	return (NULL);
}
