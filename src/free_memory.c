/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_memory.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 23:19:38 by lshonta           #+#    #+#             */
/*   Updated: 2023/03/13 14:38:17 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/* frees the map used for parsing
*/
int	free_map2(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->rows + 1)
	{
		free(map->map2[i]);
		i++;
	}
	free(map->map2);
	return (0);
}

/* frees the map and windows. Also calls free_pictures
*/
int	free_map(t_map *map, int after_window)
{
	int	i;

	i = 0;
	while (i < map->rows + 1)
	{
		if (map->map[i])
			free(map->map[i]);
		i++;
	}
	if (map->map)
		free(map->map);
	free_pictures(map);
	if (after_window)
	{
		mlx_destroy_window(map->mlx_ptr, map->win_ptr);
		mlx_destroy_display(map->mlx_ptr);
		free(map->mlx_ptr);
	}
	if (map)
		free(map);
	if (after_window)
		exit (EXIT_SUCCESS);
	exit(EXIT_FAILURE);
}

/* frees the pictures
*/
void	free_pictures(t_map *map)
{
	if (map->wall_pic)
	{
		mlx_destroy_image(map->mlx_ptr, map->finish_pic);
		mlx_destroy_image(map->mlx_ptr, map->collectible_pic);
		mlx_destroy_image(map->mlx_ptr, map->door_pic);
		mlx_destroy_image(map->mlx_ptr, map->space_pic);
		mlx_destroy_image(map->mlx_ptr, map->player_pic);
		mlx_destroy_image(map->mlx_ptr, map->wall_pic);
	}
}
