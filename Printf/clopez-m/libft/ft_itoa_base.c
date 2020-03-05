/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clopez-m <clopez-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 18:08:37 by clopez-m          #+#    #+#             */
/*   Updated: 2020/02/10 18:08:38 by clopez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa_base(unsigned long n, char *base)
{
	char	*num;
	int		nsize;
	int		r;

	r = ft_strlen(base);
	nsize = ft_ndigits_base(n, r);
	if (!(num = (char *)malloc((nsize + 1) * sizeof(char))))
		return (0);
	num[nsize] = 0;
	while (--nsize >= 0)
	{
		num[nsize] = base[(n % r)];
		n /= r;
	}
	return (num);
}
