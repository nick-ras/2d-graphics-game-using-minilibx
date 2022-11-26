/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_route.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nick <nick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 13:33:43 by nick              #+#    #+#             */
/*   Updated: 2022/11/26 11:25:09 by nick             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	init_map(t_map *grid)
{
	if (!grid)
	{
		ft_printf("could not malloc\n");
		exit(EXIT_FAILURE);
	}
	grid->count_s = 0;
	grid->door_count = 0;
	grid->collectibles = 0;
	grid->door_check_recursive = 0;
	grid->start_pos[0] = 0;
	grid->start_pos[1] = 0;
	grid->exit_pos[0] = 0;
	grid->exit_pos[1] = 0;
	grid->player_on_exit = 0;
	grid->count_down_steps = 20;
	grid->lst_pos = '0';
}

int	dfs(t_map *grid, int count_row, int count_col, int door)
{
	ft_printf("row %d col %d and inside: %s\n", count_row, count_col, \
	grid->map2[count_row]);
	if (count_row < 0 || count_row >= grid->rows || count_col < 0 \
	|| count_col >= grid->columns)
	{
		ft_printf("missing barrier\n");
		free_map(grid, 1);
	}
	if (grid->map2[count_row][count_col] == '1')
		return (door);
	if (grid->map2[count_row][count_col] == 'D')
		door++;
	grid->map2[count_row][count_col] = '1';
	door = dfs(grid, count_row - 1, count_col, door);
	door = dfs(grid, count_row + 1, count_col, door);
	door = dfs(grid, count_row, count_col - 1, door);
	door = dfs(grid, count_row, count_col + 1, door);
	return (door);
}


void	check_valid_route(t_map *grid)
{
	int	door;

	door = 0;
	door = dfs(grid, grid->start_pos[0], grid->start_pos[1], door);
	ft_printf("\ndoor check after %d\n", door);
	if (door < 0)
	{
		ft_printf("missing barrier(s)%d\n", grid->door_check_recursive);
		free_map(grid, 1);
	}
	if (door < 1)
	{
		ft_printf("player cant go to exit\n");
		free_map(grid, 1);
	}
}
