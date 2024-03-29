/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_picture.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 17:59:53 by lshonta           #+#    #+#             */
/*   Updated: 2023/03/13 14:44:49 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/* puts the image correcsponring to the map element on the window
*/
void	put_images_on_picture_nested(t_map *map, int i, int j)
{
	if (map->map[i][j] == '1')
		mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, \
		map->wall_pic, j * map->img_vert, i * map->img_hori);
	else if (map->map[i][j] == '0')
		mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, \
		map->space_pic, j * map->img_vert, i * map->img_hori);
	else if (map->map[i][j] == 'P')
		mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, \
		map->player_pic, j * map->img_vert, i * map->img_hori);
	else if (map->map[i][j] == 'E')
		mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, \
		map->door_pic, j * map->img_vert, i * map->img_hori);
	else if (map->map[i][j] == 'C')
		mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, \
		map->collectible_pic, j * map->img_vert, i * map->img_hori);
}

/* function the iterates through the whole map (2D array) and calls function the puts pixel on window*/
void	put_images_on_picture(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < map->rows)
	{
		j = 0;
		while (map->map[i][j] != '\n' && map->map[i][j] != '\0')
		{
			put_images_on_picture_nested(map, i, j);
			j++;
		}
		i++;
	}
}

/* sets the pointers to the images
*/
void	set_picture_pointers(t_map *map)
{
	int	img_height;
	int	img_width;

	map->player_pic = mlx_xpm_file_to_image(map->mlx_ptr,
			PLAYER, &img_width, &img_height);
	map->wall_pic = mlx_xpm_file_to_image(map->mlx_ptr,
			WALL, &img_width, &img_height);
	map->space_pic = mlx_xpm_file_to_image(map->mlx_ptr,
			EMPTY_SPACE, &img_width, &img_height);
	map->door_pic = mlx_xpm_file_to_image(map->mlx_ptr,
			EXIT, &img_width, &img_height);
	map->collectible_pic = mlx_xpm_file_to_image(map->mlx_ptr,
			COLLECT, &img_width, &img_height);
	map->finish_pic = mlx_xpm_file_to_image(map->mlx_ptr,
			WIN, &img_width, &img_height);
	map->img_vert = img_height;
	map->img_hori = img_width;
}
//ft_printf("vert %d hori %d\n", map->img_vert, map->img_hori);
