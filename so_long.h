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
# include "libftprintf/ft_printf.h"
# include "gnl/get_next_line.h"
# include "/usr/local/include/mlx.h"
# include <X11/Xfuncproto.h>
# include <X11/extensions/shm.h>
# include <X11/Xlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h> //del?
# include <memory.h> //del?
# define WIDTH 256
# define HEIGHT 256
# define WALL "./pictures/wall.xpm"
# define EMPTY "./pictures/empty.xpm"
# define PLAYER "./pictures/player.xpm"
# define EXIT "./pictures/exit.xpm"
# define COLLECT "./pictures/collect.xpm"
# define WIN "./pictures/winner.xpm"
# define ESC 53
# define W 13
# define A 0
# define S 1
# define D 2

typedef struct s_graph
{
	void	*wall;
	void	*empty;
	void	*collectible;
	void	*door;
	void	*player;
	void	*winner;
}	t_graph;

typedef struct s_map
{
	int rows;
	int columns;
	int Start[2];
	int Door[2];
	int collectibles;
	int S_count;
	int D_count;
	int door_check_recursive; //not used, delete
	char **map;
	char **map2;
	int		hight;
	int		lenght;
	int		x;
	int		y;
	int		player;
	int		escape;
	int		count;
	int		step;
	void	*wall;
	void	*mlx;
	void	*win;
	char	*fn;
	t_graph	*graph;
} t_map;


void	init_grid(t_map *grid);
void start(t_map *grid, int row_count, int col_count);
void door(t_map *grid, int row_count, int col_count);
void collectibles(t_map *grid, int row_count, int col_count);
int	dfs(t_map *grid, int count_row, int count_col, int door);
void free_map(t_map *map, int exit_func);
void check_map(t_map *grid);
void	make_grid(t_map *grid, char *argv);
void map_name_check(char *map);
void before_recursion(t_map *grid);
int main(int argc, char *argv[]);


void	ft_read_map(t_map *data);
void	ft_map_hight(t_map *data);
void	ft_map_data(t_map *data, char *name);
void	ft_parse_map(t_map *render);
int		ft_frame(t_map *data);
void	ft_create_map(t_map *data);
int		ft_exit(t_map *data);
int		press_key(int keycode, t_map *data);

void	ft_char_set(t_map *data);
void	ft_check_char(t_map *data);
void	ft_check_format(t_map *data);
void	ft_check_wall(t_map *data);
void	ft_game_result(t_map *data);
#endif