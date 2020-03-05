/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start_process.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clopez-m <clopez-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 18:19:52 by clopez-m          #+#    #+#             */
/*   Updated: 2020/02/10 18:19:53 by clopez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_do_print(const char *format, t_struct *s, va_list lst)
{
	if ((s->type = format[s->pos]) == 's')
		ft_print_string(s, lst);
	else if ((s->type = format[s->pos]) == 'c')
		ft_print_character(s, lst);
	else if ((s->type = format[s->pos]) == 'd' ||
				(s->type = format[s->pos]) == 'i')
		ft_print_integer(s, lst);
	else if ((s->type = format[s->pos]) == 'u')
		ft_print_unsigned_integer(s, lst);
	else if ((s->type = format[s->pos]) == 'x' ||
				(s->type = format[s->pos]) == 'X')
		ft_print_hex(s, lst);
	else if ((s->type = format[s->pos]) == 'p')
		ft_print_ptr(s, lst);
	else if ((s->type = format[s->pos]) == '%')
		ft_print_percentage(s);
}

void		ft_start_process(const char *format, t_struct *s, va_list lst)
{
	while (format[s->pos] != 0)
	{
		if (format[s->pos] == '%')
		{
			s->pos++;
			if (ft_strchr("-.*0123456789", format[s->pos]))
				ft_check_modifiers(format, s, lst);
			if (ft_strchr("cspdiuxX%", format[s->pos]))
			{
				ft_do_print(format, s, lst);
			}
		}
		else
			s->len += write(1, &format[s->pos], 1);
		ft_reset_struct(s);
		if (format[s->pos] != '\0')
			s->pos++;
	}
}
