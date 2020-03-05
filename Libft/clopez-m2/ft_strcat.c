/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clopez-m <clopez-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 10:27:33 by clopez-m          #+#    #+#             */
/*   Updated: 2019/11/08 18:15:17 by clopez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dest, const char *src)
{
	int	counter;
	int counterb;

	counter = 0;
	counterb = 0;
	while (dest[counter] != '\0')
	{
		counter++;
	}
	while (src[counterb] != '\0')
	{
		dest[counter + counterb] = src[counterb];
		counterb++;
	}
	dest[counter + counterb] = '\0';
	return (dest);
}
