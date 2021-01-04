/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhogg <mhogg@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 21:29:20 by mhogg             #+#    #+#             */
/*   Updated: 2021/01/03 20:23:50 by mhogg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_free_all(char **buff, char **remain, char **line)
{
	if (*line)
		free(*line);
	if (*buff)
		free(*buff);
	if (*remain)
		free(*remain);
	return (-1);
}

int	ft_fill_line(char *str, char *remain, char **line)
{
	char	*end;
	int		a;

	a = 0;
	if ((end = ft_strchr(str, '\n')))
	{
		*end = '\0';
		if (!(*line = ft_strjoin(*line, str)))
			return (-1);
		ft_strcpy(remain, ++end);
		a = 1;
	}
	else	if (!(*line = ft_strjoin(*line, str)))
		return (-1);
	return (a);
}

int	ft_free_remain(char **remain)
{
	if (*remain)
	{
		free(*remain);
		*remain = NULL;
	}
	return (0);
}

int	get_next_line(int fd, char **line)
{
	char		*buff;
	static char	*remain;
	int			rb;
	int			flag;

	rb = 1;
	*line = malloc(1);
	buff = malloc(BUFFER_SIZE + 1);
	if (!remain)
		remain = malloc(BUFFER_SIZE + 1);
	if (BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0 || !*line || !buff || !remain)
		return (ft_free_all(&buff, &remain, line));
	ft_bzero(buff, BUFFER_SIZE + 1);
	**line = '\0';
	if ((flag = ft_fill_line(remain, remain, line)) == -1)
		return (ft_free_all(&buff, &remain, line));
	while (!flag && (rb = read(fd, buff, BUFFER_SIZE)))
	{
		buff[rb] = '\0';
		if ((flag = ft_fill_line(buff, remain, line)) == -1)
			return (ft_free_all(&buff, &remain, line));
	}
	free(buff);
	if (rb == 0)
		return(ft_free_remain(&remain));
	return (1);
}
