#include "../so_long.h"
//make re  && ./a.out src/map.ber

void	fill_map2(t_map *grid, char *argv)
{
int row_count;
	int	fd2;

	fd2 = open(argv, O_RDONLY);
	if (fd2 < 0)
	{
		ft_printf("fd error\n");
		free_map(grid, 1);
	}
	grid->map2 = ft_calloc(grid->rows + 1, sizeof(char *));
	grid->map2[grid->rows] = NULL;
	row_count = 0;
	while (row_count < grid->rows)
	{
		grid->map2[row_count] = get_next_line(fd2);
		if (grid->map2[row_count] == NULL)
		{
		ft_printf("rows is NULL\n");
		free_map(grid, 1);
		}	
		grid->map[row_count][grid->columns] = '\0';
		row_count++;
	}
	// row_count = 0;
	// while (row_count < grid->rows)
	// {
	// 	ft_printf("TEST map2 %s", grid->map2[row_count]);
	// 	ft_printf("TEST map1 again %s\n", grid->map[row_count]);
	// 	row_count++;
	// }
	close(fd2);
}

void fill_map (t_map *grid, char *argv)
{
	int row_count;
	int	fd;

	fd = open(argv, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("fd error\n");
		free_map(grid, 1);
	}
	grid->map = ft_calloc(grid->rows + 1, sizeof(char *));
	row_count = 0;
	while (row_count < grid->rows)
	{
		grid->map[row_count] = get_next_line(fd);
		grid->map[row_count][grid->columns] = '\0';
		// ft_printf("fill_map %d", ft_strlen(grid->map[row_count]));
		row_count++;
	}
	close(fd);
	fill_map2(grid, argv);
}

void	parse_map(t_map *grid)
{
	int	img_height;
	int	img_width;

	grid->player = mlx_xpm_file_to_image(grid->mlx_ptr,
			PLAYER, &img_width, &img_height);
	grid->wall = mlx_xpm_file_to_image(grid->mlx_ptr,
			WALL, &img_width, &img_height);
	grid->space = mlx_xpm_file_to_image(grid->mlx_ptr,
			EMPTY_SPACE, &img_width, &img_height);
	grid->door = mlx_xpm_file_to_image(grid->mlx_ptr,
			EXIT, &img_width, &img_height);
	grid->collectible = mlx_xpm_file_to_image(grid->mlx_ptr,
			COLLECT, &img_width, &img_height);
	grid->winner = mlx_xpm_file_to_image(grid->mlx_ptr,
			WIN, &img_width, &img_height);
}

int main(int argc, char *argv[])
{
	t_map	*grid;

	if (argc != 2)
	{
		ft_printf("argc not 2\n");
		return (1);
	}
	filename_check(argv[1]);
	grid = init_map(grid);
	check_and_malloc(grid, argv[1]);
	fill_map(grid, argv[1]);
	check_squares(grid);
	wall_check(grid);
	char_check(grid);
	// grid->filename = *argv;
	grid->mlx_ptr = mlx_init();
	if (grid->mlx_ptr == NULL)
	{
		ft_printf("mlx_init err\n");
		free_map(grid, 1);
	}
	grid->win_ptr = mlx_new_window(grid->mlx_ptr, grid->columns * 40,	\
	grid->rows * 40, "My window");
	if (grid->win_ptr == NULL)
	{
		free(grid->win_ptr);
		ft_printf("grid->win_ptr error\n");
		free_map(grid, 1);
	}
	parse_map(grid);
	put_images_on_picture(grid);
	mlx_hook(grid->win_ptr, 17, 0, no_event, &grid); //better then key_hook
	mlx_hook(grid->win_ptr, 02, 0, key_press, &grid);
	mlx_loop(grid->mlx_ptr);

	free_map(grid, 0);
	return (0);
}
