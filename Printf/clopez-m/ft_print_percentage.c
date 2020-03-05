/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_percentage.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clopez-m <clopez-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 18:17:39 by clopez-m          #+#    #+#             */
/*   Updated: 2020/02/10 18:17:40 by clopez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_update_struct(t_struct *s)
{
	s->str = ft_strdup("%");
	s->slen = 1;
	s->w = s->width > 0;
	s->writelen = s->slen;
	s->width = (s->width < s->writelen ? s->writelen : s->width);
}

static void	ft_perc_print_right(t_struct *s)
{
	while (s->width - s->writelen > 0)
	{
		if (s->zero == 1)
			s->len += write(1, "0", 1);
		else
			s->len += write(1, " ", 1);
		s->width--;
	}
	while (s->slen > 0)
	{
		s->len += write(1, s->str++, 1);
		s->slen--;
	}
}

static void	ft_perc_print_left(t_struct *s)
{
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

void		ft_print_percentage(t_struct *s)
{
	ft_update_struct(s);
	if (s->minus)
		ft_perc_print_left(s);
	else
		ft_perc_print_right(s);
}
