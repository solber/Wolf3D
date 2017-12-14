/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnoth <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 09:51:22 by wnoth             #+#    #+#             */
/*   Updated: 2017/11/20 09:51:25 by wnoth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
** reading file according to line
*/

static int		ft_read(char **s_line, int fd)
{
	int		ret;
	char	*s;
	char	buf[BUFF_SIZE + 1];

	if ((ret = read(fd, buf, BUFF_SIZE)) == -1)
		return (-1);
	buf[ret] = '\0';
	s = *s_line;
	*s_line = ft_strjoin(*s_line, buf);
	if (*s != 0)
		free(s);
	return (ret);
}

/*
** get line and maloc if needed
*/

static int		ft_get_line(char **s_line, char **line, char *s)
{
	int		i;
	char	*join;

	i = 0;
	if (*s == '\n')
		i = 1;
	*s = 0;
	*line = ft_strjoin("", *s_line);
	if (i == 0 && ft_strlen(*s_line) != 0)
	{
		*s_line = ft_strnew(1);
		return (1);
	}
	else if (i == 0 && !(ft_strlen(*s_line)))
		return (0);
	join = *s_line;
	*s_line = ft_strjoin(s + 1, "");
	free(join);
	return (i);
}

/*
** main func checking err getting cur line formating line
*/

int				get_next_line(int const fd, char **line)
{
	int			ret;
	char		*s;
	static char	*s_line;

	if (s_line == 0)
		s_line = "";
	if (!line || BUFF_SIZE < 1)
		return (-1);
	ret = BUFF_SIZE;
	while (line)
	{
		s = s_line;
		while (*s || ret < BUFF_SIZE)
		{
			if (*s == '\n' || *s == 0 || *s == -1)
				return (ft_get_line(&s_line, line, s));
			s++;
		}
		ret = ft_read(&s_line, fd);
		if (ret == -1)
			return (-1);
	}
	return (0);
}
