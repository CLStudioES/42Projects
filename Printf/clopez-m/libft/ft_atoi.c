/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clopez-m <clopez-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 18:06:49 by clopez-m          #+#    #+#             */
/*   Updated: 2020/02/10 18:06:53 by clopez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	calculate_num(const char *str, size_t i, int *sign)
{
	size_t res;

	res = 0;
	while (ft_isdigit(*(str + i)) && *(str + i) != 0)
	{
		if (res > 214748364 && *sign == 1 && *(str + i) > '7')
			return (-1);
		if (res > 214748364 && *sign == -1 && *(str + i) > '8')
			return (0);
		if (res != 0)
			res *= 10;
		res += *(str + i) - 48;
		i++;
	}
	return (res);
}

int			ft_atoi(const char *str)
{
	size_t		i;
	int			sign;
	int			res;

	i = 0;
	sign = 1;
	while (ft_isspace(*(str + i)))
		i++;
	if ((int)*(str + i) == '+')
		i++;
	else if (*(str + i) == '-')
	{
		sign *= -1;
		i++;
	}
	res = calculate_num(str, i, &sign);
	return ((res == -1 || res == 0) ? res : (res * sign));
}
