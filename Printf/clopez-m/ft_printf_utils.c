/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clopez-m <clopez-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 18:18:06 by clopez-m          #+#    #+#             */
/*   Updated: 2020/02/10 18:18:07 by clopez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*int_hex(unsigned long n, int up)
{
	if (!up)
		return (ft_itoa_base(n, "0123456789abcdef"));
	else
		return (ft_itoa_base(n, "0123456789ABCDEF"));
}
