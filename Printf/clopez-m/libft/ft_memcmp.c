/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clopez-m <clopez-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 18:10:45 by clopez-m          #+#    #+#             */
/*   Updated: 2020/02/10 18:10:45 by clopez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*m0;
	unsigned char	*m1;

	m0 = (unsigned char *)s1;
	m1 = (unsigned char *)s2;
	while (n)
	{
		if (*m0 != *m1)
			return (*m0 - *m1);
		m0++;
		m1++;
		n--;
	}
	return (0);
}
