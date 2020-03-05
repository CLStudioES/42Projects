/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clopez-m <clopez-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 18:12:18 by clopez-m          #+#    #+#             */
/*   Updated: 2020/02/10 18:12:18 by clopez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*ms1;

	ms1 = (char *)malloc(ft_strlen((char *)s1) * sizeof(char) + 1);
	if (ms1 == NULL)
		return (ms1);
	ft_strcpy(ms1, (char *)s1);
	return (ms1);
}
