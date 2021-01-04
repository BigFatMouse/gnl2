/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhogg <mhogg@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/03 21:40:11 by mhogg             #+#    #+#             */
/*   Updated: 2021/01/04 00:08:30 by mhogg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int		ft_strlen(const char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len1;
	int		len2;
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	if (!(str = malloc(len1 + len2 + 1)))
		return (NULL);
	while (i < len1)
	{
		str[i] = s1[i];
		i++;
	}
	while (j < len2)
		str[i++] = s2[j++];
	str[i] = '\0';
	free((void *)s1);
	return (str);
}

char	*ft_strchr(const char *s, int c)
{
	int	n;
	int	i;

	i = 0;
	n = ft_strlen(s);
	if (c == '\0')
		return ((char*)s + n);
	while (i < n)
	{
		if (s[i] == c)
			return ((char*)s + i);
		i++;
	}
	return (NULL);
}

char	*ft_strdup(const char *s1)
{
	size_t	len;
	size_t	i;
	char	*str;

	i = 0;
	len = ft_strlen(s1);
	str = malloc(len + 1);
	if (str == NULL)
		return (NULL);
	while (i < len)
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

size_t	ft_strcpy(char *dst, const char *src)
{
	size_t	len;
	size_t	i;

	i = 0;
	len = ft_strlen(src);
	while (i < len)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (len);
}
