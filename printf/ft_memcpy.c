/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lahernan <lahernan@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 17:38:12 by lahernan          #+#    #+#             */
/*   Updated: 2023/04/21 17:38:13 by lahernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

// this function copy a block of memory, copies the values 
void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (dest == NULL)
		return (NULL);
	while (n > 0)
	{
		*(char *)(dest + i) = *(char *)(src + i);
		i++;
		n--;
	}
	return (dest);
}
