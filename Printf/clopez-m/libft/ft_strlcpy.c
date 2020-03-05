/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clopez-m <clopez-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 18:12:37 by clopez-m          #+#    #+#             */
/*   Updated: 2020/02/10 18:12:38 by clopez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (!dst)
		return (dstsize);
	if (dstsize > 0)
	{
		while (--dstsize && *(src + i))
		{
			*(dst + i) = *(src + i);
			i++;
		}
		*(dst + i) = 0;
		return (ft_strlen((char *)src));
	}
	return (ft_strlen((char *)src));
}
