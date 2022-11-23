/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moving.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nickras <nickras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 21:11:02 by lshonta           #+#    #+#             */
/*   Updated: 2022/11/23 15:08:13 by nickras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	move_w(t_map *data)
{
	if (data->map[data->y - 1][data->x] != '1')
	{
		if (data->map[data->y - 1][data->x] == 'C')
		{
			data->map[data->y][data->x] = '0';
			data->map[data->y - 1][data->x] = 'P';
			data->count--;
		}
		else if (data->map[data->y - 1][data->x] == '0')
		{
			data->map[data->y][data->x] = '0';
			data->map[data->y - 1][data->x] = 'P';
		}
		else if (data->map[data->y - 1][data->x] == 'E'
			&& data->count == 0)
			data->escape = 1;
		data->y--;
		data->step++;
		ft_printf("Steps: %d\n", data->step);
	}
}

void	move_s(t_map *data)
{
	if (data->map[data->y + 1][data->x] != '1')
	{
		if (data->map[data->y + 1][data->x] == 'C')
		{
			data->map[data->y][data->x] = '0';
			data->map[data->y + 1][data->x] = 'P';
			data->count--;
		}
		else if (data->map[data->y + 1][data->x] == '0')
		{
			data->map[data->y][data->x] = '0';
			data->map[data->y + 1][data->x] = 'P';
		}
		else if (data->map[data->y + 1][data->x] == 'E'
			&& data->count == 0)
			data->escape = 1;
		data->y++;
		data->step++;
		ft_printf("Steps: %d\n", data->step);
	}
}

void	move_a(t_map *data)
{
	if (data->map[data->y][data->x - 1] != '1')
	{
		if (data->map[data->y][data->x - 1] == 'C')
		{
			data->map[data->y][data->x] = '0';
			data->map[data->y][data->x - 1] = 'P';
			data->count--;
		}
		else if (data->map[data->y][data->x - 1] == '0')
		{
			data->map[data->y][data->x] = '0';
			data->map[data->y][data->x - 1] = 'P';
		}
		else if (data->map[data->y][data->x - 1] == 'E'
			&& data->count == 0)
			data->escape = 1;
		data->x--;
		data->step++;
		ft_printf("Steps: %d\n", data->step);
	}
}

void	move_d(t_map *data)
{
	if (data->map[data->y][data->x + 1] != '1')
	{
		if (data->map[data->y][data->x + 1] == 'C')
		{
			data->map[data->y][data->x] = '0';
			data->map[data->y][data->x + 1] = 'P';
			data->count--;
		}
		else if (data->map[data->y][data->x + 1] == '0')
		{
			data->map[data->y][data->x] = '0';
			data->map[data->y][data->x + 1] = 'P';
		}
		else if (data->map[data->y][data->x + 1] == 'E'
			&& data->count == 0)
			data->escape = 1;
		data->x++;
		data->step++;
		ft_printf("Steps: %d\n", data->step);
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
