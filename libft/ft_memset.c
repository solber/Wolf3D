/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnoth <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 09:42:36 by wnoth             #+#    #+#             */
/*   Updated: 2017/11/08 09:42:44 by wnoth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*res;

	if (!n)
		return (s);
	res = (unsigned char *)s;
	while (n--)
	{
		*res = (unsigned char)c;
		if (n)
			res++;
	}
	return (s);
}
