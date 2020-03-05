/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clopez-m <clopez-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 13:38:18 by clopez-m          #+#    #+#             */
/*   Updated: 2019/11/15 18:19:02 by clopez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	fill_words(const char *s, char **str, char c, int wordn)
{
	int					l;
	int					i;
	int					w;

	i = 0;
	l = 0;
	w = -1;
	while (wordn > ++w)
	{
		l = 0;
		while (s[i] == c && s[i] != 0)
			i++;
		while (s[i] != c && s[i] != 0)
		{
			l++;
			i++;
		}
		if (!(str[w] = (char *)malloc((l + 1) * sizeof(char *))))
			return ;
		ft_strlcpy(str[w], &s[i - l], l + 1);
	}
}

char		**ft_split(const char *s, char c)
{
	char				**str;
	int					wordn;
	int					w;

	w = -1;
	if (!s)
		return (NULL);
	wordn = ft_wordcnt(s, c);
	if (!(str = (char **)malloc((wordn + 1) * sizeof(char *))))
		return (NULL);
	fill_words(s, str, c, wordn);
	str[wordn] = 0;
	return (str);
}
