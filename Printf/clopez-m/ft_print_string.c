/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clopez-m <clopez-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 18:17:50 by clopez-m          #+#    #+#             */
/*   Updated: 2020/02/10 18:17:51 by clopez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_update_struct(t_struct *s)
{
	s->slen = (int)ft_strlen(s->str);
	if (s->p == 1)
		s->prec = s->slen + 1;
	s->writelen = (s->prec > -1 && s->prec < s->slen) ? s->prec : s->slen;
	s->width = s->width < s->writelen ? s->writelen : s->width;
}

static void	ft_str_print_right(t_struct *s)
{
	while (s->width - s->writelen > 0)
	{
		s->len += write(1, " ", 1);
		s->width--;
	}
	while (s->writelen > 0)
	{
		s->len += write(1, s->str++, 1);
		s->writelen--;
	}
}

static void	ft_str_print_left(t_struct *s)
{
	while (s->writelen > 0)
	{
		s->len += write(1, s->str++, 1);
		s->writelen--;
		s->width--;
	}
	while (s->width - s->writelen > 0)
	{
		s->len += write(1, " ", 1);
		s->width--;
	}
}

void		ft_print_string(t_struct *s, va_list lst)
{
	if (!(s->str = va_arg(lst, char *)))
		s->str = "(null)";
	ft_update_struct(s);
	if (s->minus)
		ft_str_print_left(s);
	else
		ft_str_print_right(s);
}
