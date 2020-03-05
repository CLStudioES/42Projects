/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_character.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clopez-m <clopez-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 18:17:25 by clopez-m          #+#    #+#             */
/*   Updated: 2020/02/10 18:17:25 by clopez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_update_struct(t_struct *s, char c)
{
	s->str = &c;
	s->slen = 1;
	s->writelen = s->slen;
}

static void	ft_char_print_right(t_struct *s)
{
	while (s->width - s->writelen > 0)
	{
		s->len += write(1, " ", 1);
		s->width--;
	}
	while (s->writelen > 0)
	{
		s->len += write(1, s->str, 1);
		s->writelen--;
	}
}

static void	ft_char_print_left(t_struct *s)
{
	while (s->writelen > 0)
	{
		s->len += write(1, s->str, 1);
		s->writelen--;
		s->width--;
	}
	while (s->width - s->writelen > 0)
	{
		s->len += write(1, " ", 1);
		s->width--;
	}
}

void		ft_print_character(t_struct *s, va_list lst)
{
	char c;

	c = va_arg(lst, int);
	ft_update_struct(s, c);
	if (s->minus)
		ft_char_print_left(s);
	else
		ft_char_print_right(s);
}
