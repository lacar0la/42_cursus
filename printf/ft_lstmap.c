/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lahernan <lahernan@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 14:26:48 by lahernan          #+#    #+#             */
/*   Updated: 2023/05/17 14:26:52 by lahernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*sln;
	t_list	*nxt;

	sln = NULL;
	while (lst != NULL)
	{
		nxt = ft_lstnew((*f)(lst->content));
		if (!nxt)
		{
			ft_lstclear(&sln, del);
			return (NULL);
		}
		ft_lstadd_back(&sln, nxt);
		lst = lst->next;
	}
	return (sln);
}
