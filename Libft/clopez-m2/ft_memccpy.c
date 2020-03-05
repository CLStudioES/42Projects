/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clopez-m <clopez-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 18:59:32 by clopez-m          #+#    #+#             */
/*   Updated: 2019/11/06 13:21:21 by clopez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*ptrd;
	unsigned char	*ptrs;

	ptrs = (unsigned char *)src;
	ptrd = (unsigned char *)dst;
	i = 0;
	while (i < n)
	{
		ptrd[i] = ptrs[i];
		if (ptrd[i] == (unsigned char)c)
			return ((void*)(dst + i + 1));
		i++;
	}
	return (0);
}
