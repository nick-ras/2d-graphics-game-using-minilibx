/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 13:20:11 by nick              #+#    #+#             */
/*   Updated: 2023/03/13 14:42:34 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/* key event handler, that calls the appropriate function
*/
int	key_press(int keycode, t_map *map)
{
	if (keycode == ESC)
		map->esc = 1;
	if (keycode == UP)
		move_w(map);
	else if (keycode == LEFT)
		move_a(map);
	else if (keycode == DOWN)
		move_s(map);
	else if (keycode == RIGHT)
		move_d(map);
	if (map->moves > -1)
		ft_printf("moves %d\n", map->moves);
	return (0);
}

/* used for the exit button, to close the window and free the map
*/
int	no_event(t_map *map)
{
	(void) map;
	return (free_map(map, 1));
}

/* updates the window after a key press. If esc pressed it frees map and window. Else puts the picture on the window
*/
int	update_window(t_map *map)
{
	mlx_clear_window(map->mlx_ptr, map->win_ptr);
	if (map->esc)
	{
		free_map(map, 1);
		mlx_destroy_window(map->mlx_ptr, map->win_ptr);
		mlx_destroy_display(map->mlx_ptr);
		exit(EXIT_SUCCESS);
	}
	else if (map->won_game == 1 || map->moves < 1)
		mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, \
		map->finish_pic, map->columns, map->rows * 4);
	else
		put_images_on_picture(map);
	return (0);
}
