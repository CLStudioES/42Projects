/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clopez-m <clopez-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 17:48:38 by clopez-m          #+#    #+#             */
/*   Updated: 2019/11/25 20:23:38 by clopez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int		free_cache(char **buffer, int str)
{
	if (*buffer)
	{
		free(*buffer);
		*buffer = 0;
	}
	return (str);
}

static int		extract(char **line, char **buffer, int idx)
{
	char				*aux;
	int					str;

	if (idx >= 0)
	{
		if (!(*line = ft_substr(*buffer, 0, idx)))
			return (free_cache(buffer, -1));
		if (!(aux = ft_substr(*buffer, idx + 1, ft_strlen(*buffer) - idx - 1)))
			return (free_cache(buffer, -1));
		str = 1;
	}
	else
	{
		if (!(*line = ft_substr(*buffer, 0, ft_strlen(*buffer))))
			return (free_cache(buffer, -1));
		aux = 0;
		str = 0;
	}
	free_cache(buffer, 0);
	*buffer = aux;
	return (str);
}

void			auxiliar(char *buff, char **buffer, char **aux)
{
	if (!*buffer)
		*buffer = ft_strdup(buff);
	else
	{
		*aux = ft_strjoin(*buffer, buff);
		free(*buffer);
		*buffer = *aux;
	}
}

int				get_next_line(int fd, char **line)
{
	ssize_t				r_size;
	char				buff[BUFFER_SIZE + 1];
	static char			*buffer;
	char				*aux;

	if (fd < 0 || !line || BUFFER_SIZE < 1)
		return (free_cache(&buffer, -1));
	while ((r_size = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[r_size] = '\0';
		auxiliar(buff, &buffer, &aux);
		if (position(buffer) != -1)
			break ;
	}
	if (r_size < 0)
		return (free_cache(&buffer, -1));
	if (r_size == 0 && (!buffer || *buffer == '\0') && (*line = ft_strdup("")))
		return (free_cache(&buffer, 0));
	return (extract(line, &buffer, position(buffer)));
}
