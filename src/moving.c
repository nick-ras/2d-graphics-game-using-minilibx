/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nick <nick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 21:11:02 by lshonta           #+#    #+#             */
/*   Updated: 2022/11/26 14:02:47 by nick             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	move_w(t_map *map)
{
	if (map->map[map->start_pos[0] - 1][map->start_pos[1]] != '1')
	{
		if (map->map[map->start_pos[0] - 1][map->start_pos[1]] == 'C')
		{
			map->map[map->start_pos[0] - 1][map->start_pos[1]] = 'P';
			map->collectibles--;
		}
		else if (map->map[map->start_pos[0] - 1][map->start_pos[1]] == '0')
		{
			map->map[map->start_pos[0]][map->start_pos[1]] = '0';
			map->map[map->start_pos[0] - 1][map->start_pos[1]] = 'P';
		}
		else if (map->map[map->start_pos[0] - 1][map->start_pos[1]] == 'E'
			&& map->count_down_steps == 0)
			map->player_on_exit = 1;
		map->start_pos[0]--;
		map->count_down_steps--;
	}
}

void	move_s(t_map *map)
{
	if (map->map[map->start_pos[0] + 1][map->start_pos[1]] != '1')
	{
		if (map->map[map->start_pos[0] + 1][map->start_pos[1]] == 'C')
		{
			map->map[map->start_pos[0]][map->start_pos[1]] = '0';
			map->map[map->start_pos[0] + 1][map->start_pos[1]] = 'P';
			map->count_down_steps--;
			map->collectibles--;
		}
		else if (map->map[map->start_pos[0] + 1][map->start_pos[1]] == '0')
		{
			map->map[map->start_pos[0]][map->start_pos[1]] = '0';
			map->map[map->start_pos[0] + 1][map->start_pos[1]] = 'P';
		}
		else if (map->map[map->start_pos[0] + 1][map->start_pos[1]] == 'E'
			&& map->count_down_steps == 0)
			map->player_on_exit = 1;
		map->start_pos[0]++;
	}
	mlx_destroy_window(map->mlx_ptr, map->win_ptr);
	put_images_on_picture(map);
}

void	move_a(t_map *map)
{
	if (map->map[map->start_pos[0]][map->start_pos[1] - 1] != '1')
	{
		if (map->map[map->start_pos[0]][map->start_pos[1] - 1] == 'C')
		{
			map->map[map->start_pos[0]][map->start_pos[1]] = '0';
			map->map[map->start_pos[0]][map->start_pos[1] - 1] = 'P';
			map->count_down_steps--;
			map->collectibles--;
		}
		else if (map->map[map->start_pos[0]][map->start_pos[1] - 1] == '0')
		{
			map->map[map->start_pos[0]][map->start_pos[1]] = '0';
			map->map[map->start_pos[0]][map->start_pos[1] - 1] = 'P';
		}
		else if (map->map[map->start_pos[0]][map->start_pos[1] - 1] == 'E'
			&& map->count_down_steps == 0)
			map->player_on_exit = 1;
		map->start_pos[1]--;
	}
}

void	move_d(t_map *map)
{
	if (map->map[map->start_pos[0]][map->start_pos[1] + 1] != '1')
	{
		if (map->map[map->start_pos[0]][map->start_pos[1] + 1] == 'C')
		{
			mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, \
		map->player_pic, map->start_pos[0] * 40, map->start_pos[1]  + 1 * 40);
		if (map->lst_pos = 'E')
			mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, \
		map->door_pic, map->start_pos[0] * 40, map->start_pos[1] * 40);
		else
			mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, \
		map->space_pic, map->start_pos[0] * 40, map->start_pos[1] * 40);
			map->count_down_steps--;
			map->collectibles--;
		}
		else if (map->map[map->start_pos[0]][map->start_pos[1] + 1] == '0')
		{
			map->map[map->start_pos[0]][map->start_pos[1]] = '0';
			map->map[map->start_pos[0]][map->start_pos[1] + 1] = 'P';
		}
		else if (map->map[map->start_pos[0]][map->start_pos[1] + 1] == 'E'
			&& map->count_down_steps == 0)
			map->player_on_exit = 1;
		map->start_pos[1]++;
	}
}

int	key_press(int keycode, t_map *map)
{
	ft_printf("in key_press\n");
	if (keycode == ESC)
	{
		mlx_destroy_window(map->mlx_ptr, map->win_ptr);
		free_map(map, 0);
	}
	map->key_pressed = keycode;
	return (0);
}

int update_window(t_map *map)
{
	if (map->key_pressed == UP)
		move_w(map);
	else if (map->key_pressed == LEFT)
		move_a(map);
	else if (map->key_pressed == DOWN)
		move_s(map);
	else if (map->key_pressed == RIGHT)
		move_d(map);
}
