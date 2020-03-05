/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clopez-m <clopez-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 18:08:43 by clopez-m          #+#    #+#             */
/*   Updated: 2020/02/10 18:08:44 by clopez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_ndigits(long int n)
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

char		*ft_itoa(long int n)
{
	char			*num;
	unsigned int	onum;
	int				is_negative;
	int				nsize;

	is_negative = n < 0 ? 1 : 0;
	nsize = ft_ndigits(n) + is_negative;
	if (!(num = (char *)malloc((nsize + 1) * sizeof(char))))
		return (0);
	onum = is_negative ? -n : n;
	num[nsize] = 0;
	if (is_negative)
		num[0] = '-';
	while (--nsize >= is_negative)
	{
		num[nsize] = onum % 10 + 48;
		onum /= 10;
	}
	return (num);
}
