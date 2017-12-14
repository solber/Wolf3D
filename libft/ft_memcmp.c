/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnoth <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 14:56:12 by wnoth             #+#    #+#             */
/*   Updated: 2017/11/08 14:56:13 by wnoth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char *source1;
	unsigned char *source2;

	source1 = (unsigned char *)s1;
	source2 = (unsigned char *)s2;
	while (n--)
	{
		if (*source1 == *source2)
		{
			source1++;
			source2++;
		}
		else
			return (*source1 - *source2);
	}
	return (0);
}
