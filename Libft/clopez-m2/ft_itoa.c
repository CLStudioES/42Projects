/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clopez-m <clopez-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 15:21:04 by clopez-m          #+#    #+#             */
/*   Updated: 2019/11/15 16:20:21 by clopez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	size_len(int nbr)
{
	int				counter;
	unsigned int	aux;

	if (nbr == 0)
		return (1);
	counter = 0;
	aux = nbr;
	if (nbr < 0)
	{
		counter++;
		aux = -nbr;
	}
	while (aux > 0)
	{
		aux /= 10;
		counter++;
	}
	return (counter);
}

char		*ft_itoa(int nb)
{
	char			*str;
	int				len;
	int				negative;
	unsigned int	unbr;

	len = size_len(nb);
	if ((str = (char*)malloc(sizeof(char) * (len + 1))) == NULL)
		return (NULL);
	str[len] = '\0';
	negative = 0;
	unbr = nb;
	if (nb < 0)
	{
		negative = 1;
		str[0] = '-';
		unbr = -nb;
	}
	len--;
	while (len >= (negative ? 1 : 0))
	{
		str[len] = unbr % 10 + '0';
		unbr /= 10;
		len--;
	}
	return (str);
}
