/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nickras <nickras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 23:19:38 by lshonta           #+#    #+#             */
/*   Updated: 2022/11/24 08:25:40 by nickras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	wall_check(t_map *data)
{
	int	i;

	i = 0;
	while (i < data->rows)
	{
		if (data->map[i][0] != '1' && data->map[i][data->columns - 1] != '1')
		{
			ft_printf("Error horisontal walls\n");
			free_map(data, 1);
		}
		i++;
	}
	i = 0;
	while (i < data->columns - 1)
	{
		if (data->map[0][i] != '1' || data->map[data->rows - 1][i] != '1')
		{
			ft_printf("Error vertical walls ");
			free_map(data, 1);
		}
		i++;
	}
}

void	char_check(t_map *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < data->rows)
	{
		j = 0;
		while (j < data->columns)
		{
			if (data->map[i][j] != '1' && data->map[i][j] != 'D' && \
			data->map[i][j] != 'S' && data->map[i][j] != 'C' && data->map[i][j] != '0')
			{
				ft_printf("There are invalid characters in grid\n");
				free_map(data, 1);
			}
			j++;
		}
		i++;
	}
}
