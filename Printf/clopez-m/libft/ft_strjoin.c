/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clopez-m <clopez-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 18:12:24 by clopez-m          #+#    #+#             */
/*   Updated: 2020/02/10 18:12:25 by clopez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*str;
	size_t	strlen;
	size_t	cnt;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	strlen = ft_strlen(s1) + ft_strlen(s2);
	cnt = 0;
	if (!(str = (char *)malloc((strlen + 1) * sizeof(char))))
		return (NULL);
	while (*(s1 + cnt) != 0)
	{
		*(str + cnt) = *(s1 + cnt);
		cnt++;
	}
	strlen = cnt;
	cnt = 0;
	while (*(s2 + cnt) != 0)
	{
		*(str + strlen + cnt) = *(s2 + cnt);
		cnt++;
	}
	*(str + strlen + cnt) = 0;
	return (str);
}
