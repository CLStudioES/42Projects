/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clopez-m <clopez-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 18:26:57 by clopez-m          #+#    #+#             */
/*   Updated: 2020/03/03 20:10:36 by clopez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int			name_checker(char **argv)
{
	char *aux;

	if (!(aux = ft_strchr(argv[1], '.')))
		return (-1);
	if (*(++aux) != 'c')
		return (-1);
	if (*(++aux) != 'u')
		return (-1);
	if (*(++aux) != 'b')
		return (-1);
	return (1);
}

static int	border_checker(t_variables *s)
{
	int i;

	i = 0;
	while (i < s->width)
		if (s->mapn[0][i++] != 1)
			return (-1);
	i = 0;
	while (i < s->width)
		if (s->mapn[s->height - 1][i++] != 1)
			return (-1);
	i = 0;
	while (i < s->height)
		if (s->mapn[i++][0] != 1)
			return (-1);
	i = 0;
	while (i < s->height)
		if (s->mapn[i++][s->width - 1] != 1)
			return (-1);
	return (1);
}

static int	content_checker(t_variables *s)
{
	int i;

	i = 0;
	while (s->map[i] != '\0')
	{
		if (s->map[i] != '1' && s->map[i] != '0' && s->map[i] != '2'
			&& s->map[i] != 'N' && s->map[i] != 'S' &&
			s->map[i] != 'O' && s->map[i] != 'E' && s->map[i] != 'W')
			return (-1);
		i += 2;
	}
	return (1);
}

int			checker_controller(t_variables *s)
{
	if (border_checker(s) == -1)
		return (-1);
	if (content_checker(s) == -1)
		return (-1);
	if (!(ft_strchr(s->map, 'N') || ft_strchr(s->map, 'S') ||
		ft_strchr(s->map, 'W') || ft_strchr(s->map, 'E')))
		return (-1);
	if (s->x > XMAX)
		s->x = XMAX;
	if (s->y > YMAX)
		s->y = YMAX;
	return (1);
}