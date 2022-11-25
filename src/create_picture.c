/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_picture.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nick <nick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 17:59:53 by lshonta           #+#    #+#             */
/*   Updated: 2022/11/25 15:55:30 by nick             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	put_player_to_picture(t_map *data, int *j, int *i)
{
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->player_pic, (*j) * 40, (*i) * 40);
	data->vert_pos = *i;
	data->hori_pos = *j;
}

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

void	put_part_images_on_picture(t_map *data)
{
 //1. set last pos = '0'
 //2. update last pos to new pos from parameter

	//Here you have to use mlx_put for the last and current (the ones )
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, \
		data->collectible_pic, data->vert_pos * 40, data->hori_pos * 40);
	
	//updates last pos
	data->lst_pos = data->map[data->vert_pos][data->hori_pos];
}
