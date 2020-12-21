/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhogg <mhogg@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 21:29:20 by mhogg             #+#    #+#             */
/*   Updated: 2020/12/20 14:14:28 by mhogg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_check_remain(char *remain, char **line)
{
	char	*end;

	*line = (malloc(1));
	(*line)[0] = '\0';
	end = NULL;
	if ((end = ft_strchr(remain, '\n')))
	{
		*end = '\0';
		*line = ft_strjoin(*line, remain);
		ft_strcpy(remain, ++end);
	}
	else
		*line = ft_strjoin(*line, remain);
	return (end);
}

int		get_next_line(int fd, char **line)
{
	char		buff[BUFFER_SIZE + 1];
	int			rb;
	char		*end;
	static char	remain[256][BUFFER_SIZE + 1];

	rb = 1;
	if (line == NULL || read(fd, 0, 0) < 0)
		return (-1);
	end = ft_check_remain(remain[fd], line);
	while (!end && (rb = read(fd, buff, BUFFER_SIZE)))
	{
		buff[rb] = '\0';
		if ((end = ft_strchr(buff, '\n')))
		{
			*end = '\0';
			ft_strcpy(remain[fd], ++end);
		}
		if (!(*line = ft_strjoin(*line, buff)))
			return (-1);
	}
	if (rb == 0)
	{
		remain[fd][rb] = '\0';
		return (0);
	}
	return (1);
}
