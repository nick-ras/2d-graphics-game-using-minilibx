/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nick <nick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 13:20:33 by nick              #+#    #+#             */
/*   Updated: 2022/11/28 15:02:26 by nick             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
//make re  && ./a.out src/map.ber

void	fill_map2(t_map *map, char *argv)
{
	int	row_count;
	int	fd2;

	fd2 = open(argv, O_RDONLY);
	if (fd2 < 0)
	{
		ft_printf("fd error\n");
		free_map(map, 1);
	}
	map->map2 = ft_calloc(map->rows + 1, sizeof(char *));
	map->map2[map->rows] = NULL;
	row_count = 0;
	while (row_count < map->rows)
	{
		map->map2[row_count] = get_next_line(fd2);
		if (map->map2[row_count] == NULL)
		{
			ft_printf("rows is NULL\n");
			free_map(map, 1);
		}	
		map->map[row_count][map->columns] = '\0';
		row_count++;
	}
	close(fd2);
}

void	fill_map(t_map *map, char *argv)
{
	int	row_count;
	int	fd;

	fd = open(argv, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("fd error\n");
		free_map(map, 1);
	}
	map->map = ft_calloc(map->rows + 1, sizeof(char *));
	row_count = 0;
	while (row_count < map->rows)
	{
		map->map[row_count] = get_next_line(fd);
		map->map[row_count][map->columns] = '\0';
		row_count++;
	}
	close(fd);
	fill_map2(map, argv);
	check_squares(map);
	wall_check(map);
}
		// ft_printf("fill_map %d", ft_strlen(map->map[row_count]));

void	set_picture_pointers(t_map *map)
{
	int	img_height;
	int	img_width;

	map->player_pic = mlx_xpm_file_to_image(map->mlx_ptr,
			PLAYER, &img_width, &img_height);
	map->wall_pic = mlx_xpm_file_to_image(map->mlx_ptr,
			WALL, &img_width, &img_height);
	map->space_pic = mlx_xpm_file_to_image(map->mlx_ptr,
			EMPTY_SPACE, &img_width, &img_height);
	map->door_pic = mlx_xpm_file_to_image(map->mlx_ptr,
			EXIT, &img_width, &img_height);
	map->collectible_pic = mlx_xpm_file_to_image(map->mlx_ptr,
			COLLECT, &img_width, &img_height);
	map->winner_pic = mlx_xpm_file_to_image(map->mlx_ptr,
			WIN, &img_width, &img_height);
	map->img_vert = img_height;
	map->img_hori = img_width;
	ft_printf("vert %d hori %d\n", map->img_vert, map->img_hori);
}

void	check_and_malloc(t_map *map, char *argv)
{
	int		fd;
	char	*line_as_str;

	fd = get_fd(argv);
	line_as_str = get_next_line(fd);
	set_columns(map, line_as_str);
	while (line_as_str)
	{
		line_as_str[map->columns] = '\0';
		if ((int)ft_strlen(line_as_str) != map->columns)
		{
			ft_printf("line not same length as start line\n");
			free_map(map, 1);
		}
		free(line_as_str);
		line_as_str = get_next_line(fd);
		map->rows++;
	}
	ft_printf("map->rows = %d\n", map->rows);
	close(fd);
	if (map->rows < 4 || map->columns < 4 || map->rows == map->columns)
	{
		ft_printf("not enough rows or columns or map is not a rectangle");
		exit (1);
	}
}

int	main(int argc, char *argv[])
{
	t_map	*map;

	if (argc != 2)
	{
		ft_printf("argc not 2\n");
		return (1);
	}
	filename_check(argv[1]);
	map = ft_calloc(1, sizeof (t_map));
	init_map(map);
	check_and_malloc(map, argv[1]);
	fill_map(map, argv[1]);
	check_valid_route(map);
	map->mlx_ptr = mlx_init();
	check_ptr(map, map->mlx_ptr);
	map->win_ptr = mlx_new_window(map->mlx_ptr, map->columns * 40, \
	map->rows * 40, "My window");
	check_ptr(map, map->win_ptr);
	set_picture_pointers(map);
	put_images_on_picture(map);
	mlx_hook(map->win_ptr, KEYPRESS_EXIT, (1L << 2), no_event, map);
	mlx_hook(map->win_ptr, KEYPRESS_EVENT, (1L << 0), key_press, map);
	mlx_loop_hook(map->mlx_ptr, update_window, map);
	mlx_loop(map->mlx_ptr);
	// free_map(map, 0);
	return (0);
}


// mlx_loop -->A part of the window should be re-drawn
// (this is called an "expose" event, and it is your program's job to handle it).
// .br