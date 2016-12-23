#include "get_next_line.h"

int get_next_line(int const fd, char **line)
{
	ssize_t ret;
	char *str;
	char ch[BUFF_SIZE + 1];

	if ((ret = read(fd, ch, BUFF_SIZE + 1)) > 0)
	{
		if ( != '\n')
		{
			ch[ret] = '\0';
			str = ch;
			printf("%s", str);
		}
	}
	return (1);
}

int main(int argc, char **argv)
{
	int fd;
	char *line = NULL;

	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		get_next_line(fd, &line);
	}
	return (0);
}