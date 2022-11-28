/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_free_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nick <nick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 23:19:38 by lshonta           #+#    #+#             */
/*   Updated: 2022/11/28 21:57:00 by nick             ###   ########.fr       */
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
			ft_printf("Error\n");
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
		ft_printf("Error\n");
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

int	free_map2(t_map *map)
{
	int	i;

	i = -1;
	while (++i < map->rows)
		free(map->map[i]);
	free(map->map);
}

int	free_map(t_map *map, int exit_func)
{
	int	i;

	i = -1;
	while (++i < map->rows)
		free(map->map[i]);
	free(map->map);
	if (map->wall_pic)
	{
		free(map->collectible_pic);
		free(map->door_pic);
		free(map->space_pic);
		free(map->player_pic);
		free(map->wall_pic);
	}
	if (map->finish_pic)
		free(map->finish_pic);
	if (map->mlx_ptr || map->win_ptr)
		mlx_destroy_window(map->mlx_ptr, map->win_ptr);
	if (exit_func)
		exit(EXIT_FAILURE);
	exit(EXIT_SUCCESS);
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
			ft_printf("Error\n");
			ft_printf("line not same length as start line\n");
			free_map(map, 1);
		}
		free(line_as_str);
		line_as_str = get_next_line(fd);
		map->rows++;
	}
	ft_printf("map->rows = %d\n", map->rows);
	close(fd);
	check_rows(map);
}
