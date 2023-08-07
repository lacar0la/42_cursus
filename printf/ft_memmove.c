/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lahernan <lahernan@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 19:49:27 by lahernan          #+#    #+#             */
/*   Updated: 2023/05/09 19:49:31 by lahernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t count)
{
	unsigned char	*ptrdest;
	unsigned char	*ptrsrc;

	ptrdest = (unsigned char *)dest;
	ptrsrc = (unsigned char *)src;
	if (!dest && !src)
		return (dest);
	if (ptrdest < ptrsrc)
	{
		while ((int)(count--) > 0)
			*ptrdest++ = *ptrsrc++;
	}
	else
	{
		ptrdest += count;
		ptrsrc += count;
		while ((int)(count--) > 0)
			*--ptrdest = *--ptrsrc;
	}
	return (dest);
}
