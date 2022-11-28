/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_free_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nick <nick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 23:19:38 by lshonta           #+#    #+#             */
/*   Updated: 2022/11/28 19:01:27 by nick             ###   ########.fr       */
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

int	free_map(t_map *map, int exit_func)
{
	int	i;

	i = 0;
	while (i < map->rows)
	{
		if (map->map[i] != NULL)
			free(map->map[i]);
		if (map->map2[i] != NULL)
			free(map->map2[i]);
		i++;
	}
	free(map->map);
	free(map->map2);
	if (map->wall_pic)
	{
		free(map->collectible_pic);
		free(map->door_pic);
		free(map->space_pic);
		free(map->player_pic);
		free(map->wall_pic);
		free(map->finish_pic);
	}
	if (map->mlx_ptr || map->win_ptr)
		mlx_destroy_window(map->mlx_ptr, map->win_ptr);
	if (exit_func)
	{
		ft_printf("exits program with error\n");
		exit(EXIT_FAILURE);
	}
	exit(EXIT_SUCCESS);
}
