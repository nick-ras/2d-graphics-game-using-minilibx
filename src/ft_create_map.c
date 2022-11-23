/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshonta <lshonta@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 17:59:53 by lshonta           #+#    #+#             */
/*   Updated: 2021/12/23 22:44:21 by lshonta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_exit(t_map *data)
{
	(void) *data;
	exit(EXIT_SUCCESS);
}

void	put_player_img(t_map *data, int *j, int *i)
{
	mlx_put_image_to_window(data->mlx, data->win,
		data->graph->player, (*j) * 40, (*i) * 40);
	data->y = *i;
	data->x = *j;
}

void	put_wall_img(t_map *data, int *j, int *i)
{
	mlx_put_image_to_window(data->mlx, data->win,
		data->graph->wall, (*j) * 40, (*i) * 40);
}

void	put_empty_img(t_map *data, int *j, int *i)
{
	mlx_put_image_to_window(data->mlx, data->win,
		data->graph->empty, (*j) * 40, (*i) * 40);
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
				put_wall_img(data, &j, &i);
			else if (data->map[i][j] == '0')
				put_empty_img(data, &j, &i);
			else if (data->map[i][j] == 'P')
				put_player_img(data, &j, &i);
			else if (data->map[i][j] == 'E')
				mlx_put_image_to_window(data->mlx, data->win,
					data->graph->door, j * 40, i * 40);
			else if (data->map[i][j] == 'C')
				mlx_put_image_to_window(data->mlx, data->win,
					data->graph->collectible, j * 40, i * 40);
			j++;
		}
		j = 0, i++;
	}
}
