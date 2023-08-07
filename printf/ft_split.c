/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lahernan <lahernan@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 16:34:31 by lahernan          #+#    #+#             */
/*   Updated: 2023/05/02 16:34:33 by lahernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

static int	count(const char *s, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < (int)ft_strlen(s))
	{
		if (s[i++] != c && (s[i] == c || s[i] == '\0'))
		{
			j++;
		}
	}
	return (j);
}

static char	*ft_strsplit(const char *s, char c, char **text)
{
	size_t	len;
	size_t	n;

	n = 0;
	while (*s)
	{
		if (*s != c)
		{
			len = 0;
			while (*s && (*s != c))
			{
				len++;
				s++;
			}
			text[n] = ft_substr((s - len), 0, len);
			n++;
		}
		else
			s++;
	}
	text[n] = 0;
	return (*text);
}

char	**ft_split(const char *s, char c)
{
	char	**text;

	text = malloc(sizeof(char *) * (count(s, c) + 1));
	if (!text)
		return (0);
	ft_strsplit(s, c, text);
	return (text);
}
