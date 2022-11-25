/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nick <nick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 21:11:02 by lshonta           #+#    #+#             */
/*   Updated: 2022/11/25 10:37:25 by nick             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	move_w(t_map *data)
{
	if (data->map[data->vert_pos - 1][data->hori_pos] != '1')
	{
		if (data->map[data->vert_pos - 1][data->hori_pos] == 'C')
		{
			data->map[data->vert_pos][data->hori_pos] = '0';
			data->map[data->vert_pos - 1][data->hori_pos] = 'P';
			data->count_down_steps--;
		}
		else if (data->map[data->vert_pos - 1][data->hori_pos] == '0')
		{
			data->map[data->vert_pos][data->hori_pos] = '0';
			data->map[data->vert_pos - 1][data->hori_pos] = 'P';
		}
		else if (data->map[data->vert_pos - 1][data->hori_pos] == 'E'
			&& data->count_down_steps == 0)
			data->player_on_exit = 1;
		data->vert_pos--;
	}
}

void	move_s(t_map *data)
{
	if (data->map[data->vert_pos + 1][data->hori_pos] != '1')
	{
		if (data->map[data->vert_pos + 1][data->hori_pos] == 'C')
		{
			data->map[data->vert_pos][data->hori_pos] = '0';
			data->map[data->vert_pos + 1][data->hori_pos] = 'P';
			data->count_down_steps--;
		}
		else if (data->map[data->vert_pos + 1][data->hori_pos] == '0')
		{
			data->map[data->vert_pos][data->hori_pos] = '0';
			data->map[data->vert_pos + 1][data->hori_pos] = 'P';
		}
		else if (data->map[data->vert_pos + 1][data->hori_pos] == 'E'
			&& data->count_down_steps == 0)
			data->player_on_exit = 1;
		data->vert_pos++;
	}
}

void	move_a(t_map *data)
{
	if (data->map[data->vert_pos][data->hori_pos - 1] != '1')
	{
		if (data->map[data->vert_pos][data->hori_pos - 1] == 'C')
		{
			data->map[data->vert_pos][data->hori_pos] = '0';
			data->map[data->vert_pos][data->hori_pos - 1] = 'P';
			data->count_down_steps--;
		}
		else if (data->map[data->vert_pos][data->hori_pos - 1] == '0')
		{
			data->map[data->vert_pos][data->hori_pos] = '0';
			data->map[data->vert_pos][data->hori_pos - 1] = 'P';
		}
		else if (data->map[data->vert_pos][data->hori_pos - 1] == 'E'
			&& data->count_down_steps == 0)
			data->player_on_exit = 1;
		data->hori_pos--;
	}
}

void	move_d(t_map *data)
{
	if (data->map[data->vert_pos][data->hori_pos + 1] != '1')
	{
		if (data->map[data->vert_pos][data->hori_pos + 1] == 'C')
		{
			data->map[data->vert_pos][data->hori_pos] = '0';
			data->map[data->vert_pos][data->hori_pos + 1] = 'P';
			data->count_down_steps--;
		}
		else if (data->map[data->vert_pos][data->hori_pos + 1] == '0')
		{
			data->map[data->vert_pos][data->hori_pos] = '0';
			data->map[data->vert_pos][data->hori_pos + 1] = 'P';
		}
		else if (data->map[data->vert_pos][data->hori_pos + 1] == 'E'
			&& data->count_down_steps == 0)
			data->player_on_exit = 1;
		data->hori_pos++;
	}
}

int	key_press(int keycode, t_map *data)
{
	if (keycode == ESC)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		free_map(data, 0);
	}
	else if (keycode == W)
		move_w(data);
	else if (keycode == A)
		move_a(data);
	else if (keycode == S)
		move_s(data);
	else if (keycode == D)
		move_d(data);
	return (0);
}