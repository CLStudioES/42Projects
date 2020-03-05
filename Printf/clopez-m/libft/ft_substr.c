/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clopez-m <clopez-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 18:13:27 by clopez-m          #+#    #+#             */
/*   Updated: 2020/02/10 18:13:27 by clopez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	size_t	slen;
	size_t	cnt;
	char	*str;

	if (!s)
		return (NULL);
	if (ft_strlen(s) < start)
		return (ft_strdup(""));
	slen = ft_strlen(s + start);
	if (slen < len)
		len = slen;
	if (!(str = (char *)malloc((len + 1) * sizeof(char))))
		return (NULL);
	cnt = 0;
	while (cnt < len)
	{
		str[cnt] = s[start + cnt];
		cnt++;
	}
	str[cnt] = 0;
	return (str);
}
