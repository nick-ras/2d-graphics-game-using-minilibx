/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 21:11:02 by lshonta           #+#    #+#             */
/*   Updated: 2023/03/13 14:37:28 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/* moves the player up if possible and updates position and collectibles found
*/
void	move_w(t_map *map)
{
	if (map->map[map->start_pos[0] - 1][map->start_pos[1]] == '1')
		return ;
	put_last_pos(map);
	if (map->map[map->start_pos[0] - 1][map->start_pos[1]] == 'E')
	{
		map->lst_pos = 'E';
		if (map->collectibles < 1)
			map->won_game = 1;
	}
	else if (map->map[map->start_pos[0] - 1][map->start_pos[1]] == 'C')
		map->collectibles--;
	map->start_pos[0]--;
	map->map[map->start_pos[0]][map->start_pos[1]] = 'P';
	map->moves--;
}

/* moves the player down if possible and updates position and collectibles found
*/
void	move_s(t_map *map)
{
	if (map->map[map->start_pos[0] + 1][map->start_pos[1]] == '1')
		return ;
	put_last_pos(map);
	if (map->map[map->start_pos[0] + 1][map->start_pos[1]] == 'E')
	{
		map->lst_pos = 'E';
		if (map->collectibles < 1)
			map->won_game = 1;
	}
	else if (map->map[map->start_pos[0] + 1][map->start_pos[1]] == 'C')
		map->collectibles--;
	map->start_pos[0]++;
	map->map[map->start_pos[0]][map->start_pos[1]] = 'P';
	map->moves--;
}

/* moves the player right if possible and updates position and collectibles found
*/
void	move_d(t_map *map)
{
	if (map->map[map->start_pos[0]][map->start_pos[1] + 1] == '1')
		return ;
	put_last_pos(map);
	if (map->map[map->start_pos[0]][map->start_pos[1] + 1] == 'E')
	{
		map->lst_pos = 'E';
		if (map->collectibles < 1)
			map->won_game = 1;
	}
	else if (map->map[map->start_pos[0]][map->start_pos[1] + 1] == 'C')
		map->collectibles--;
	map->start_pos[1]++;
	map->map[map->start_pos[0]][map->start_pos[1]] = 'P';
	map->moves--;
}

/* moves the player left if possible and updates position and collectibles found
*/
void	move_a(t_map *map)
{
	if (map->map[map->start_pos[0]][map->start_pos[1] - 1] == '1')
		return ;
	put_last_pos(map);
	if (map->map[map->start_pos[0]][map->start_pos[1] - 1] == 'E')
	{
		map->lst_pos = 'E';
		if (map->collectibles < 1)
			map->won_game = 1;
	}
	else if (map->map[map->start_pos[0]][map->start_pos[1] - 1] == 'C')
		map->collectibles--;
	map->start_pos[1]--;
	map->map[map->start_pos[0]][map->start_pos[1]] = 'P';
	map->moves--;
}

/* updates the last position of the player. Used to pass through exit without exiting if all collectibles are not found
*/
void	put_last_pos(t_map *map)
{
	if (map->lst_pos == 'E')
	{
		map->map[map->start_pos[0]][map->start_pos[1]] = 'E';
		map->lst_pos = '0';
	}
	else
		map->map[map->start_pos[0]][map->start_pos[1]] = '0';
}
