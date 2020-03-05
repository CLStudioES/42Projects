/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_handler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clopez-m <clopez-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 18:49:06 by clopez-m          #+#    #+#             */
/*   Updated: 2020/03/03 19:02:05 by clopez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int			lines_counter(t_variables *s)
{
	int i;
	int x;

	i = 0;
	x = 0;
	while (s->map[i++] != '\0')
		if (s->map[i] == '\n')
			x++;
	s->height = x;
	return (x);
}

int			files_counter(t_variables *s)
{
	int i;
	int x;

	x = 0;
	i = 0;
	while (s->map[i++] != '\n')
		if (s->map[i] != ' ')
			x++;
	s->width = x;
	return (x);
}

static void	directposition_getter(t_variables *s, int dir, int x, int y)
{
	s->posx = x;
	s->posy = y;
	s->dirx = -1;
	s->diry = 0;
	s->initialdir = 0;
	if (dir == DIRS)
		s->initialdir = 21;
	if (dir == DIRW)
		s->initialdir = 10;
	if (dir == DIRE)
	{
		s->initialdir = 32;
	}
}

void	second_maparray_converter(t_variables *s, int x, int n, int y)
{
	s->mapn[x][y] = s->map[n] - 48;
	if (s->mapn[x][y] == 2)
		s->mapn[x][y] = 2;
	if (s->mapn[x][y] > 2)
	{
		directposition_getter(s, s->mapn[x][y], x, y);
		s->mapn[x][y] = 0;
	}
}

void	maparray_converter(t_variables *s)
{
	int	i;
	int n;
	int y;

	i = 0;
	n = 0;

	if (!(s->mapn = malloc(sizeof(int *) * (lines_counter(s) + 1))))
		return ;
	while (i < lines_counter(s))
	{
		y = 0;
		if (!(s->mapn[i] = malloc(sizeof(int) * (files_counter(s) + 1))))
			return ;
		while (y < files_counter(s))
		{
			second_maparray_converter(s, i, n, y++);
			n += 2;
		}
		i++;
	}
}
