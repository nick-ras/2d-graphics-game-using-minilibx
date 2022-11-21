#include "../so_long.h"
//gcc src/main.c libftprintf/libftprintf.a gnl/get_next_line.c gnl/get_next_line_utils.c && ./a.out src/map.ber

void	init_grid(t_map *grid)
{
	grid->S_count = 0;
	grid->D_count = 0;
	grid->collectibles = 0;
	grid->door_check_recursive = 0;
	grid->S[0] = 0;
	grid->S[1] = 0;
	grid->D[0] = 0;
	grid->D[1] = 0;
}

void start(t_map *grid, int row_count, int col_count)
{
	if (grid->map[row_count][col_count] == 'S')
	{
		if (grid->S_count != 0)
		{
			ft_printf("too many entrances\n");
			exit (1);
		}
		grid->S[0] = row_count;
		grid->S[1] = col_count;
		grid->S_count++;
	}
}

void door(t_map *grid, int row_count, int col_count)
{
	if (grid->map[row_count][col_count] == 'D')
	{
		if (grid->D_count != 0)
		{
			ft_printf("too many doors\n");
			exit(1);
		}
		grid->D[0] = row_count;
		grid->D[1] = col_count;
		// ft_printf("door %d and %d \n", grid->D[0], grid->D[1]);
		grid->D_count++;
	}
}

void collectibles(t_map *grid, int row_count, int col_count)
{
	if (grid->map[row_count][col_count] == 'C')
		grid->collectibles++;
}

int	dfs(t_map *grid, int count_row, int count_col, int door)
{
	//ft_printf("row %d col %d and inside: %c\n", count_row, count_col, grid->map2[count_row][count_col]);
	if (count_row < 0 || count_row >= grid->rows || count_col < 0 || count_col >= grid->columns)
	{
		ft_printf("missing barrier\n");
		exit (1);
	}
	if (grid->map2[count_row][count_col] == '1')
		return door;
	if (grid->map2[count_row][count_col] == 'D')
		door++;
	grid->map2[count_row][count_col] = '1';
	door = dfs(grid, count_row - 1, count_col, door);
	door = dfs(grid, count_row + 1, count_col, door);
	door = dfs(grid, count_row, count_col - 1, door);
	door = dfs(grid, count_row, count_col + 1, door);
	return door;
}

void free_map(char **map, int rows)
{
	int i;

	i = 0;
	while (i < rows)
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void check_map(t_map *grid)
{
	int	row_count;
	int	col_count;
	
	init_grid(grid);
	row_count = 0;
	while (row_count < grid->rows)
	{
		col_count = 0;
		while (col_count < grid->columns)
		{
			start(grid, row_count, col_count);
			door(grid, row_count, col_count);
			collectibles(grid, row_count, col_count);
			col_count++;
		}
		row_count++;
	}
	if (grid->D_count < 1 || grid->S_count < 1 || grid->collectibles < 1)
	{
		ft_printf("missing smth. Start: = %d, door: %d, collectible: %d\n", grid->S_count, grid->D_count, grid->collectibles);
		exit (1);
	}
	int door = 0;
	door = dfs(grid, grid->S[0], grid->S[1], door);
	ft_printf("\ndoor check after %d\n", door);
	if (door < 0)
	{
		ft_printf("missing barrier(s)%d\n", grid->door_check_recursive);
		exit (1);
	}
	if (door < 1)
	{
		ft_printf("player cant go to exit, doors%d\n", grid->door_check_recursive);
		exit (1);
	}
	free_map(grid->map2, grid->rows);
}

t_map *make_grid(t_map *grid, char *argv)
{
	int row_count = 0;
	int	fd;

	fd = open(argv, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("fd error\n");
		exit (1);
	}
	grid->map = ft_calloc(grid->rows + 1, sizeof(char));
	while (row_count < grid->rows)
	{
		grid->map[row_count] = ft_calloc(grid->columns, sizeof(char));
		grid->map[row_count] = get_next_line(fd);
		row_count++;
	}
	close(fd);
	row_count = 0;
	fd = open(argv, O_RDONLY);
	grid->map2 = ft_calloc(grid->rows, sizeof(char));
	while (row_count < grid->rows)
	{
		grid->map2[row_count] = ft_calloc(grid->columns, sizeof(char));
		grid->map2[row_count] = get_next_line(fd);
		row_count++;
	}
	close(fd);
	ft_printf("\nrows %d col %d\n", grid->rows, grid->columns);
	return grid;
}

t_map *get_map_using_gnl(char *argv)
{
	t_map *grid;
	int fd;
	char *line_as_str;

	fd = open(argv, O_RDONLY);
	ft_printf("%d", fd);
	if (fd < 0)
	{
		ft_printf("fd error from first open\n");
		exit (1);
	}
	line_as_str = get_next_line(fd);
	grid = ft_calloc(1, sizeof *grid);
	grid->columns = ft_strlen(line_as_str) - 1;
	while(line_as_str)
	{
	 	ft_printf("%s", line_as_str);
		free(line_as_str);
		line_as_str = get_next_line(fd);
		grid->rows++;
	}
	free(line_as_str);
	close(fd);
	if (grid->rows < 4 || grid->columns < 4 || grid->rows == grid->columns)
	{
		ft_printf("not enough rows or columns or not a rectangle");
		exit (1);
	}
	grid = make_grid(grid, argv);
	check_map(grid);
	return (grid);
}

void map_name_check(char *map)
{
	char	*ptr;
	ft_printf("name %s length%d \n", map, ft_strlen(map));
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

int main(int argc, char *argv[])
{
	t_map *grid;

	if (argc != 2)
	{
		ft_printf("argc == 2 or under\n");
		return 1;
	}
	map_name_check(argv[1]);
	grid = get_map_using_gnl(argv[1]);
	free_map(grid->map, grid->rows);
	free(grid);
	return 0;
}
