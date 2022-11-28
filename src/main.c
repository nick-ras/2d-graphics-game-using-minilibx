/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nick <nick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 13:20:33 by nick              #+#    #+#             */
/*   Updated: 2022/11/28 20:28:38 by nick             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
//make re  && ./a.out src/map.ber

void	check_rows(t_map *map)
{
	if (map->rows < 4 || map->columns < 4 || map->rows == map->columns)
	{
		ft_printf("Error\n");
		ft_printf("not enough rows or columns or map is not a rectangle");
		free_map(map, 1);
		exit (1);
	}
}

void	check_ptr(t_map *map, void *ptr)
{
	if (ptr == NULL)
	{
		free(ptr);
		ft_printf("Error\n");
		ft_printf("map->win_ptr error\n");
		free_map(map, 1);
	}
}

int	get_fd(char *argv)
{
	int	fd;

	fd = open(argv, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Error\n");
		ft_printf("fd error from first open\n");
		exit (1);
	}
	return (fd);
}

void	set_columns(t_map *map, char *line_as_str)
{
	int	i;

	i = 0;
	while (line_as_str[i] != '\n' && line_as_str[i] != '\0')
		i++;
	map->columns = i;
	ft_printf("Error\n");
	ft_printf("map->columns %d\n", map->columns);
}

int	main(int argc, char *argv[])
{
	t_map	*map;

	if (argc != 2)
	{
		ft_printf("Error\n");
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
	mlx_hook(map->win_ptr, KEYPRESS_EXIT, (1L << 2), no_event, map);
	mlx_hook(map->win_ptr, KEYPRESS_EVENT, (1L << 0), key_press, map);
	mlx_loop_hook(map->mlx_ptr, update_window, map);
	mlx_loop(map->mlx_ptr);
	return (0);
}
