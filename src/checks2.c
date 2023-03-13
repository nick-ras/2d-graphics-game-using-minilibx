/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 19:19:46 by nick              #+#    #+#             */
/*   Updated: 2023/03/13 14:47:09 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/* checks if the map has a wall on the left and right sides
*/
void	wall_check2(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->columns - 1)
	{
		if (map->map[0][i] != '1' || map->map[map->rows - 1][i] != '1')
		{
			ft_printf("Error\n");
			ft_printf("Error vertical walls\n");
			free_map2(map);
			free_map(map, 0);
		}
		i++;
	}
}

/* checks if the map is big enough and is a square
*/
void	check_rows(t_map *map)
{
	if (map->rows < 4 || map->columns < 4 || map->rows == map->columns)
	{
		ft_printf("Error\n");
		ft_printf("map is not a rectangle or not enough rows or columns\n");
		free(map);
		exit (1);
	}
}

/* checks if win_ptr pointer works
*/
void	check_ptr(t_map *map, void *ptr)
{
	if (ptr == NULL)
	{
		free(ptr);
		ft_printf("Error\n");
		ft_printf("map->win_ptr doesnt work\n");
		free_map(map, 0);
	}
}
