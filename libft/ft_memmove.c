/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnoth <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 14:56:45 by wnoth             #+#    #+#             */
/*   Updated: 2017/11/08 14:56:46 by wnoth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char			*dst1;
	const unsigned char		*src1;

	dst1 = (unsigned char *)dst;
	src1 = (const unsigned char *)src;
	if (src1 < dst1)
		while (len--)
			dst1[len] = src1[len];
	else
		ft_memcpy(dst1, src1, len);
	return (dst1);
}
