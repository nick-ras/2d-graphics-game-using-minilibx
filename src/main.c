/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nick <nick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 13:20:33 by nick              #+#    #+#             */
/*   Updated: 2022/11/29 20:38:45 by nick             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
//make re  && ./a.out src/map.ber

int	get_fd(char *argv)
{
	int	fd;

	fd = open(argv, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Error\n");
		ft_printf("fd error from first open\n");
		exit (0);
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
}
//ft_printf("map->columns %d\n", map->columns);

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
	map->rows * 40, "My window"); //suppose to set 40 to the feedback but putwin
	check_ptr(map, map->win_ptr);
	set_picture_pointers(map);
	mlx_hook(map->win_ptr, KEYPRESS_EXIT, (1L << 2), no_event, map);
	mlx_hook(map->win_ptr, KEYPRESS_EVENT, (1L << 0), key_press, map);
	mlx_loop_hook(map->mlx_ptr, update_window, map);
	mlx_loop(map->mlx_ptr);
	return (0);
}
