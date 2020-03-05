/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initiate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clopez-m <clopez-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 17:00:57 by clopez-m          #+#    #+#             */
/*   Updated: 2020/03/05 16:41:53 by clopez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	read_map(t_variables *s, char **argv, int argc)
{
	int		fp;
	char	*buffer;

	s->map = ft_strdup("");
	fp = open(argv[1], O_RDONLY);
	while ((get_next_line(fp, &buffer)) > 0)
	{
		info_controller(s, buffer);
		free(buffer);
	}
	info_controller(s, buffer);
	free(buffer);
	maparray_converter(s);
	close(fp);
	if (argc == 3)
	{
		write(1, "Error\n-Argumento incorrecto-", 28);
		exit(1);
	}
}

void	initiate(t_variables *s)
{
	s->id = 0;
	s->planex = 0;
	s->planey = 0.66;
	s->obj = 0;
	s->movespeed = 0.12;
	s->rotspeed = 0.08;
	s->count = 0;
	s->mlx_ptr = NULL;
	s->win_ptr = NULL;
}

void	executor(t_variables *s)
{
	int i;

	i = 0;
	s->mlx_ptr = mlx_init();
	s->win_ptr = mlx_new_window(s->mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "CUBE3D");
	file_processor(s);
	s->fpposx = s->x / 2 - s->w[5] / 2;
	s->fpposy = s->y - s->h[5];
	first_raycast(s);
	mlx_hook(s->win_ptr, 2, 0, nopresed, s);
	mlx_hook(s->win_ptr, 3, 0, presed, s);
	mlx_loop_hook(s->mlx_ptr, key_handler, s);
	if (s->initialdir > 0)
	{
		s->presedl = 1;
		while (i++ < s->initialdir)
			key_handler(s);
		s->presedl = 0;
		s->initialdir = 0;
	}
	mlx_loop(s->mlx_ptr);
}