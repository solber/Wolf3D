/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnoth <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 12:26:49 by wnoth             #+#    #+#             */
/*   Updated: 2017/11/09 12:26:51 by wnoth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(char str)
{
	if ((str == '\n') || (str == '\t') || (str == '\v') ||
			(str == ' ') || (str == '\f') || (str == '\r'
			|| str == '0'))
		return (1);
	return (0);
}

int			ft_atoi(const char *str)
{
	int		i;
	int		nbr;
	int		negative;
	int		j;

	j = 0;
	nbr = 0;
	negative = 0;
	i = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-')
		negative = 1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] && (str[i] >= '0') && (str[i] <= '9'))
	{
		if (j > 10 && negative)
			return (0);
		else if (j++ > 10)
			return (-1);
		nbr = (nbr * 10) + (str[i] - '0');
		i++;
	}
	return (negative ? -nbr : nbr);
}
