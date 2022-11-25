/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_picture.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nick <nick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 17:59:53 by lshonta           #+#    #+#             */
/*   Updated: 2022/11/25 12:31:29 by nick             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	put_player_to_picture(t_map *data, int *j, int *i)
{
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->player, (*j) * 40, (*i) * 40);
	data->vert_pos = *i;
	data->hori_pos = *j;
}

void	put_images_on_picture(t_map *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < data->rows)
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == '1')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,	data->wall, j * 40, i * 40);
			else if (data->map[i][j] == '0')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,	data->space, j * 40, i * 40);
			else if (data->map[i][j] == 'S')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,	data->player, j * 40, i * 40);
			else if (data->map[i][j] == 'D')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,	data->door, j * 40, i * 40);
			else if (data->map[i][j] == 'C')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->collectible, j * 40, i * 40);
			j++;
		}
		i++;
	}
}
