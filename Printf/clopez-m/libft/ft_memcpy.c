/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clopez-m <clopez-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 18:10:50 by clopez-m          #+#    #+#             */
/*   Updated: 2020/02/10 18:10:51 by clopez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char *m0;
	char *m1;

	if (n == 0 || dst == src)
		return (dst);
	m0 = (char *)dst;
	m1 = (char *)src;
	while (n--)
		*m0++ = *m1++;
	return (dst);
}
