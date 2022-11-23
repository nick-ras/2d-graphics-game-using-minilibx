/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nickras <nickras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 23:19:38 by lshonta           #+#    #+#             */
/*   Updated: 2022/11/23 10:34:02 by nickras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	wall_check(t_map *data)
{
	int	i;

	i = 0;
	while (i < data->rows)
	{
		if (data->map[i][0] != '1' || data->map[i][data->columns - 1] != '1')
		{
			ft_printf("Error.\n doesnt have walls in outer blocks");
			free_map(data, 1);
		}
		i++;
	}
	i = 0;
	while (i < data->columns)
	{
		if (data->map[0][i] != '1' || data->map[data->rows - 1][i] != '1')
		{
			ft_printf("Error.\n doesnt have walls in outer blocks");
			free_map(data, 1);
		}
		i++;
	}
}

void	char_check(t_map *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (data->map[j])
	{
		i = 0;
		while (data->map[j][i])
		{
			if (data->map[j][i] != 'S' || data->map[j][i] != 'D'
				|| data->map[j][i] != '1' || data->map[j][i] != 'C'
				|| data->map[j][i] != '0')
			{
				ft_printf("Error.\n There are invalid characters in map");
				free_map(data, 1);
			}
				i++;
		}
		j++;
	}
}

void	result(t_map *data)
{
	mlx_clear_window(data->mlx, data->win_ptr); //the init and new windows create win_ptr
	mlx_put_image_to_window(data->mlx, data->win_ptr, data->graph->winner,
		data->columns * 60 / 2.4, data->rows * 60 / 4);
}
