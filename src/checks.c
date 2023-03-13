/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 13:33:43 by nick              #+#    #+#             */
/*   Updated: 2023/03/13 14:48:51 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/* checks if the map has a wall on the upper and lower sides
*/
void	wall_check(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->rows)
	{
		if (map->map[i][0] != '1' && map->map[i][map->columns - 1] != '1')
		{
			ft_printf("Error\n");
			ft_printf("Error horisontal walls\n");
			free_map2(map);
			free_map(map, 1);
		}
		i++;
	}
	wall_check2(map);
}

/* checks if the map has a valid characters
*/
void	char_check(t_map *map, int i, int j)
{
	if (map->map[i][j] != '1' && map->map[i][j] != 'E' && \
	map->map[i][j] != 'P' && map->map[i][j] != 'C' \
	&& map->map[i][j] != '0')
	{
		ft_printf("Error\n");
		ft_printf("There are invalid characters in map \
or lines not same length\n");
		free_map2(map);
		free_map(map, 0);
	}
}

/* Using recursion to check if the player can get to the exit
*/
int	dfs(t_map *map, int count_row, int count_col, int door)
{
	if (count_row < 0 || count_row >= map->rows || count_col < 0 \
	|| count_col >= map->columns)
	{
		ft_printf("Error\n");
		ft_printf("missing barrier\n");
		free_map2(map);
		free_map(map, 0);
	}
	if (map->map2[count_row][count_col] == '1')
		return (door);
	if (map->map2[count_row][count_col] == 'E')
		door++;
	map->map2[count_row][count_col] = '1';
	door = dfs(map, count_row - 1, count_col, door);
	door = dfs(map, count_row + 1, count_col, door);
	door = dfs(map, count_row, count_col - 1, door);
	door = dfs(map, count_row, count_col + 1, door);
	return (door);
}

/* calls dfs to check if the player can get to the exit. If not, then it frees memory
*/
void	check_valid_route(t_map *map)
{
	int	door;

	door = 0;
	door = dfs(map, map->start_pos[0], map->start_pos[1], door);
	if (door < 1)
	{
		ft_printf("Error\n");
		ft_printf("player cant go to exit\n");
		free_map2(map);
		free_map(map, 1);
	}
	free_map2(map);
}

/* checks if file name is correct, without opening it
*/
void	filename_check(char *map)
{
	char	*ptr;

	if (ft_strnstr(map, ".ber", ft_strlen(map)) == NULL)
	{
		ft_printf("Error\n");
		ft_printf("name not correct\n");
		exit (1);
	}
	ptr = ft_memchr(map, '.', ft_strlen(map));
	if (*(ptr + 4) != '\0')
	{
		ft_printf("Error\n");
		ft_printf("char after '.ber'\n");
		exit (1);
	}
	if (ptr == map)
	{
		ft_printf("Error\n");
		ft_printf("char(s) missing before '.ber'\n");
		exit (1);
	}
}
