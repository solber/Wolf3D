/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnoth <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/08 09:06:50 by wnoth             #+#    #+#             */
/*   Updated: 2017/08/10 09:27:33 by wnoth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*d;

	d = (char *)malloc(sizeof(char) * (ft_strlen(src) + 1));
	if (d == NULL)
		return (NULL);
	ft_strcpy(d, src);
	return (d);
}
