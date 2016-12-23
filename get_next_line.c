#include "get_next_line.h"
#include "libft/libft.h"

int get_next_line(int const fd, char **line)
{
	int ret;
	int flag = 0;;
	static char *down;
	char chr[2];

	down = ft_strnew(1);
	if (*line == NULL || fd < 0)
		return (-1);
	while ((ret = read(fd, chr, 1)) > 0)
	{
		flag = 1;
		if (*chr == '\n')
			break ;
		down = ft_strjoin(down, chr);
	}
	if (ret < 0)
		return (-1);
	if (ret > 0)
		*line = down;
	return (flag);
}

int main(int argc, char **argv)
{
	int fd;
	char *line = NULL;

	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		printf("%d\n", get_next_line(fd, &line));
	}
	close (fd);
	return (0);
}
