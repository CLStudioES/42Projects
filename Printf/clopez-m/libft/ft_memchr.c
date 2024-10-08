/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clopez-m <clopez-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 18:10:29 by clopez-m          #+#    #+#             */
/*   Updated: 2020/02/10 18:10:30 by clopez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*m0;
	size_t	i;

	m0 = (char *)s;
	i = 0;
	while (*(m0 + i) != (char)c)
	{
		if (i == n - 1)
			return (0);
		i++;
	}
	return ((m0 + i));
}
