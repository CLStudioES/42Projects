/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clopez-m <clopez-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 05:13:53 by clopez-m          #+#    #+#             */
/*   Updated: 2020/02/10 18:28:59 by clopez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>
# include "libft/libft.h"
# include <stdio.h>

typedef	struct	s_struct
{
	int		pos;
	int		len;
	int		minus;
	int		zero;
	int		plus;
	int		space;
	int		hash;
	int		w;
	int		width;
	int		p;
	int		prec;
	int		isneg;
	char	type;
	char	*str;
	int		slen;
	int		writelen;
}				t_struct;

int				ft_printf(const char *format, ...);
void			ft_start_process(const char *format, t_struct *s, va_list lst);
void			ft_check_modifiers(const char *format,
									t_struct *s, va_list lst);
void			ft_print_string(t_struct *s, va_list lst);
void			ft_print_character(t_struct *s, va_list lst);
void			ft_print_integer(t_struct *s, va_list lst);
void			ft_print_unsigned_integer(t_struct *s, va_list lst);
void			ft_print_hex(t_struct *s, va_list lst);
void			ft_reset_struct(t_struct *s);
void			ft_print_ptr(t_struct *s, va_list lst);
void			ft_print_percentage(t_struct *s);
char			*int_hex(unsigned long n, int up);

#endif
