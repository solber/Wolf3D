/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnoth <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 09:54:31 by wnoth             #+#    #+#             */
/*   Updated: 2017/11/09 09:54:38 by wnoth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void *elem;

	elem = NULL;
	if (size <= 0)
		return (NULL);
	if (!(elem = malloc(size)))
		return (NULL);
	ft_bzero(elem, size);
	return (elem);
}
