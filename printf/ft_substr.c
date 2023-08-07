/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lahernan <lahernan@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 17:36:48 by lahernan          #+#    #+#             */
/*   Updated: 2023/04/22 17:36:50 by lahernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdlib.h>

char	*ft_strng(char const *s, unsigned int start, size_t len, char *sln)
{
	size_t	i;
	size_t	j;

	j = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (i >= start && j < len)
		{
			sln[j] = s[i];
			j++;
		}
		i++;
	}
	sln[j] = '\0';
	return (sln);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sln;
	size_t	total_len;

	total_len = ft_strlen(s);
	if (total_len <= start)
		return (ft_strdup(""));
	if ((len + start) > total_len)
		len = total_len - start;
	sln = (char *)malloc(sizeof(char) * len + 1);
	if (!sln)
		return (0);
	sln = ft_strng(s, start, len, sln);
	return (sln);
	free(sln);
}
