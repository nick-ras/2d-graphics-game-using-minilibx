/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nick <nick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 23:19:38 by lshonta           #+#    #+#             */
/*   Updated: 2022/12/05 12:40:09 by nick             ###   ########.fr       */
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

void	check_and_malloc(t_map *map, char *argv)
{
	int		fd;
	char	*line_as_str;

	fd = get_fd(argv, map);
	line_as_str = get_next_line(fd);
	set_columns(map, line_as_str);
	while (line_as_str)
	{
		if ((int)ft_strlen(line_as_str) != map->columns && \
		((int)ft_strlen(line_as_str) - 1) != map->columns)
		{
			ft_printf("Error\n");
			ft_printf("line not same length as start line\n");
			free(line_as_str);
			free(map);
			exit (1);
		}
		free(line_as_str);
		line_as_str = get_next_line(fd);
		map->rows++;
	}
	close(fd);
	check_rows(map);
}
//ft_printf("map->rows = %d\n", map->rows);
