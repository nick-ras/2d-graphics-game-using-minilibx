#include "../so_long.h"
//gcc src/main.c ../libftprintf/libftprintf.a ../gnl/get_next_line.c ../gnl/get_next_line_utils.c && ./a.out src/map.ber 

char **get_map_using_gnl(int argc, char *argv)
{
	int fd1 = open(argv, O_RDONLY);

	char *str = get_next_line(fd1);
	int width = 0;
	int length = ft_strlen(str) - 1;
	while(str)
	{
		ft_printf("%s", str);
		free(str);
		str = get_next_line(fd1);
		width++;
	}
	ft_printf(" length %d width %d\n", length, width);
	close(fd1);
	fd1 = open(argv, O_RDONLY);
	char **arrmap = ft_calloc(length, sizeof(char));
	while (length)
	{
		ft_calloc()
		ft_printf("%s", str);
		str[i]
		free(str);
		str = get_next_line(fd);
		length--;
	}
}

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		ft_printf("argc == 2 or under\n");
		return 0;
	}
	ft_printf("%s\n", argv[1]);
	//test of name of map is..

	get_map_using_gnl(argc, argv[1]);
	
}
