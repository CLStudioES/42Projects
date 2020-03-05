/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auxiliar.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clopez-m <clopez-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 17:57:35 by clopez-m          #+#    #+#             */
/*   Updated: 2020/03/03 19:35:44 by clopez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	object_calculator(t_variables *s)
{
	while (s->obend - s->obstart < s->h[7])
	{
		s->lineheightaux = s->drawend - s->h[7];
		s->obstart = -s->lineheightaux / 2 + (s->y / 1.3);
		if (s->obstart < 0)
			s->obstart = 0;
		s->obend = s->lineheightaux / 2 + (s->y / 1.3);
		if (s->obend >= s->y)
			s->obend = s->y - 1;
	}
}

void	image_converter(t_variables *s)
{
	char *n = NULL;

	s->count = 0;
	mlx_put_image_to_window(s->mlx_ptr, s->win_ptr, s->img, 0, 0);
	mlx_put_image_to_window(s->mlx_ptr, s->win_ptr,
		s->wlone[5], s->fpposx, s->fpposy);
	if (s->obj == 1)
		mlx_put_image_to_window(s->mlx_ptr, s->win_ptr,
			s->wlone[7], s->obstart, s->obend);
	mlx_string_put(s->mlx_ptr, s->win_ptr, 20, 20, 293994, n);
	free(n);
	mlx_destroy_image(s->mlx_ptr, s->wlone[7]);
	mlx_destroy_image(s->mlx_ptr, s->img);
	s->obj = 0;
}