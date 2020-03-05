/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clopez-m <clopez-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 19:33:30 by clopez-m          #+#    #+#             */
/*   Updated: 2019/11/15 18:13:34 by clopez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_str_is_lowercase(char *str)
{
	int a;
	int b;

	a = 0;
	b = 0;
	while (str[a] != '\0' && b == 0)
	{
		if (!(str[a] >= 97 && str[a] <= 122))
		{
			b++;
		}
		a++;
	}
	if (b != 0)
		return (0);
	else
		return (1);
}
