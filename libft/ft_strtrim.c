/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnoth <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 11:49:16 by wnoth             #+#    #+#             */
/*   Updated: 2017/11/09 11:49:18 by wnoth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(char c)
{
	if (c == ' ' || c == '\t' || c == '\n')
		return (1);
	else
		return (0);
}

static int	ft_splitspaces(char *str, int *i, size_t *j)
{
	while (ft_isspace(*(str + *i)))
		(*i)++;
	while (ft_isspace(*(str + *j)))
		(*j)--;
	if (*i || *j < ft_strlen(str))
		return (1);
	return (0);
}

char		*ft_strtrim(char const *s)
{
	char	*res;
	size_t	j;
	size_t	new_size;
	int		k;
	int		i;

	if (!s)
		return (NULL);
	i = 0;
	k = 0;
	j = ft_strlen(s) - 1;
	if (!ft_splitspaces((char *)s, &i, &j) || !ft_strlen(s))
		return ((char *)s);
	new_size = (i == (int)ft_strlen(s)) ? 0 : ft_strlen(s) - (size_t)i - \
	(ft_strlen(s) - j);
	res = ft_strnew(new_size + 1);
	if (!res)
		return (NULL);
	while (i <= (int)j)
		*(res + k++) = *(s + i++);
	return (res);
}
