/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clopez-m <clopez-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 18:13:53 by clopez-m          #+#    #+#             */
/*   Updated: 2020/02/10 18:13:54 by clopez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_ndigits(unsigned int n)
{
	int i;

	i = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char		*ft_uitoa(unsigned int n)
{
	char			*num;
	int				nsize;

	nsize = ft_ndigits(n);
	if (!(num = (char *)malloc((nsize + 1) * sizeof(char))))
		return (0);
	num[nsize] = 0;
	while (--nsize >= 0)
	{
		num[nsize] = n % 10 + 48;
		n /= 10;
	}
	return (num);
}
