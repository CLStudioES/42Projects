/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clopez-m <clopez-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 19:06:33 by clopez-m          #+#    #+#             */
/*   Updated: 2019/11/18 14:00:54 by clopez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	start_check(char const *s1, char const *check)
{
	unsigned int			start;

	start = 0;
	while ((s1[start] != '\0') && (ft_strchr(check, (int)s1[start])))
	{
		start++;
	}
	return (start);
}

static int	end_check(char const *s1, char const *check, unsigned int start)
{
	unsigned int		end;

	end = ft_strlen(s1);
	while ((end > start) && (ft_strchr(check, (int)s1[end])))
	{
		end--;
	}
	return (end);
}

char		*ft_strtrim(char const *s1, char const *check)
{
	char				*ptr;
	int					start;
	int					end;
	int					counter;

	counter = 0;
	if (!s1)
		return (NULL);
	start = start_check(s1, check);
	end = end_check(s1, check, start);
	if (!(ptr = (char *)malloc((end - start + 2) * sizeof(char))))
		return (NULL);
	while (start <= end)
	{
		ptr[counter] = s1[start];
		start++;
		counter++;
	}
	ptr[counter] = '\0';
	return (ptr);
}
