/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_route.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nick <nick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 13:33:43 by nick              #+#    #+#             */
/*   Updated: 2022/11/26 13:23:02 by nick             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	init_map(t_map *map)
{
	if (!map)
	{
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
	map->player_on_exit = 0;
	map->count_down_steps = 20;
	map->lst_pos = '0';
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
