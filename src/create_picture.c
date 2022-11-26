/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_picture.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nick <nick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 17:59:53 by lshonta           #+#    #+#             */
/*   Updated: 2022/11/26 13:48:47 by nick             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	put_images_on_picture_nested(t_map *map, int i, int j)
{
	if (map->map[i][j] == '1')
		mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, \
		map->wall_pic, j * 40, i * 40);
	else if (map->map[i][j] == '0')
		mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, \
		map->space_pic, j * 40, i * 40);
	else if (map->map[i][j] == 'S')
		mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, \
		map->player_pic, j * 40, i * 40);
	else if (map->map[i][j] == 'D')
		mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, \
		map->door_pic, j * 40, i * 40);
	else if (map->map[i][j] == 'C')
		mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, \
		map->collectible_pic, j * 40, i * 40);
}

void	put_images_on_picture(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < map->rows)
	{
		j = 0;
		while (map->map[i][j])
		{
			put_images_on_picture_nested(map, i, j);
			j++;
		}
		i++;
	}
}
