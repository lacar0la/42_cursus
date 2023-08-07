/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lahernan <lahernan@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 18:11:52 by lahernan          #+#    #+#             */
/*   Updated: 2023/04/28 18:11:53 by lahernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

static int	ft_charisin(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*sln;
	size_t	start;
	size_t	i;
	size_t	end;

	start = 0;
	end = ft_strlen(s1);
	while (s1[start] != '\0' && (ft_charisin(s1[start], set) == 1))
	{
		start++;
	}
	while (end > start && (ft_charisin(s1[end - 1], set) == 1))
	{
		end--;
	}
	sln = (char *)malloc(sizeof(char) * (end - start + 1));
	if (!sln)
		return (NULL);
	i = 0;
	while (start < end)
		sln[i++] = s1[start++];
	sln[i] = 0;
	return (sln);
}
