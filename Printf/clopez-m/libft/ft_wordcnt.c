/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wordcnt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clopez-m <clopez-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 18:13:59 by clopez-m          #+#    #+#             */
/*   Updated: 2020/02/10 18:13:59 by clopez-m         ###   ########.fr       */
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
