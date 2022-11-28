/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nick <nick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 21:11:02 by lshonta           #+#    #+#             */
/*   Updated: 2022/11/28 20:47:10 by nick             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	put_last_pos(t_map *map)
{
	if (map->lst_pos == 'D')
		map->map[map->start_pos[0]][map->start_pos[1]] = 'D';
	else
		map->map[map->start_pos[0]][map->start_pos[1]] = '0';
	ft_printf("in put_last_pos\n");
}

void	move_w(t_map *map)
{
	if (map->map[map->start_pos[0] - 1][map->start_pos[1]] == '1')
		return ;
	if (map->map[map->start_pos[0] - 1][map->start_pos[1]] == 'D' \
	&& map->collectibles < 1)
		map->won_game = 1;
	if (map->map[map->start_pos[0] - 1][map->start_pos[1]] == 'C')
		map->collectibles--;
	else if (map->map[map->start_pos[0] - 1][map->start_pos[1]] == 'D' \
		&& map->collectibles > 0)
		map->lst_pos = 'D';
	ft_printf("before update\n");
	put_last_pos(map);
	map->start_pos[0]--;
	map->map[map->start_pos[0]][map->start_pos[1]] = 'P';
	map->moves--;
}

void	move_s(t_map *map)
{
	if (map->map[map->start_pos[0] + 1][map->start_pos[1]] == '1')
		return ;
	if (map->map[map->start_pos[0] + 1][map->start_pos[1]] == 'D' \
	&& map->collectibles < 1)
		map->won_game = 1;
	if (map->map[map->start_pos[0] + 1][map->start_pos[1]] == 'C')
		map->collectibles--;
	else if (map->map[map->start_pos[0] + 1][map->start_pos[1]] == 'D' \
		&& map->collectibles > 0)
		map->lst_pos = 'D';
	ft_printf("before update\n");
	put_last_pos(map);
	map->start_pos[0]++;
	map->map[map->start_pos[0]][map->start_pos[1]] = 'P';
	map->moves--;
}

void	move_d(t_map *map)
{
	if (map->map[map->start_pos[0]][map->start_pos[1] + 1] == '1')
		return ;
	if (map->map[map->start_pos[0]][map->start_pos[1] + 1] == 'D' \
	&& map->collectibles < 1)
		map->won_game = 1;
	if (map->map[map->start_pos[0]][map->start_pos[1] + 1] == 'C')
		map->collectibles--;
	else if (map->map[map->start_pos[0]][map->start_pos[1] + 1] == 'D' \
		&& map->collectibles > 0)
		map->lst_pos = 'D';
	ft_printf("before update\n");
	put_last_pos(map);
	map->start_pos[1]++;
	map->map[map->start_pos[0]][map->start_pos[1]] = 'P';
	map->moves--;
}

void	move_a(t_map *map)
{
	if (map->map[map->start_pos[0]][map->start_pos[1] - 1] == '1')
		return ;
	if (map->map[map->start_pos[0]][map->start_pos[1] - 1] == 'D' \
	&& map->collectibles < 1)
		map->won_game = 1;
	if (map->map[map->start_pos[0]][map->start_pos[1] - 1] == 'C')
		map->collectibles--;
	else if (map->map[map->start_pos[0]][map->start_pos[1] - 1] == 'D' \
		&& map->collectibles > 0)
		map->lst_pos = 'D';
	ft_printf("before update\n");
	put_last_pos(map);
	map->start_pos[1]--;
	map->map[map->start_pos[0]][map->start_pos[1]] = 'P';
	map->moves--;
}


// 	mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, PLAYER, \
// (map->start_pos[0] - 1)  * 40, map->start_pos[1]  * 40);

int	key_press(int keycode, t_map *map)
{
	if (keycode == ESC)
	{
	 	map->esc = 1;
		ft_printf("ESCAPE PRESSED\n");
	}
	if (keycode == UP)
	 	move_w(map);
	else if (keycode == LEFT)
		move_a(map);
	else if (keycode == DOWN)
		move_s(map);
	else if (keycode == RIGHT)
		move_d(map);
	ft_printf("x = keycode %d %d y = %d lst pos %c collectibles %d moves %d\n", keycode, map->start_pos[0], map->start_pos[1], map->lst_pos, map->collectibles, map->moves);
	
	return (0);
}

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
