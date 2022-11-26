/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_values.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nick <nick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 13:33:04 by nick              #+#    #+#             */
/*   Updated: 2022/11/26 12:08:59 by nick             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	start(t_map *map, int i, int j)
{
	if (map->map[i][j] == 'S')
	{
		if (map->count_start != 0)
		{
			ft_printf("too many entrances\n");
			free_map(map, 1);
		}
		map->start_pos[0] = i;
		map->start_pos[1] = j;
		map->count_start++;
	}
}

void	door(t_map *map, int i, int j)
{
	if (map->map[i][j] == 'D')
	{
		if (map->door_count != 0)
		{
			ft_printf("too many doors\n");
			free_map(map, 1);
		}
		map->exit_pos[0] = i;
		map->exit_pos[1] = j;
		map->door_count++;
	}
}
// ft_printf("door %d and %d \n", map->D[0], map->D[1]);

void	collectibles(t_map *map, int i, int j)
{
	if (map->map[i][j] == 'C')
		map->collectibles++;
}


void	check_squares(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->rows)
	{
		j = 0;
		while (j < map->columns)
		{
			start(map, i, j);
			door(map, i, j);
			collectibles(map, i, j);
			char_check(map, i, j);
			j++;
		}
		i++;
	}
	if (map->door_count < 1 || map->count_start < 1 || map->collectibles < 1)
	{
		ft_printf("missing values, could ne start, door or collectible.");
		free_map(map, 1);
	}
}
