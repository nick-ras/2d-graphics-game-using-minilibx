/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nick <nick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 21:11:02 by lshonta           #+#    #+#             */
/*   Updated: 2022/11/28 10:26:12 by nick             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void put_last_pos(t_map *map)
{
	if (map->lst_pos == 'D' && map->count_down_steps > 0)
	{
		//mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, EXIT, \
		map->start_pos[0]  * 40, map->start_pos[1]  * 40);
		map->map[map->start_pos[0] - 1][map->start_pos[1]] = 'E';
	}
	else if (map->lst_pos == 'C' || map->lst_pos == '0' )
	{
		//mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, EMPTY_SPACE, \
		map->start_pos[0]  * 40, map->start_pos[1]  * 40);
		map->map[map->start_pos[0] - 1][map->start_pos[1]] = '0';
	}
}
void	move_w(t_map *map)
{
	if (map->map[map->start_pos[0] - 1][map->start_pos[1]] == '1')
		return ;
	if (map->map[map->start_pos[0] - 1][map->start_pos[1]] == 'C')
	{
		//mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, PLAYER, \
		(map->start_pos[0] - 1)  * 40, map->start_pos[1]  * 40);
		map->map[map->start_pos[0] - 1][map->start_pos[1]] = 'P';
		put_last_pos(map);
		map->collectibles--;
	}
	// else if (map->map[map->start_pos[0] - 1][map->start_pos[1]] == '0')
	// {
	// 	map->map[map->start_pos[0]][map->start_pos[1]] = '0';
	// 	map->map[map->start_pos[0] - 1][map->start_pos[1]] = 'P';
	// }
	// else if (map->map[map->start_pos[0] - 1][map->start_pos[1]] == 'E' \
	// 	&& map->step_count == 0)
	// 	map->player_on_exit = 1;
	map->start_pos[0] = map->start_pos[0] - 1;
	map->count_down_steps--;
}

int	key_press(int keycode, t_map *map)
{
	ft_printf("in key_press keycode = %d\n", keycode);
	ft_printf("x = %d y = %d\n", map->start_pos[0], map->start_pos[1]);
	// if (keycode == ESC)
	// 	free_map(map, 0);
	// if (keycode == UP)
	// 	move_w(map);
	// else if (keycode == LEFT)
	// 	move_a(map);
	// else if (keycode == DOWN)
	// 	move_s(map);
	// else if (keycode == RIGHT)
	// 	move_d(map);
	ft_printf("in key_press end keycdoe\n");
	return (0);
}

int update_window(t_map *map)
{
	//mlx_clear_window(map->mlx_ptr, map->win_ptr);
	//put_images_on_picture(map);
	
	return (0);
}
