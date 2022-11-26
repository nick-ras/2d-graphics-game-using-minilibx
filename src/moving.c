/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nick <nick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 21:11:02 by lshonta           #+#    #+#             */
/*   Updated: 2022/11/26 11:51:09 by nick             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	move_w(t_map *data)
{
	if (data->map[data->start_pos[0] - 1][data->start_pos[1]] != '1')
	{
		if (data->map[data->start_pos[0] - 1][data->start_pos[1]] == 'C')
		{
			data->map[data->start_pos[0]][data->start_pos[1]] = '0';
			data->map[data->start_pos[0] - 1][data->start_pos[1]] = 'P';
			data->collectibles--;
		}
		else if (data->map[data->start_pos[0] - 1][data->start_pos[1]] == '0')
		{
			data->map[data->start_pos[0]][data->start_pos[1]] = '0';
			data->map[data->start_pos[0] - 1][data->start_pos[1]] = 'P';
		}
		else if (data->map[data->start_pos[0] - 1][data->start_pos[1]] == 'E'
			&& data->count_down_steps == 0)
			data->player_on_exit = 1;
		data->start_pos[0]--;
		data->count_down_steps--;
	}
}

void	move_s(t_map *data)
{
	if (data->map[data->start_pos[0] + 1][data->start_pos[1]] != '1')
	{
		if (data->map[data->start_pos[0] + 1][data->start_pos[1]] == 'C')
		{
			data->map[data->start_pos[0]][data->start_pos[1]] = '0';
			data->map[data->start_pos[0] + 1][data->start_pos[1]] = 'P';
			data->count_down_steps--;
			data->collectibles--;
		}
		else if (data->map[data->start_pos[0] + 1][data->start_pos[1]] == '0')
		{
			data->map[data->start_pos[0]][data->start_pos[1]] = '0';
			data->map[data->start_pos[0] + 1][data->start_pos[1]] = 'P';
		}
		else if (data->map[data->start_pos[0] + 1][data->start_pos[1]] == 'E'
			&& data->count_down_steps == 0)
			data->player_on_exit = 1;
		data->start_pos[0]++;
	}
}

void	move_a(t_map *data)
{
	if (data->map[data->start_pos[0]][data->start_pos[1] - 1] != '1')
	{
		if (data->map[data->start_pos[0]][data->start_pos[1] - 1] == 'C')
		{
			data->map[data->start_pos[0]][data->start_pos[1]] = '0';
			data->map[data->start_pos[0]][data->start_pos[1] - 1] = 'P';
			data->count_down_steps--;
			data->collectibles--;
		}
		else if (data->map[data->start_pos[0]][data->start_pos[1] - 1] == '0')
		{
			data->map[data->start_pos[0]][data->start_pos[1]] = '0';
			data->map[data->start_pos[0]][data->start_pos[1] - 1] = 'P';
		}
		else if (data->map[data->start_pos[0]][data->start_pos[1] - 1] == 'E'
			&& data->count_down_steps == 0)
			data->player_on_exit = 1;
		data->start_pos[1]--;
	}
}

void	move_d(t_map *data)
{
	if (data->map[data->start_pos[0]][data->start_pos[1] + 1] != '1')
	{
		if (data->map[data->start_pos[0]][data->start_pos[1] + 1] == 'C')
		{
			data->map[data->start_pos[0]][data->start_pos[1]] = '0';
			data->map[data->start_pos[0]][data->start_pos[1] + 1] = 'P';
			data->count_down_steps--;
			data->collectibles--;
		}
		else if (data->map[data->start_pos[0]][data->start_pos[1] + 1] == '0')
		{
			data->map[data->start_pos[0]][data->start_pos[1]] = '0';
			data->map[data->start_pos[0]][data->start_pos[1] + 1] = 'P';
		}
		else if (data->map[data->start_pos[0]][data->start_pos[1] + 1] == 'E'
			&& data->count_down_steps == 0)
			data->player_on_exit = 1;
		data->start_pos[1]++;
	}
}

int	key_press(int keycode, t_map *data)
{
	if (keycode == ESC)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		free_map(data, 0);
	}
	else if (keycode == UP)
		move_w(data);
	else if (keycode == LEFT)
		move_a(data);
	else if (keycode == DOWN)
		move_s(data);
	else if (keycode == RIGHT)
		move_d(data);
	return (0);
}
