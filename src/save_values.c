/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_values.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nick <nick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 13:33:04 by nick              #+#    #+#             */
/*   Updated: 2022/11/26 11:38:03 by nick             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	start(t_map *grid, int i, int j)
{
	if (grid->map[i][j] == 'S')
	{
		if (grid->count_s != 0)
		{
			ft_printf("too many entrances\n");
			free_map(grid, 1);
		}
		grid->start_pos[0] = i;
		grid->start_pos[1] = j;
		grid->count_s++;
	}
}

void	door(t_map *grid, int i, int j)
{
	if (grid->map[i][j] == 'D')
	{
		if (grid->door_count != 0)
		{
			ft_printf("too many doors\n");
			free_map(grid, 1);
		}
		grid->exit_pos[0] = i;
		grid->exit_pos[1] = j;
		grid->door_count++;
	}
}
// ft_printf("door %d and %d \n", grid->D[0], grid->D[1]);

void	collectibles(t_map *grid, int i, int j)
{
	if (grid->map[i][j] == 'C')
		grid->collectibles++;
}


void	check_squares(t_map *grid)
{
	int	i;
	int	j;

	i = 0;
	while (i < grid->rows)
	{
		j = 0;
		while (j < grid->columns)
		{
			start(grid, i, j);
			door(grid, i, j);
			collectibles(grid, i, j);
			char_check(grid, i, j);
			j++;
		}
		i++;
	}
	if (grid->door_count < 1 || grid->count_s < 1 || grid->collectibles < 1)
	{
		ft_printf("missing values, could ne start, door or collectible.");
		free_map(grid, 1);
	}
}
