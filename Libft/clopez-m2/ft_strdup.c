/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clopez-m <clopez-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 19:36:12 by clopez-m          #+#    #+#             */
/*   Updated: 2019/11/19 13:50:45 by clopez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char final;
	char *aux;

	aux = malloc(sizeof(final) + ft_strlen(s1));
	if (aux == NULL)
		return (NULL);
	ft_strcpy(aux, s1);
	return (ft_strcpy(aux, s1));
}
