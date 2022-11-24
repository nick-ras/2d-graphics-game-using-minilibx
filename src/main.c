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

	ft_printf("BEFORE\n");
	grid->player = mlx_xpm_file_to_image(grid->mlx_ptr,
			PLAYER, &img_width, &img_height);
	ft_printf("HERE\n");
	grid->wall = mlx_xpm_file_to_image(grid->mlx_ptr,
			WALL, &img_width, &img_height);
	grid->space = mlx_xpm_file_to_image(grid->mlx_ptr,
			EMPTY, &img_width, &img_height);
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
	grid = allocate_and_check(argv[1]);
	grid->filename = *argv;
	grid->mlx_ptr = mlx_init();
	if (grid->mlx_ptr == NULL)
	{
		free(grid->mlx_ptr);
		ft_printf("mlx_init err\n");
		free_map(grid, 1);
	}
	parse_map(grid);
	grid->win_ptr = mlx_new_window(grid->mlx_ptr, grid->columns * 40,	\
	grid->rows * 40, "My window");
	if (grid->win_ptr == NULL)
	{
		free(grid->win_ptr);
		ft_printf("grid->win_ptr error\n");
		free_map(grid, 1);
	}

	// mlx_hook(data->win_ptr, 17, 0, ft_exit, &data);
	// mlx_hook(data->win_ptr, 02, 0, press_key, &data);
	// mlx_loop_hook(data->mlx_ptr, ft_frame, &data);
	// mlx_loop(data->mlx_ptr);

	// // mlx_loop_hook(grid->mlx_ptr, &no_event, &grid);
	// // mlx_key_hook(grid->win_ptr, key_press, &grid);
	// // mlx_hook(grid->win_ptr, KeyRelease, KeyReleaseMask, &handle_keyrelease, &grid);

	// mlx_destroy_display(grid->mlx_ptr);
	// free(grid->mlx_ptr);
	// free_map(grid, 0);
	return (0);
}












	// Display *display;
	// Window window;
	// XEvent event;
	// char *msg = "Hello, Worlds!!!";
	// int screen;

	// // open connection to the server
	// display = XOpenDisplay(NULL);
	// if (display == NULL)
	// {
	// 		ft_printf("Cannot open display\n %s\n", stderr);
	// 		exit(1);
	// }

	// screen = DefaultScreen(display);

	// // create window
	// window = XCreateSimpleWindow(display, RootWindow(display, screen), 100, 100, 500, 300, 1,
	// 															WhitePixel(display, screen), WhitePixel(display, screen));

	// // select kind of events we are interested in
	// XSelectInput(display, window, ExposureMask | KeyPressMask);

	// // map (show) the window
	// XMapWindow(display, window);

	// // event loop
	// while (1)
	// {
	// 		XNextEvent(display, &event);

	// 		// // draw or redraw the window
	// 		if (event.type == Expose)
	// 		{
	// 				XFillRectangle(display, window, DefaultGC(display, screen), 40, 	40, 110, 110);
	// 				XDrawString(display, window, DefaultGC(display, screen), 50, 50, msg, strlen(msg));
	// 		}
	// 		// // exit on key press
	// 		if (event.type == KeyPress)
	// 				break;
	// }

	// // close connection to the server
	// XCloseDisplay(display);