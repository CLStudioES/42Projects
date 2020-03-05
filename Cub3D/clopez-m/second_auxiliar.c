/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   second_auxiliar.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clopez-m <clopez-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 18:44:18 by clopez-m          #+#    #+#             */
/*   Updated: 2020/03/03 18:46:40 by clopez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

static	void	resolution_getter(char *temp, t_variables *s)
{
	int		i;
	int		aux;
	char	*temp2;

	i = 0;
	while (!(ft_isdigit(temp[i])))
		i++;
	aux = i;
	while (ft_isdigit(temp[i]))
		i++;
	temp2 = ft_substr(temp, aux, i);
	s->x = ft_atoi(temp2);
	free(temp2);
	while (temp[i] == ' ')
		i++;
	aux = i;
	while (ft_isdigit(temp[i]))
		i++;
	temp2 = ft_substr(temp, aux, i);
	s->y = ft_atoi(temp2);
	free(temp2);
}

static	char	*str_getter(char *temp)
{
	while (*temp != '.')
		temp++;
	return (temp);
}

static	char	*color_getter(char *temp)
{
	while (!(ft_isdigit(*temp)))
		temp++;
	return (temp);
}

void			line_getter(t_variables *s, char *temp, char *buffer)
{
	char *temp2;

	temp = ft_strjoin(buffer, "\n");
	temp2 = s->map;
	s->map = ft_strjoin(s->map, temp);
	free(temp2);
	free(temp);
}

void			info_controller(t_variables *s, char *buffer)
{
	char	*temp;
	int		len;

	len = ft_strlen(buffer);
	if ((temp = ft_strchr(buffer, 'R')))
		resolution_getter(buffer, s);
	else if ((temp = ft_strnstr(buffer, "NO", len)))
		s->no = ft_strdup(str_getter(buffer));
	else if ((temp = ft_strnstr(buffer, "SO", len)))
		s->so = ft_strdup(str_getter(buffer));
	else if ((temp = ft_strnstr(buffer, "WE", len)))
		s->we = ft_strdup(str_getter(buffer));
	else if ((temp = ft_strnstr(buffer, "EA", len)))
		s->ea = ft_strdup(str_getter(buffer));
	else if ((temp = ft_strnstr(buffer, "S .", len)))
		s->s = str_getter(buffer);
	else if ((temp = ft_strchr(buffer, 'F')))
		s->f = color_getter(buffer);
	else if ((temp = ft_strchr(buffer, 'C')))
		s->c = color_getter(buffer);
	else if ((temp = ft_strchr(buffer, '1')))
		line_getter(s, temp, buffer);
}