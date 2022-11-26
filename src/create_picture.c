/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_picture.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nick <nick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 17:59:53 by lshonta           #+#    #+#             */
/*   Updated: 2022/11/26 11:51:14 by nick             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	put_images_on_picture_nested(t_map *data, int i, int j)
{
	if (data->map[i][j] == '1')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, \
		data->wall_pic, j * 40, i * 40);
	else if (data->map[i][j] == '0')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, \
		data->space_pic, j * 40, i * 40);
	else if (data->map[i][j] == 'S')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, \
		data->player_pic, j * 40, i * 40);
	else if (data->map[i][j] == 'D')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, \
		data->door_pic, j * 40, i * 40);
	else if (data->map[i][j] == 'C')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, \
		data->collectible_pic, j * 40, i * 40);
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
			put_images_on_picture_nested(data, i, j);
			j++;
		}
		i++;
	}
}
