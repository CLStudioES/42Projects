/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clopez-m <clopez-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 18:09:15 by clopez-m          #+#    #+#             */
/*   Updated: 2020/02/10 18:09:16 by clopez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list *temp;
	t_list *list;

	list = *lst;
	while (list)
	{
		temp = list;
		list = list->next;
		del(temp->content);
		free(temp);
	}
	*lst = NULL;
}
