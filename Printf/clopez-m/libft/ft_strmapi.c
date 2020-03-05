/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clopez-m <clopez-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 18:13:03 by clopez-m          #+#    #+#             */
/*   Updated: 2020/02/10 18:13:04 by clopez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	char			*str;
	unsigned int	slen;

	if (!s || !f)
		return (NULL);
	slen = ft_strlen(s);
	if (!(str = (char *)malloc((slen + 1) * sizeof(char))))
		return (NULL);
	str[slen] = 0;
	while (slen-- > 0)
		str[slen] = f(slen, s[slen]);
	return (str);
}
