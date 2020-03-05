/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clopez-m <clopez-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 16:50:35 by clopez-m          #+#    #+#             */
/*   Updated: 2019/11/15 17:49:11 by clopez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*str;
	unsigned int	counter;
	size_t			j;

	if (s != NULL && f != NULL)
	{
		j = ft_strlen(s);
		if (!(str = (char *)malloc((j + 1) * sizeof(char))))
			return (NULL);
		counter = 0;
		while (counter < j)
		{
			str[counter] = f(counter, s[counter]);
			counter++;
		}
		str[counter] = 0;
		return (str);
	}
	return (NULL);
}
