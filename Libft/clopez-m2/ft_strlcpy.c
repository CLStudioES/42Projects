/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clopez-m <clopez-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 11:14:12 by clopez-m          #+#    #+#             */
/*   Updated: 2019/11/19 15:25:11 by clopez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *d, const char *s, size_t z)
{
	unsigned int	counter;

	if (d == NULL || s == NULL)
		return (0);
	if (z > 0)
	{
		counter = 0;
		while (counter < (z - 1) && s[counter] != 0)
		{
			d[counter] = s[counter];
			counter++;
		}
		d[counter] = '\0';
	}
	return (ft_strlen(s));
}
