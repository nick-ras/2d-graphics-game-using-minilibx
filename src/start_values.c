/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_values.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nick <nick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 13:33:04 by nick              #+#    #+#             */
/*   Updated: 2022/11/25 15:54:35 by nick             ###   ########.fr       */
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

void	start(t_map *grid, int row_count, int col_count)
{
	if (grid->map[row_count][col_count] == 'S')
	{
		if (grid->count_s != 0)
		{
			ft_printf("too many entrances\n");
			free_map(grid, 1);
		}
		grid->start_pos[0] = row_count;
		grid->start_pos[1] = col_count;
		grid->count_s++;
	}
}

void	door(t_map *grid, int row_count, int col_count)
{
	if (grid->map[row_count][col_count] == 'D')
	{
		if (grid->door_count != 0)
		{
			ft_printf("too many doors\n");
			free_map(grid, 1);
		}
		grid->exit_pos[0] = row_count;
		grid->exit_pos[1] = col_count;
		grid->door_count++;
	}
}
// ft_printf("door %d and %d \n", grid->D[0], grid->D[1]);

void	collectibles(t_map *grid, int row_count, int col_count)
{
	if (grid->map[row_count][col_count] == 'C')
		grid->collectibles++;
}
