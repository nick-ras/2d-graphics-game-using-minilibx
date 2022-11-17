#include "../so_long.h"
//gcc src/main.c libftprintf/libftprintf.a gnl/get_next_line.c gnl/get_next_line_utils.c && ./a.out src/map.ber


void	dfs(t_map *grid, int count_row, int count_col)
{
	if (count_row < 0 || count_row >= grid->rows)
		return;
	if (count_col < 0 || count_col >= grid->columns)
		return;
	if (grid->map2[count_row][count_col] == '1')
		return;
	
	//extra array in struct
	grid->map2[count_row][count_col] = '0';
	dfs(grid, count_row - 1, count_col);
	dfs(grid, count_row + 1, count_col);
	dfs(grid, count_row, count_col - 1);
	dfs(grid, count_row, count_col + 1);
}

void check_path_to_exit(t_map *grid)
{
	int row_count  = 0;
	int col_count = 0;
	while (grid->map[row_count] != NULL)
	{
		while(col_count < grid->columns)
		{
			if (col_count == 'P')
			{
				grid->entrance[0] = row_count;
				grid->entrance[1] = col_count;
			}
			if (col_count != '0' || col_count != 'C' || col_count != 'P')
				dfs(grid, row_count, col_count);
			col_count++;
		}
		row_count++;
	}
}

t_map *get_map_using_gnl(int argc, char *argv)
{
	t_map *grid;
	int fd = open(argv, O_RDONLY);
	char *line_as_str = get_next_line(fd);
	
	grid = ft_calloc(1, sizeof(t_map));
	grid->columns = ft_strlen(line_as_str) - 1;
	while(line_as_str)
	{
		ft_printf("%s", line_as_str);
		free(line_as_str);
		line_as_str = get_next_line(fd);
		grid->rows++;
	}
	ft_printf(" columns %d rows %d\n", grid->columns, grid->rows);
	close(fd);
	fd = open(argv, O_RDONLY);
	
	grid->map = ft_calloc(grid->rows, sizeof(char));
	int row_count = 0;

	while (row_count < grid->rows)
	{
		grid->map[row_count] = ft_calloc(grid->columns, sizeof(char));
		grid->map[row_count] = get_next_line(fd);
		grid->map2[row_count] = ft_calloc(grid->columns, sizeof(char));
		grid->map2[row_count] = grid->map[row_count];
		ft_printf("argc %d malloced space for %d= %s", argc, row_count, grid[row_count]);
		row_count++;
	}
	close(fd);
	check_path_to_exit(grid);
	return (grid);
}

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		ft_printf("argc == 2 or under\n");
		return 1;
	}
	ft_printf("%s\n", argv[1]);
	//test of name of map is..
	get_map_using_gnl(argc, argv[1]);
	return 0;
}
