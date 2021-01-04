#include "get_next_line.h"

int	main(void)
{
	char	*line;
	int		fd;
	int		a;
	char 	*txt = "/Users/mhogg/gnl2/GNL_lover/test_files_GNL/test_file10";

	fd = open(txt, O_RDONLY);
	while((a = get_next_line(fd, &line)) > 0)
	{
		printf("%d: %s\n", a, line);
		free (line);
	}
	printf("%d: %s\n", a, line);
	free (line);

	/*fd = open("myfile3.txt", O_RDONLY);
	while((a = get_next_line(fd, &line)))
	{
		printf("%d: %s\n", a, line);
		free (line);
	}
	printf("%d: %s\n", a, line);
	free (line);*/
	//while (1) {}
    return (0);
}
