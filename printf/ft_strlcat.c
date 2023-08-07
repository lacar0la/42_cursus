/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lahernan <lahernan@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 17:10:47 by lahernan          #+#    #+#             */
/*   Updated: 2023/03/26 17:10:50 by lahernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int	len(char *dest)
{
	size_t	i;

	i = 0;
	while (dest[i] != '\0')
	{
		i++;
	}
	return (i);
}

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	len_dest;
	size_t	len_src;

	len_dest = len(dest);
	len_src = len((char *)src);
	i = 0;
	j = len_dest;
	if (len_dest < (size - 1) && size > 0)
	{
		while (src[i] != '\0' && (len_dest + i) < (size - 1))
		{
			dest[j] = src[i];
			i++;
			j++;
		}
		dest[j] = '\0';
	}
	if (len_dest >= size)
	{
		len_dest = size;
	}
	return (len_src + len_dest);
}
