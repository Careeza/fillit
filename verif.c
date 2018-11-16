#include <stdio.h>
#include "libft.h"

int main(int argc, const char *argv[])
{
	int		ret;
	int		fd;
	char	*line;

	fd = open(argv[1], O_RDONLY);
	while (get_next_line(fd, &line) > 0)
		printf("%s\n", line);
	return 0;
}
