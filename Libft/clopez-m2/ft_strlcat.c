/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clopez-m <clopez-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 13:35:42 by clopez-m          #+#    #+#             */
/*   Updated: 2019/11/07 18:38:15 by clopez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t			c;
	size_t			dstlen;

	c = 0;
	dstlen = ft_strlen((char *)dst);
	if (dstsize <= dstlen)
		return (ft_strlen((char *)src) + dstsize);
	while (c < dstsize - dstlen - 1 && *(src + c) != 0)
	{
		*(dst + dstlen + c) = *(src + c);
		c++;
	}
	*(dst + dstlen + c) = 0;
	return (ft_strlen((char *)src) + dstlen);
}
