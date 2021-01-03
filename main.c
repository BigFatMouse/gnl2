#include "get_next_line.h"

int	main(void)
{
	char	*line;
	int		fd;
	int		a;
	char 	*txt = "myfile.txt";

	fd = open(txt, O_RDONLY);
	while((a = get_next_line(fd, &line)))
	{
		printf("%d: %s\n", a, line);
		free (line);
	}
	printf("%d: %s\n", a, line);
	free (line);
    //while(1); 
    return (0);
}