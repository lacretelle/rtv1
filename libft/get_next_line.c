/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madufour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 15:13:57 by madufour          #+#    #+#             */
/*   Updated: 2019/01/24 15:33:49 by madufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_read(char **tp, int fd)
{
	int		res;
	char	*tmp;
	char	buf[BUFF_SIZE + 1];

	tmp = 0;
	while ((res = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[res] = '\0';
		if (!(*tp))
		{
			if (!(*tp = ft_strdup(buf)))
				return (-1);
		}
		else
		{
			if (!(tmp = ft_strjoin_free(*tp, buf)))
				return (-1);
			*tp = tmp;
		}
		if ((ft_strchr(buf, '\n')))
			return (res);
	}
	return (res);
}

char	*ft_cursor(char *tmp, int i)
{
	char	*s;

	s = 0;
	if (tmp[i] == '\n')
	{
		if (!(s = ft_strdup(tmp + i + 1)))
			return (NULL);
	}
	else if (tmp[i] == '\0')
	{
		if (!(s = ft_strnew(0)))
			return (NULL);
	}
	ft_strdel(&tmp);
	tmp = s;
	return (tmp);
}

int		get_next_line(const int fd, char **line)
{
	static char *tmp[10240];
	size_t		k;
	int			res;

	if (fd < 0 || line == NULL)
		return (-1);
	*line = 0;
	if ((res = ft_read(&tmp[fd], fd)) < 0)
		return (-1);
	if (res == 0 && tmp[fd] == NULL)
		return (0);
	else if (res == 0 && tmp[fd][0] == '\0')
	{
		free(tmp[fd]);
		tmp[fd] = NULL;
		return (0);
	}
	k = 0;
	while (tmp[fd][k] != '\0' && tmp[fd][k] != '\n')
		k++;
	if (!(*line = ft_strsub(tmp[fd], 0, k)))
		return (-1);
	if (!(tmp[fd] = ft_cursor(tmp[fd], k)))
		return (-1);
	return (1);
}
