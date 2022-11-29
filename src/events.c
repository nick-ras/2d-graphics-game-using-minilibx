/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nick <nick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 13:20:11 by nick              #+#    #+#             */
/*   Updated: 2022/11/29 11:43:58 by nick             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	no_event(t_map *map)
{
	(void) map;

	return (free_map(map, 1));
}

int	update_window(t_map *map)
{
	mlx_clear_window(map->mlx_ptr, map->win_ptr);
	//mlx_destroy_window(map->mlx_ptr, map->win_ptr);
	if (map->esc)
	{
		free_map(map, 1);
		mlx_destroy_window(map->mlx_ptr, map->win_ptr);
		mlx_destroy_display(map->mlx_ptr);
		exit(EXIT_SUCCESS);
	}
	else if (map->won_game == 1 || map->moves < 1)
		mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, \
		map->finish_pic, map->columns, map->rows);
	else
		put_images_on_picture(map);
	return (0);
}
