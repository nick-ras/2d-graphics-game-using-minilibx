/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nick <nick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 13:20:11 by nick              #+#    #+#             */
/*   Updated: 2022/11/28 22:38:48 by nick             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	no_event(void *map)
{
	(void) map;
	return (EXIT_SUCCESS);
}

int	update_window(t_map *map)
{
	mlx_clear_window(map->mlx_ptr, map->win_ptr);
	//mlx_destroy_window(map->mlx_ptr, map->win_ptr);
	if (map->esc)
	{
		free_map(map, 0);
		mlx_destroy_window(map->mlx_ptr, map->win_ptr);
	}
	else if (map->won_game == 1 || map->moves < 1)
		mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, \
		map->finish_pic, map->columns, map->rows);
	else
		put_images_on_picture(map);
	return (0);
}