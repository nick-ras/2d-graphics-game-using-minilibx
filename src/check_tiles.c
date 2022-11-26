/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_tiles.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nick <nick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 23:19:38 by lshonta           #+#    #+#             */
/*   Updated: 2022/11/26 12:09:14 by nick             ###   ########.fr       */
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
	map->map[i][j] != 'S' && map->map[i][j] != 'C' \
	&& map->map[i][j] != '0')
	{
		ft_printf("There are invalid characters in map\n");
		free_map(map, 1);
	}
}
