/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clopez-m <clopez-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 19:06:22 by clopez-m          #+#    #+#             */
/*   Updated: 2019/11/07 15:52:07 by clopez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*str;
	int		counter;

	str = (char *)s;
	counter = 0;
	while (*str != '\0')
	{
		str++;
		counter++;
	}
	while (*str != c && counter-- > 0)
		str--;
	if (counter < 0)
		return (0);
	else
		return (str);
}
