/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clopez-m <clopez-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 18:17:29 by clopez-m          #+#    #+#             */
/*   Updated: 2020/02/10 18:17:30 by clopez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_update_struct(t_struct *s, unsigned int num)
{
	s->str = (s->type == 'x') ? int_hex(num, 0) : int_hex(num, 1);
	s->slen = (int)ft_strlen(s->str);
	s->w = (s->width > 0) ? 1 : 0;
	s->writelen = s->prec > s->slen ? s->prec : s->slen;
	s->width = (s->width < s->writelen ? s->writelen : s->width);
	s->zero = s->prec > 0 ? 0 : s->zero;
}

static void	ft_hex_print_right(t_struct *s)
{
	while (s->width - s->writelen > 0)
	{
		if (s->zero == 1)
			s->len += write(1, "0", 1);
		else
			s->len += write(1, " ", 1);
		s->width--;
	}
	while (s->writelen - s->slen > 0)
	{
		s->len += write(1, "0", 1);
		s->writelen--;
	}
	while (s->slen > 0)
	{
		s->len += write(1, s->str++, 1);
		s->slen--;
	}
}

static void	ft_hex_print_left(t_struct *s)
{
	while (s->writelen - s->slen > 0)
	{
		s->len += write(1, "0", 1);
		s->writelen--;
		s->width--;
	}
	while (s->slen > 0)
	{
		s->len += write(1, s->str++, 1);
		s->slen--;
		s->width--;
	}
	while (s->width > 0)
	{
		s->len += write(1, " ", 1);
		s->width--;
	}
}

void		ft_print_hex(t_struct *s, va_list lst)
{
	unsigned int	num;

	num = va_arg(lst, unsigned int);
	ft_update_struct(s, num);
	if (s->prec == 0 && num == 0 && s->w == 0)
		return ;
	if (s->prec == 0 && num == 0 && s->width > 0)
	{
		s->str = ft_strdup("");
		s->slen = 0;
		s->writelen = 0;
	}
	if (s->minus)
		ft_hex_print_left(s);
	else
		ft_hex_print_right(s);
}
