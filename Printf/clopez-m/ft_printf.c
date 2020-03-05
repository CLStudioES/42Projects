/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clopez-m <clopez-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 18:18:12 by clopez-m          #+#    #+#             */
/*   Updated: 2020/02/10 18:18:13 by clopez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "ft_printf.h"

static void	ft_init_struct(t_struct *f)
{
	f->pos = 0;
	f->len = 0;
	f->minus = 0;
	f->zero = 0;
	f->plus = 0;
	f->space = 0;
	f->hash = 0;
	f->isneg = 0;
	f->writelen = 0;
	f->width = 0;
	f->w = 0;
	f->p = 0;
	f->prec = -1;
	f->str = NULL;
	f->type = '\n';
}

int			ft_printf(const char *format, ...)
{
	t_struct	tab;
	va_list		alist;

	ft_init_struct(&tab);
	va_start(alist, format);
	if (format[0] == '%' && format[1] == 0)
		return (0);
	else if (!ft_strchr(format, '%'))
		tab.len += write(1, format, ft_strlen(format));
	else
		ft_start_process(format, &tab, alist);
	va_end(alist);
	ft_reset_struct(&tab);
	return (tab.len);
}
