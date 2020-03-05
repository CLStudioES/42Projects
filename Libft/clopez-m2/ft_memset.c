/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clopez-m <clopez-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 19:06:59 by clopez-m          #+#    #+#             */
/*   Updated: 2019/11/05 19:20:18 by clopez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*a;

	if (len == 0)
	{
		return (b);
	}
	a = (unsigned char *)b;
	while (len--)
	{
		*a = (unsigned char)c;
		if (len)
		{
			a++;
		}
	}
	return (b);
}
