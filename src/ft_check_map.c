/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshonta <lshonta@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 23:19:38 by lshonta           #+#    #+#             */
/*   Updated: 2021/12/27 18:57:39 by lshonta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_check_wall(t_map *data)
{
	int	i;
	int	err;

	err = 0;
	i = 0;
	while (i < data->hight)
	{
		if (data->map[i][0] != '1' || data->map[i][data->lenght - 1] != '1')
			err++;
		i++;
	}
	i = 0;
	while (i < data->lenght)
	{
		if (data->map[0][i] != '1' || data->map[data->hight - 1][i] != '1')
			err++;
		i++;
	}
	if (err > 0)
	{
		printf("Error.\nCheck walls");
		free_map(data, 1);
	}
}

void	ft_check_format(t_map *data)
{
	char	*ber;
	int		i;
	int		j;
	int		len;

	i = 0;
	j = 0;
	ber = "ber";
	len = ft_strlen(data->fn);
	if (len < 3)
	{
		printf("Error.\nCheck file extansion");
		exit(EXIT_FAILURE);
	}
	i = len - 3;
	while (data->fn[i] != '\0' && ber[j] != '\0')
	{
		if (data->fn[i] != ber[j])
		{
			printf("Error.\nCheck file extansion");
			exit(EXIT_FAILURE);
		}
		i++;
		j++;
	}
}

void	ft_check_char(t_map *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (data->map[j])
	{
		while (data->map[j][i])
		{
			if (data->map[j][i] == 'S' || data->map[j][i] == 'D'
				|| data->map[j][i] == '1' || data->map[j][i] == 'C'
				|| data->map[j][i] == '0')
				i++;
			else
			{
				printf("Error.\nInvalid char at map");
				free_map(data, 1);
			}
		}
		i = 0;
		j++;
	}
}

void	ft_char_set(t_map *data)
{
	int	i;
	int	j;
	int	ex;

	i = 0;
	j = 0;
	ex = 0;
	while (data->map[j])
	{
		i = 0;
		while (data->map[j][i])
		{
			if (data->map[j][i] == 'P')
				data->player += 1;
			else if (data->map[j][i] == 'E')
				ex++;
			else if (data->map[j][i] == 'C')
				data->count += 1;
			i++;
		}
		j++;
	}
	if (data->count == 0 || data->player == 0
		|| ex == 0 || data->player > 1)
		printf("Error.\n Map invalid"), exit(EXIT_FAILURE);
}

void	ft_game_result(t_map *data)
{
	mlx_clear_window(data->mlx, data->win_ptr);
	mlx_put_image_to_window(data->mlx, data->win_ptr, data->graph->winner,
		data->lenght * 40 / 2.4, data->hight * 40 / 4);
}
