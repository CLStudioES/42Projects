/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clopez-m <clopez-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 17:25:29 by clopez-m          #+#    #+#             */
/*   Updated: 2019/11/15 18:13:36 by clopez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_str_is_alpha(char *str)
{
	int n;
	int c;

	n = 0;
	c = 0;
	while (str[n] != '\0' && c == 0)
	{
		if (!((str[n] >= 65 && str[n] <= 90) ||
			(str[n] >= 97 && str[n] <= 122) || str[n] == 0))
		{
			c++;
		}
		n++;
	}
	if (c != 0)
		return (0);
	else
		return (1);
}
