/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clopez-m <clopez-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 13:50:49 by clopez-m          #+#    #+#             */
/*   Updated: 2019/11/06 16:23:49 by clopez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ptr;
	unsigned char	d;
	size_t			i;

	i = 0;
	ptr = (unsigned char *)s;
	d = (unsigned char)c;
	while (i < n && ptr[i] != d)
		i++;
	if (i < n && ptr[i] == d)
		return (&ptr[i]);
	return (NULL);
}
