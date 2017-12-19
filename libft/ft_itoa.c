/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnoth <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 10:16:04 by wnoth             #+#    #+#             */
/*   Updated: 2017/11/13 10:16:47 by wnoth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_intlen(int n, size_t *len, int *weight)
{
	*len = 1;
	if (n >= 0)
	{
		*len = 0;
		n = -n;
	}
	*weight = 1;
	while (n / *weight < -9)
	{
		*weight *= 10;
		*len += 1;
	}
}

char		*ft_itoa(int n)
{
	char	*conv;
	size_t	len;
	int		weight;
	size_t	current;

	ft_intlen(n, &len, &weight);
	if ((conv = ft_strnew(len + 1)) == NULL)
		return (NULL);
	current = 0;
	if (n < 0)
		conv[current++] = '-';
	if (n > 0)
		n = -n;
	while (weight >= 1)
	{
		conv[current++] = -(n / weight % 10) + 48;
		weight /= 10;
	}
	return (conv);
}
