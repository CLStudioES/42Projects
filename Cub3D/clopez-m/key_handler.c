/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clopez-m <clopez-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 18:12:31 by clopez-m          #+#    #+#             */
/*   Updated: 2020/03/03 19:39:15 by clopez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	w_and_s(t_variables *s)
{
	if (s->presedw == 1)
	{
		if ((s->mapn[(int)(s->posx + s->dirx *
			(s->movespeed + 0.6))][(int)s->posy]) != 1)
			s->posx += s->dirx * s->movespeed;
		if ((s->mapn[(int)s->posx][(int)(s->posy + s->diry *
			(s->movespeed + 0.6))]) != 1)
			s->posy += s->diry * s->movespeed;
	}
	if (s->preseds == 1)
	{
		if ((s->mapn[(int)(s->posx - s->dirx *
			(s->movespeed + 0.6))][(int)s->posy]) != 1)
			s->posx -= s->dirx * s->movespeed;
		if ((s->mapn[(int)s->posx][(int)(s->posy -
			s->diry * (s->movespeed + 0.6))]) != 1)
			s->posy -= s->diry * s->movespeed;
	}
}

void	a_and_d(t_variables *s)
{
	if (s->preseda == 1)
	{
		if ((s->mapn[(int)(s->posx - s->diry *
			(s->movespeed + 0.6))][(int)s->posy]) != 1)
			s->posx -= s->diry * s->movespeed;
		if ((s->mapn[(int)s->posx][(int)(s->posy +
			s->dirx * (s->movespeed + 0.6))]) != 1)
			s->posy += s->dirx * s->movespeed;
	}
	if (s->presedd == 1)
	{
		if ((s->mapn[(int)(s->posx + s->diry *
			(s->movespeed + 0.6))][(int)s->posy]) != 1)
			s->posx += s->diry * s->movespeed;
		if ((s->mapn[(int)s->posx][(int)(s->posy -
			s->dirx * (s->movespeed + 0.6))]) != 1)
			s->posy -= s->dirx * s->movespeed;
	}
}

void	l_and_r(t_variables *s)
{
	if (s->presedl == 1)
	{
		s->olddirx = s->dirx;
		s->dirx = s->dirx * cos(s->rotspeed) - s->diry * sin(s->rotspeed);
		s->diry = s->olddirx * sin(s->rotspeed) + s->diry * cos(s->rotspeed);
		s->oldplanex = s->planex;
		s->planex = s->planex * cos(-s->rotspeed)
			- s->planey * sin(s->rotspeed);
		s->planey = s->oldplanex * sin(s->rotspeed)
			+ s->planey * cos(-s->rotspeed);
	}
	if (s->presedr == 1)
	{
		s->olddirx = s->dirx;
		s->dirx = s->dirx * cos(-s->rotspeed) - s->diry * sin(-s->rotspeed);
		s->diry = s->olddirx * sin(-s->rotspeed) + s->diry * cos(-s->rotspeed);
		s->oldplanex = s->planex;
		s->planex = s->planex * cos(-s->rotspeed) -
			s->planey * sin(-s->rotspeed);
		s->planey = s->oldplanex * sin(-s->rotspeed)
			+ s->planey * cos(-s->rotspeed);
	}
}

int		key_handler(t_variables *s)
{
	first_raycast(s);
	w_and_s(s);
	a_and_d(s);
	l_and_r(s);
	if (s->presedesq == 1)
	{
		system("exit CUB3D");
		exit(1);
	}
	return (1);
}