/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lahernan <lahernan@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 13:00:19 by lahernan          #+#    #+#             */
/*   Updated: 2023/04/19 13:00:23 by lahernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <string.h>
#include <unistd.h>

char	*ft_strrchr(const char *str, int c)
{
	char	*result;

	result = NULL;
	while (*str != '\0')
	{
		if (*str == (char)c)
		{
			result = (char *)str;
		}
		str++;
	}
	if ((char)c == '\0')
	{
		while (*str != (char)c)
		{
			str++;
		}
		result = (char *)str;
	}
	return (result);
}
