/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nickras <nickras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 09:49:19 by nickras           #+#    #+#             */
/*   Updated: 2022/09/12 11:56:08 by nickras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <fcntl.h>
# include "libftprintf/ft_printf.h"
# include "gnl/get_next_line.h"
# include "/usr/local/include/mlx.h"
# include <X11/Xfuncproto.h>
# include <X11/extensions/shm.h>
# include <X11/Xlib.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <string.h>

typedef struct s_map
{
	int rows;
	int columns;
	int entrance[2];
	char **map;
	char **map2;
	int collectibles;
} t_map;

void	dfs(t_map *grid, int count_row, int count_col);
void check_path_to_exit(t_map *grid);
t_map *get_map_using_gnl(int argc, char *argv);
int main(int argc, char *argv[]);

#endif