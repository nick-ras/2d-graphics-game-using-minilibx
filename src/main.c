#include "../so_long.h"
//gcc src/main.c libftprintf/libftprintf.a gnl/get_next_line.c gnl/get_next_line_utils.c && ./a.out src/map.ber


int	dfs(char **grid, int count_row, int count_col)
{
	int rows;
	int columns;

	rows = ft_strlen(grid);
	columns = ft_strlen(grid[0];
	if (count_row < 0 || count_row >= rows)
		return;
	if (count_col < 0 || count_col >= columns)
		return;
	if (grid[count_row][count_col] == '0')
		return;
	
	grid[count_row][count_col] = '0';
	dfs(grid, count_row - 1, count_col);
	dfs(grid, count_row + 1, count_col);
	dfs(grid, count_row, count_col - 1);
	dfs(grid, count_row, count_col + 1);
}

int numIslands(char **grid, int rows, int columns)
{
	int i  = 0;
	int j = 0;
	while (grid[i] != NULL)
	{
		while(grid[i][j] != NULL)
		{
			if (j != '0' || j != 'C' || j != 'P')
				dfs(grid, i, j);
			j++;
		}
		i++;
	}
}

char	**get_map_using_gnl(int argc, char *argv)
{
	int fd = open(argv, O_RDONLY);
	char *line_as_str = get_next_line(fd);
	int nb_lines = 0;
	int line_length = ft_strlen(line_as_str) - 1;

	while(line_as_str)
	{
		ft_printf("%s", line_as_str);
		free(line_as_str);
		line_as_str = get_next_line(fd);
		nb_lines++;
	}
	ft_printf(" line_length %d nb_lines %d\n", line_length, nb_lines);
	close(fd);
	fd = open(argv, O_RDONLY);
	
	char **grid = ft_calloc(line_length, sizeof(char));
	int i = 0;

	while (i < nb_lines)
	{
		grid[i] = ft_calloc(line_length, sizeof(char));
		grid[i] = get_next_line(fd);
		ft_printf("malloced space fir %d= %s", i, grid[i]);
		i++;
	}
	printf("\n argc %d", argc);
	close(fd);
	numIslands(grid, nb_lines, line_length);
	return (grid);
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
	char ** grid = get_map_using_gnl(argc, argv[1]);
}
