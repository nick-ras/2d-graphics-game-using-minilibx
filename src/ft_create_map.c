/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nickras <nickras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 17:59:53 by lshonta           #+#    #+#             */
/*   Updated: 2022/11/23 10:04:35 by nickras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"



void	put_player_tp_picture(t_map *data, int *j, int *i)
{
	mlx_put_image_to_window(data->mlx, data->win_ptr,
		data->graph->player, (*j) * 60, (*i) * 60);
	data->y = *i;
	data->x = *j;
}

void	put_wall_to_picture(t_map *data, int *j, int *i)
{
	mlx_put_image_to_window(data->mlx, data->win_ptr,
		data->graph->wall, (*j) * 60, (*i) * 60);
}

void	put_space_to_picture(t_map *data, int *j, int *i)
{
	mlx_put_image_to_window(data->mlx, data->win_ptr,
		data->graph->empty, (*j) * 60, (*i) * 60);
}

void	ft_create_map(t_map *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (data->map[i])
	{
		while (data->map[i][j])
		{
			if (data->map[i][j] == '1')
				put_wall_to_picture(data, &j, &i);
			else if (data->map[i][j] == '0')
				put_space_to_picture(data, &j, &i);
			else if (data->map[i][j] == 'P')
				put_player_tp_picture(data, &j, &i);
			else if (data->map[i][j] == 'E')
				mlx_put_image_to_window(data->mlx, data->win_ptr,
					data->graph->door, j * 60, i * 60);
			else if (data->map[i][j] == 'C')
				mlx_put_image_to_window(data->mlx, data->win_ptr,
					data->graph->collectible, j * 60, i * 60);
			j++;
		}
		j = 0, i++;
	}
}
