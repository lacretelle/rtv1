/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaxime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 21:39:36 by cmaxime           #+#    #+#             */
/*   Updated: 2017/11/28 11:21:21 by cmaxime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include "libft.h"

# define BUFF_SIZE 32

typedef struct	s_read
{
	int		fd;
	int		pos;
	char	buff[BUFF_SIZE];
}				t_read;

int				get_next_line(const int fd, char **line);

#endif
