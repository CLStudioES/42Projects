/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clopez-m <clopez-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 15:32:23 by clopez-m          #+#    #+#             */
/*   Updated: 2019/11/26 16:56:09 by clopez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

int				get_next_line(int fd, char **line);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_substr(const char *s, unsigned int start, ssize_t len);
size_t			ft_strlen(const char *str);
char			*ft_strdup(const char *s1);
ssize_t			position(char *s);

#endif
