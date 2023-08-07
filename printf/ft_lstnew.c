/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lahernan <lahernan@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 12:19:19 by lahernan          #+#    #+#             */
/*   Updated: 2023/05/11 12:19:20 by lahernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*list_new;

	list_new = (t_list *)malloc(sizeof(t_list));
	if (!list_new)
		return (0);
	list_new->content = content;
	list_new->next = NULL;
	return (list_new);
}
