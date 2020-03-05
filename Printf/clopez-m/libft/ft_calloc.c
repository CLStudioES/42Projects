/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clopez-m <clopez-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 18:07:19 by clopez-m          #+#    #+#             */
/*   Updated: 2020/02/10 18:07:23 by clopez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void *mptr;

	mptr = malloc(count * size);
	if (mptr == NULL)
		return (mptr);
	ft_bzero(mptr, size * count);
	return (mptr);
}
