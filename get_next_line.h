# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>

int		get_next_line(int fd, char **line);
int		ft_strlen (const char *str);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strchr(const char *s, int c);
size_t	ft_strcpy(char *dst, const char *src);

#endif

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 32
#endif
