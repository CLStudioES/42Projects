/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reset_struct.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clopez-m <clopez-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 18:19:47 by clopez-m          #+#    #+#             */
/*   Updated: 2020/02/10 18:19:48 by clopez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_reset_struct(t_struct *f)
{
	f->minus = 0;
	f->zero = 0;
	f->plus = 0;
	f->space = 0;
	f->hash = 0;
	f->width = 0;
	f->w = 0;
	f->p = 0;
	f->prec = -1;
	f->writelen = 0;
	f->slen = 0;
	f->isneg = 0;
	f->str = NULL;
	f->type = '\0';
}
