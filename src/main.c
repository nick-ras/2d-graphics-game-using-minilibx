/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nick <nick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 13:20:33 by nick              #+#    #+#             */
/*   Updated: 2022/11/25 15:00:28 by nick             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
//make re  && ./a.out src/map.ber

void	fill_map2(t_map *grid, char *argv)
{
	int	row_count;
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
	close(fd2);
}

void	fill_map(t_map *grid, char *argv)
{
	int	row_count;
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
		row_count++;
	}
	close(fd);
	fill_map2(grid, argv);
	check_squares(grid);
	wall_check(grid);
	char_check(grid);
}
		// ft_printf("fill_map %d", ft_strlen(grid->map[row_count]));

void	parse_map(t_map *grid)
{
	int	img_height;
	int	img_width;

	grid->player_pic = mlx_xpm_file_to_image(grid->mlx_ptr,
			PLAYER, &img_width, &img_height);
	grid->wall_pic = mlx_xpm_file_to_image(grid->mlx_ptr,
			WALL, &img_width, &img_height);
	grid->space_pic = mlx_xpm_file_to_image(grid->mlx_ptr,
			EMPTY_SPACE, &img_width, &img_height);
	grid->door_pic = mlx_xpm_file_to_image(grid->mlx_ptr,
			EXIT, &img_width, &img_height);
	grid->collectible_pic = mlx_xpm_file_to_image(grid->mlx_ptr,
			COLLECT, &img_width, &img_height);
	grid->winner_pic = mlx_xpm_file_to_image(grid->mlx_ptr,
			WIN, &img_width, &img_height);
}

void	check_and_malloc(t_map *grid, char *argv)
{
	int		fd;
	char	*line_as_str;

	fd = get_fd(argv);
	line_as_str = get_next_line(fd);
	set_columns(grid, line_as_str);
	while (line_as_str)
	{
		line_as_str[grid->columns] = '\0';
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

int	main(int argc, char *argv[])
{
	t_map	*grid;

	if (argc != 2)
	{
		ft_printf("argc not 2\n");
		return (1);
	}
	filename_check(argv[1]);
	grid = ft_calloc(1, sizeof (t_map));
	init_map(grid);
	check_and_malloc(grid, argv[1]);
	fill_map(grid, argv[1]);
	grid->mlx_ptr = mlx_init();
	check_ptr(grid, grid->mlx_ptr);
	grid->win_ptr = mlx_new_window(grid->mlx_ptr, grid->columns * 40, \
	grid->rows * 40, "My window");
	check_ptr(grid, grid->win_ptr);
	parse_map(grid);
	put_images_on_picture(grid);
	mlx_hook(grid->win_ptr, KEYPRESS_EXIT, 2, no_event, &grid);
	mlx_hook(grid->win_ptr, KEYPRESS_EVENT, 0, key_press, &grid);
	mlx_loop(grid->mlx_ptr);
	free_map(grid, 0);
	return (0);
}


// mlx_loop -->A part of the window should be re-drawn
// (this is called an "expose" event, and it is your program's job to handle it).
// .br