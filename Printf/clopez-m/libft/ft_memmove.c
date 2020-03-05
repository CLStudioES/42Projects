/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clopez-m <clopez-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 18:10:54 by clopez-m          #+#    #+#             */
/*   Updated: 2020/02/10 18:10:55 by clopez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*m0;
	unsigned char	*m1;

	m0 = (unsigned char *)dst;
	m1 = (unsigned char *)src;
	i = 0;
	if (dst == src)
		return (dst);
	if (m1 < m0)
		while (++i <= len)
			m0[len - i] = m1[len - i];
	else
		while (len-- > 0)
			*m0++ = *m1++;
	return (dst);
}
