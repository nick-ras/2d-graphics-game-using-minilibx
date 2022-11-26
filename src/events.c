/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nick <nick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 13:20:11 by nick              #+#    #+#             */
/*   Updated: 2022/11/26 12:09:21 by nick             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	no_event(void *map)
{
	(void) map;
	return (EXIT_SUCCESS);
}

void	result(t_map *map)
{
	mlx_clear_window(map->mlx_ptr, map->win_ptr);
	mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->winner_pic,
		map->columns * 40 / 2.4, map->rows * 40 / 4);
}

int	free_map(t_map *map, int exit_func)
{
	int	i;

	i = 0;
	while (i < map->rows)
	{
		if (map->map[i] != NULL)
			free(map->map[i]);
		if (map->map[i] != NULL)
			free(map->map2[i]);
		i++;
	}
	free(map->map);
	free(map->map2);
	if (map->mlx_ptr)
		free(map->mlx_ptr);
	if (map->win_ptr)
		free(map->win_ptr);
	free(map);
	if (exit_func)
	{
		ft_printf("exits program with error\n");
		exit(EXIT_FAILURE);
	}
	exit(EXIT_SUCCESS);
}

void	check_ptr(t_map *map, void *ptr)
{
	if (ptr == NULL)
	{
		free(ptr);
		ft_printf("map->win_ptr error\n");
		free_map(map, 1);
	}
}
