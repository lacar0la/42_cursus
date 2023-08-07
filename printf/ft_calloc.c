/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lahernan <lahernan@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 19:24:23 by lahernan          #+#    #+#             */
/*   Updated: 2023/05/09 19:24:24 by lahernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

void	*ft_calloc(size_t nitems, size_t size)
{
	void	*sln;

	sln = malloc(nitems * size);
	if (!sln)
		return (0);
	ft_bzero(sln, nitems * size);
	return (sln);
}
