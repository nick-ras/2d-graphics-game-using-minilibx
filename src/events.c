/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nick <nick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 13:20:11 by nick              #+#    #+#             */
/*   Updated: 2022/11/29 12:48:22 by nick             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

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
	return (0);
}

//ft_printf("x = keycode %d %d y = %d lst pos %c collectibles 
//%d moves %d\n", keycode, map->start_pos[0], map->start_pos[1], 
//map->lst_pos, map->collectibles, map->moves);
// int	i;
// 	int	j;

// 	i = 0;
// 	j = 0;
// 	while (i < map->rows)
// 	{
// 		j = 0;
// 		while (map->map[i][j])
// 		{
// 			printf("%c", map->map[i][j]);
// 			j++;
// 		}
// 		printf("\n");
// 		i++;
// 	}

int	no_event(t_map *map)
{
	(void) map;
	return (free_map(map, 1));
}

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
		map->finish_pic, map->columns, map->rows);
	else
		put_images_on_picture(map);
	return (0);
}
