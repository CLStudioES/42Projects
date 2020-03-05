/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wordcnt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clopez-m <clopez-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 20:14:29 by clopez-m          #+#    #+#             */
/*   Updated: 2019/11/15 15:17:57 by clopez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_wordcnt(const char *s, char del)
{
	int	pos;
	int	wcnt;

	pos = 0;
	wcnt = 0;
	while (s[pos] != 0)
	{
		if (s[pos] == del)
			pos++;
		else
		{
			wcnt++;
			while (s[pos] != del && s[pos] != 0)
				pos++;
		}
	}
	return (wcnt);
}
