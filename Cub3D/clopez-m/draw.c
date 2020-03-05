/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clopez-m <clopez-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 18:00:11 by clopez-m          #+#    #+#             */
/*   Updated: 2020/03/03 18:04:18 by clopez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	first_verline(t_variables *s)
{
	s->color2 = 293994;
	s->j = 0;
	while (s->j < s->drawstart)
	{
		ft_memcpy(s->img_ptr + (s->wbpp[1] / 8) * s->x *
			s->j + s->cox * (s->wbpp[1] / 8),
			&s->wdata[1][s->j % 512 * s->wsl[1] +
			s->cox % 512 * s->wbpp[1] / 8], sizeof(int));
		s->j++;
	}
	s->j = s->drawstart;
	if (s->side == 0)
	{
		s->id = 3;
		s->x_wall = s->posy + s->perpwalldist * s->raydiry;
	}
	else
	{
		s->id = 4;
		s->x_wall = s->posx + s->perpwalldist * s->raydirx;
	}
	if (s->side == 0 && s->raydirx > 0)
		s->id = 2;
	second_verline(s);
}

void	second_verline(t_variables *s)
{
	if (s->side == 1 && s->raydiry < 0)
		s->id = 0;
	s->x_text = (int)(s->x_wall * (double)s->w[s->id]);
	s->x_text = abs(s->x_text);
	while (s->j <= s->drawend)
		put_pxl_to_img(s, s->cox, s->j++);
	while (s->j < s->y)
	{
		ft_memcpy(s->img_ptr + 4 * s->x * s->j +
			s->cox * 4, &s->color2, sizeof(int));
		s->j++;
	}
	if (s->obj > 0 && s->cox >= s->objposx)
	{
		s->id = 7;
		s->count++;
		s->j = s->obstart;
		third_verline(s);
	}
}

void	third_verline(t_variables *s)
{
	while (s->j < s->obend && s->j - s->obstart <
		s->h[7] && s->count < s->w[7])
	{
		if (s->wdata[7][s->oby % s->h[7] * s->wsl[7] +
		s->obx % s->w[7] * s->wbpp[7] / 8] != 0)
		{
			ft_memcpy(s->img_ptr + (s->wbpp[7] / 8) *
				s->x * s->j + s->cox * (s->wbpp[7] / 8),
			&s->wdata[7][s->oby % s->h[7] * s->wsl[7] +
			s->obx % s->w[7] * s->wbpp[7] / 8], sizeof(int));
		}
		s->oby++;
		s->j++;
	}
	s->obx++;
}

void	put_pxl_to_img(t_variables *s, int x, int y)
{
	int n;

	if (x < s->x && y < s->y)
	{
		n = abs((((y * (s->h[s->id] * 4) - s->y * (s->h[s->id] * 2)
			+ s->lineheight * (s->h[s->id] * 2)) * s->h[s->id])
					/ s->lineheight) / (s->h[s->id] * 4));
		ft_memcpy(s->img_ptr + (s->wbpp[s->id] / 8) * s->x * y
			+ x * (s->wbpp[s->id] / 8),
				&s->wdata[s->id][n % s->h[s->id] * s->wsl[s->id] +
				s->x_text % s->w[s->id] * s->wbpp[s->id] / 8], sizeof(int));
	}
}