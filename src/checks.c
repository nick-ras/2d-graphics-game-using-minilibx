/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nick <nick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 13:33:43 by nick              #+#    #+#             */
/*   Updated: 2022/11/28 18:56:32 by nick             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	wall_check(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->rows)
	{
		if (map->map[i][0] != '1' && map->map[i][map->columns - 1] != '1')
		{
			ft_printf("Error horisontal walls\n");
			free_map(map, 1);
		}
		i++;
	}
	i = 0;
	while (i < map->columns - 1)
	{
		if (map->map[0][i] != '1' || map->map[map->rows - 1][i] != '1')
		{
			ft_printf("Error vertical walls ");
			free_map(map, 1);
		}
		i++;
	}
}

void	char_check(t_map *map, int i, int j)
{
	if (map->map[i][j] != '1' && map->map[i][j] != 'D' && \
	map->map[i][j] != 'P' && map->map[i][j] != 'C' \
	&& map->map[i][j] != '0')
	{
		ft_printf("There are invalid characters in map\n");
		free_map(map, 1);
	}
}

int	dfs(t_map *map, int count_row, int count_col, int door)
{
	//ft_printf("row %d col %d and inside: %s\n", count_row, count_col, \
	map->map2[count_row]);
	if (count_row < 0 || count_row >= map->rows || count_col < 0 \
	|| count_col >= map->columns)
	{
		ft_printf("missing barrier\n");
		free_map(map, 1);
	}
	if (map->map2[count_row][count_col] == '1')
		return (door);
	if (map->map2[count_row][count_col] == 'D')
		door++;
	map->map2[count_row][count_col] = '1';
	door = dfs(map, count_row - 1, count_col, door);
	door = dfs(map, count_row + 1, count_col, door);
	door = dfs(map, count_row, count_col - 1, door);
	door = dfs(map, count_row, count_col + 1, door);
	return (door);
}


void	check_valid_route(t_map *map)
{
	int	door;

	door = 0;
	door = dfs(map, map->start_pos[0], map->start_pos[1], door);
	if (door < 0)
	{
		ft_printf("missing barrier(s)\n");
		free_map(map, 1);
	}
	if (door < 1)
	{
		ft_printf("player cant go to exit\n");
		free_map(map, 1);
	}
}

void	filename_check(char *map)
{
	char	*ptr;

	if (ft_strnstr(map, ".ber", ft_strlen(map)) == NULL)
	{
		ft_printf("name not correct\n");
		exit (1);
	}
	ptr = ft_memchr(map, '.', ft_strlen(map));
	if (*(ptr + 4) != '\0')
	{
		ft_printf("char after '.ber'\n");
		exit (1);
	}
	if (ptr == map)
	{
		ft_printf("char(s) missing before '.ber'\n");
		exit (1);
	}
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
