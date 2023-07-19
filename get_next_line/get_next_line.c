/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lahernan <lahernan@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 12:36:19 by lahernan          #+#    #+#             */
/*   Updated: 2023/05/31 12:36:21 by lahernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"
#include <stdio.h>
#include <unistd.h>

// void	ft_leaks(void)
// {
// 	system("leaks -q a.out");
// }

char	*ft_freedom(char *saved, char *buffer)
{
	char	*sec;

	if (!saved)
	{
		saved = malloc(1);
		saved[0] = 0;
	}
	sec = ft_strjoin(saved, buffer);
	free(saved);
	saved = NULL;
	return (sec);
}

char	*ft_find_next(char *text)
{
	int		i;
	int		j;
	char	*next_line;
	int		size;

	i = 0;
	while (text[i] && text[i] != '\n')
		i++;
	if (!text[i])
	{
		free(text);
		return (NULL);
	}
	size = ft_strlen(text) - i + 1;
	next_line = (char *)malloc(sizeof(char) * (size));
	ft_bzero(next_line, sizeof(char) * size);
	i++;
	j = 0;
	while (text[i])
		next_line[j++] = text[i++];
	next_line[j] = 0;
	free(text);
	return (next_line);
}

char	*ft_new_line(char *text)
{
	char	*line;
	int		i;

	i = 0;
	if (!text[i])
		return (NULL);
	while (text[i] && text[i] != '\n')
		i++;
	line = (char *)malloc((sizeof(char)) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (text[i] && text[i] != '\n')
	{
		line[i] = text[i];
		i++;
	}
	if (text[i] && text[i] == '\n')
	{
		line[i] = '\n';
		i++;
	}
	line[i] = 0;
	return (line);
}

char	*ft_evaluation_line(int fd, char *saved)
{
	char	*buffer;
	int		total_bytes;

	buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (0);
	total_bytes = 1;
	while (total_bytes > 0)
	{
		total_bytes = read(fd, buffer, BUFFER_SIZE);
		if (total_bytes < 0)
		{
			free(buffer);
			buffer = NULL;
			free(saved);
			saved = NULL;
			return (NULL);
		}
		buffer[total_bytes] = 0;
		saved = ft_freedom(saved, buffer);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	free(buffer);
	return (saved);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*next_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	next_line = ft_evaluation_line(fd, next_line);
	if (!next_line)
		return (NULL);
	line = ft_new_line(next_line);
	next_line = ft_find_next(next_line);
	return (line);
}
