/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clopez-m <clopez-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 18:11:01 by clopez-m          #+#    #+#             */
/*   Updated: 2020/02/10 18:11:02 by clopez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int char_n, size_t len)
{
	unsigned char *a;

	a = (unsigned char *)str;
	while (len-- > 0)
		*a++ = (unsigned char)char_n;
	return (str);
}
