/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clopez-m <clopez-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 18:13:13 by clopez-m          #+#    #+#             */
/*   Updated: 2020/02/10 18:13:13 by clopez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t hayc;
	size_t needc;

	if (!*needle)
		return ((char *)haystack);
	hayc = 0;
	while (*(haystack + hayc) != 0 && hayc < len)
	{
		needc = 0;
		while (*(haystack + hayc + needc) == *(needle + needc) &&
				hayc + needc < len && *(needle + needc) != 0)
		{
			if (*(needle + needc + 1) == 0)
				return ((char *)(haystack + hayc));
			else
				needc++;
		}
		hayc++;
	}
	return (0);
}
