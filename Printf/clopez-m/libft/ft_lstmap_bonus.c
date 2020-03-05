/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clopez-m <clopez-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 18:10:08 by clopez-m          #+#    #+#             */
/*   Updated: 2020/02/10 18:10:09 by clopez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list *new;
	t_list *first;

	if (lst || del)
	{
		if (!(first = ft_lstnew(f(lst->content))))
			return (NULL);
		lst = lst->next;
		while (lst)
		{
			if (!(new = ft_lstnew(f(lst->content))))
				return (NULL);
			ft_lstadd_back(&first, new);
			lst = lst->next;
		}
		return (first);
	}
	return (NULL);
}
