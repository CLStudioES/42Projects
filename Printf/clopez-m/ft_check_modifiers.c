/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_modifiers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clopez-m <clopez-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 18:17:20 by clopez-m          #+#    #+#             */
/*   Updated: 2020/02/10 18:17:21 by clopez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_check_precision(const char *format, t_struct *s, va_list lst)
{
	int wd;

	wd = 0;
	if (!(format[s->pos] == '.'))
		return ;
	s->pos++;
	if (format[s->pos] == '*')
	{
		wd = (int)va_arg(lst, int);
		s->p = (wd < 0);
		wd = (wd < 0 ? 0 : wd);
		s->pos++;
	}
	else if (ft_isdigit(format[s->pos]))
	{
		while (ft_isdigit(format[s->pos]))
		{
			if (wd != 0)
				wd *= 10;
			wd += format[s->pos] - '0';
			s->pos++;
		}
	}
	s->prec = wd;
}

static void	ft_check_width(const char *format, t_struct *s, va_list lst)
{
	int wd;

	wd = 0;
	if (format[s->pos] == '*')
	{
		wd = va_arg(lst, int);
		if (wd < 0)
		{
			s->minus = 1;
			wd = -wd;
		}
		s->pos++;
	}
	else if (ft_isdigit(format[s->pos]))
	{
		while (ft_isdigit(format[s->pos]))
		{
			if (wd != 0)
				wd *= 10;
			wd += format[s->pos] - '0';
			s->pos++;
		}
	}
	s->width = wd;
}

static void	ft_check_flags(const char *format, t_struct *s)
{
	while (ft_strchr("-0", format[s->pos]))
	{
		if (format[s->pos] == '-')
			s->minus = 1;
		else if (format[s->pos] == '0')
			s->zero = 1;
		s->pos++;
	}
	if (s->zero && s->minus)
		s->zero = 0;
}

void		ft_check_modifiers(const char *format, t_struct *s, va_list lst)
{
	ft_check_flags(format, s);
	ft_check_width(format, s, lst);
	ft_check_precision(format, s, lst);
}
