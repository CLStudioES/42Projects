/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clopez-m <clopez-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 14:10:15 by clopez-m          #+#    #+#             */
/*   Updated: 2019/11/18 16:33:04 by clopez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*lst;

	if (!(lst = malloc(sizeof(lst))))
		return (NULL);
	if (content == NULL)
		lst->content = NULL;
	else
		lst->content = (void *)content;
	lst->next = NULL;
	return (lst);
}
