/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clopez-m <clopez-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 19:38:04 by clopez-m          #+#    #+#             */
/*   Updated: 2019/11/06 13:48:06 by clopez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t				i;
	unsigned char		*ptr;
	unsigned char		*ptr2;

	ptr = (unsigned char*)src;
	ptr2 = (unsigned char*)dst;
	i = 0;
	if (ptr == ptr2)
		return (dst);
	if (ptr < ptr2)
	{
		ptr = (unsigned char *)src + len - 1;
		ptr2 = dst + len - 1;
		while (len--)
		{
			*ptr2-- = *ptr--;
		}
	}
	else
	{
		while (len--)
			*ptr2++ = *ptr++;
	}
	return (dst);
}
