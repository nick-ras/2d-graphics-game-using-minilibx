/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_free_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nick <nick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 23:19:38 by lshonta           #+#    #+#             */
/*   Updated: 2022/11/29 11:45:15 by nick             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	fill_map2(t_map *map, char *argv)
{
	int	row_count;
	int	fd2;

	fd2 = open(argv, O_RDONLY);
	if (fd2 < 0)
	{
		ft_printf("Error\n");
		ft_printf("fd didnt work\n");
		free_map(map, 0);
	}
	map->map2 = ft_calloc(map->rows + 1, sizeof(char *));
	row_count = 0;
	while (row_count < map->rows)
	{
		map->map2[row_count] = get_next_line(fd2);
		if (map->map2[row_count] == NULL)
		{
			ft_printf("Error\n");
			ft_printf("rows is NULL\n");
			free_map(map, 0);
		}	
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
		ft_printf("Error\n");
		ft_printf("fd not working\n");
		free_map(map, 0);
	}
	map->map = ft_calloc(map->rows + 1, sizeof(char *));
	row_count = 0;
	while (row_count < map->rows)
	{
		map->map[row_count] = get_next_line(fd);
		row_count++;
	}
	close(fd);
	fill_map2(map, argv);
	check_squares(map);
	wall_check(map);
}

int	free_map2(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->rows + 1)
	{
		free(map->map2[i]);
		i++;
	}
	free(map->map2);
}

int	free_map(t_map *map, int after_window)
{
	int	i;

	i = 0;
	while (i < map->rows + 1)
	{
		if (map->map[i])
			free(map->map[i]);
		i++;
	}
	if (map->map)
		free(map->map);
	if (map->wall_pic)
	{
		ft_printf("PICTURE EXISTS\n");
		mlx_destroy_image(map->mlx_ptr, map->finish_pic);
		mlx_destroy_image(map->mlx_ptr, map->collectible_pic);
		mlx_destroy_image(map->mlx_ptr, map->door_pic);
		mlx_destroy_image(map->mlx_ptr, map->space_pic);
		mlx_destroy_image(map->mlx_ptr, map->player_pic);
		mlx_destroy_image(map->mlx_ptr, map->wall_pic);
	}
	if (after_window)
	{
		mlx_destroy_window(map->mlx_ptr, map->win_ptr);
		mlx_destroy_display(map->mlx_ptr);
		free(map->mlx_ptr);
	}
	if (map)
		free(map);
	if (after_window)
		exit (EXIT_SUCCESS);
	exit(EXIT_FAILURE);
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
		if ((int)ft_strlen(line_as_str) != map->columns && \
		((int)ft_strlen(line_as_str) - 1) != map->columns)
		{
			ft_printf("Error\n");
			ft_printf("line not same length as start line\n");
			free_map(map, 0);
		}
		free(line_as_str);
		line_as_str = get_next_line(fd);
		map->rows++;
	}
	ft_printf("map->rows = %d\n", map->rows);
	close(fd);
	check_rows(map);
}
