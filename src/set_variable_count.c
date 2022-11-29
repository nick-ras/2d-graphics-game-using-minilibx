/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_variable_count.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nick <nick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 18:50:33 by nick              #+#    #+#             */
/*   Updated: 2022/11/28 20:22:42 by nick             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	init_map(t_map *map)
{
	if (!map)
	{
		ft_printf("Error\n");
		ft_printf("could not malloc\n");
		exit(EXIT_FAILURE);
	}
	map->count_start = 0;
	map->door_count = 0;
	map->collectibles = 0;
	map->start_pos[0] = 0;
	map->start_pos[1] = 0;
	map->exit_pos[0] = 0;
	map->exit_pos[1] = 0;
	map->won_game = 0;
	map->moves = 20;
	map->lst_pos = '0';
}

void	start(t_map *map, int i, int j)
{
	if (map->map[i][j] == 'P')
	{
		if (map->count_start != 0)
		{
			ft_printf("Error\n");
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
			ft_printf("Error\n");
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
		ft_printf("Error\n");
		ft_printf("missing values, could not start, door or collectible.");
		free_map(map, 1);
	}
}
