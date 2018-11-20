#include <stdio.h>
#include "libft.h"

int		ft_val(char **tetri, int i, int j, int k)
{
	int vic;

	while (++j <= i)
	{
		vic = 0;
		k = 0;
		while (tetri[j][k])
		{
			if (tetri[j][k] == '#')
			{
				if (k < 20 && tetri[j][k + 1] == '#')
					vic++;
				if (k > 0 && tetri[j][k - 1] == '#')
					vic++;
				if (k < 16 && tetri[j][k + 5] == '#')
					vic++;
				if (k > 4 && tetri[j][k - 5] == '#')
					vic++;
			}
			k++;
		}
		if (vic < 6)
			return (-1);
	}
	return (0);
}

void	ft_tetri(int fd, char **tetri, int i, int j)
{
	int k;
	char *line;

	while (get_next_line(fd, &line) > 0)
	{
		k = -1;
		if (line[0] == 0)
		{
			tetri[i][j + 1] = '\0';
			printf("%s\n", tetri[i]);
			i++;
			j = -1;
		}
		else
		{
			while (k < 4)
				tetri[i][++j] = line[++k];
			tetri[i][j] = '\n';
		}
	}
	tetri[i][j + 1] = '\0';
	printf("%s", tetri[i]);
	tetri[i + 1] = NULL;
}

int		ft_malloc(int fd, char **tetri, int i, const char *name)
{
	char	*line;
	int		j;
	int		k;

	close(fd);
	if (!(tetri = (char**)malloc(sizeof(char*) * (i + 2))))
		return (-1);
	j = 0;
	while (j <= i)
	{
		if (!(tetri[j] = (char*)malloc(sizeof(char) * (21))))
			return (-1);
		j++;
	}
	j = -1;
	close (fd);
	fd = open(name, O_RDONLY);
	ft_tetri(fd, tetri, 0, -1);
	return (ft_val(tetri, i, -1, 0));
}

int		ft_check(char *str, int i, int ret)
{
	static int cmt;
	static int cpt;

	if (str[0] != 0 && ret != 0)
	{
		cpt++;
		if (ft_strlen(str) != 4)
			return (-1);
		while (i < 4)
		{
			if (str[i] == '#')
				cmt++;
			if ((str[i] != '.' && str[i] != '#'))
				return (-1);
			i++;
		}
	}
	else
	{
		if (cmt != 4 || cpt != 4)
			return (-1);
		cmt = 0;
		cpt = 0;
		return (0);
	}
	return (0);
}


int		ft_gnl(int fd)
{
	char	*line;
	int		i;
	int		ret;

	i = 0;
	ret = 1;
	while (ret > 0)
	{
		ret = get_next_line(fd, &line);
		if (line[0] == 0)
			i++;
		if (ft_check(line, 0, ret) == -1)
			return (-1);
	}
	return(i);
}

int		main(int argc, const char *argv[])
{
	int		fd;
	char	**tetri;
	int		i;

	fd = open(argv[1], O_RDONLY);
	if ((i = ft_gnl(fd)) == -1)
	{
	write (2, "error\n", 6);
	return (0);
	}
	if (ft_malloc(fd, tetri, i, argv[1]) == -1)
	{
	write (2, "error\n", 6);
	return (0);
	}
	printf("nice\n");
	return 0;
}
