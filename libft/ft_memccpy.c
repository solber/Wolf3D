/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnoth <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 09:42:08 by wnoth             #+#    #+#             */
/*   Updated: 2017/11/08 09:42:10 by wnoth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	const unsigned char	*src1;
	unsigned char		l;
	unsigned char		*res;

	src1 = (const unsigned char *)src;
	l = (unsigned char)c;
	res = (unsigned char *)dst;
	while (n--)
		if (((*res++ = *src1++) == l))
			return (res);
	return (NULL);
}
