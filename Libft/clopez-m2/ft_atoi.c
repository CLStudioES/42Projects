/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clopez-m <clopez-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 11:18:01 by clopez-m          #+#    #+#             */
/*   Updated: 2019/11/12 16:45:11 by clopez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *s)
{
	int	c;
	int	numero;
	int signo;

	numero = 0;
	c = 0;
	signo = 1;
	while (s[c] != '\0' && (s[c] == '\t' || s[c] == '\n' || s[c] == ' ' ||
	s[c] == '\v' || s[c] == '\f' || s[c] == '\r'))
		c++;
	if (s[c] != '\0' && (s[c] == '+' || s[c] == '-'))
	{
		signo = s[c] == '-' ? -signo : signo;
		c++;
	}
	while (s[c] != '\0' && s[c] >= '0' && s[c] <= '9')
	{
		if (numero > 214748364 && signo == 1 && *(s + c) > '7')
			return (-1);
		else if (numero > 214748364 && signo == -1 && *(s + c) > '8')
			return (0);
		numero = numero * 10 + (s[c] - '0');
		c++;
	}
	return (numero * signo);
}
