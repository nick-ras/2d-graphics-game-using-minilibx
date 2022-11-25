# include "../so_long.h"

int get_fd(char *argv)
{
	int fd;

	fd = open(argv, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("fd error from first open\n");
		exit (1);
	}
	return (fd);
}

void	check_and_malloc(t_map *grid, char *argv)
{
	int		fd;
	char	*line_as_str;
	int	i;

	fd = get_fd(argv);
	line_as_str = get_next_line(fd);
	i = 0;
	while (line_as_str[i] != '\n' && line_as_str[i] != '\0')
		i++;
	grid->columns = i;
	ft_printf("grid->columns %d\n", grid->columns);
	while (line_as_str)
	{
		line_as_str[grid->columns] = '\0';
	 	//ft_printf("%s %d %d\n", line_as_str, ft_strlen(line_as_str), grid->columns);
		if ((int)ft_strlen(line_as_str) != grid->columns)
		{
			ft_printf("line not same length as start line\n");
			free_map(grid, 1);
		}
		free(line_as_str);
		line_as_str = get_next_line(fd);
		grid->rows++;
	}
	ft_printf("grid->rows = %d\n", grid->rows);
	close(fd);
	if (grid->rows < 4 || grid->columns < 4 || grid->rows == grid->columns)
	{
		ft_printf("not enough rows or columns or map is not a rectangle");
		exit (1);
	}
}

void	filename_check(char *map)
{
	char	*ptr;
	//ft_printf("name %s length%d \n", map, ft_strlen(map));
	if (ft_strnstr(map, ".ber", ft_strlen(map)) == NULL)
	{
		ft_printf("name not correct\n");
		exit (1);
	}
	ptr = ft_memchr(map, '.', ft_strlen(map));
	if (*(ptr + 4 ) !=  '\0')
	{
		ft_printf("char after '.ber'\n");
		exit (1);
	}
	if (ptr ==  map)
	{
		ft_printf("char(s) missing before '.ber'\n");
		exit (1);
	}
}