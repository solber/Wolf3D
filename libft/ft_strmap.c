/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnoth <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 09:55:17 by wnoth             #+#    #+#             */
/*   Updated: 2017/11/09 09:56:23 by wnoth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*res;
	int		i;

	if (!s)
		return (NULL);
	i = -1;
	if (!(res = ft_strnew(ft_strlen(s))))
		return (NULL);
	while (*(s + ++i))
		*(res + i) = f(*(s + i));
	return (res);
}
