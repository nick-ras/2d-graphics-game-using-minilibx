/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nick <nick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 09:49:19 by nickras           #+#    #+#             */
/*   Updated: 2022/11/25 12:29:30 by nick             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "libftprintf/ft_printf.h"
# include "gnl/get_next_line.h"
# include "/usr/local/include/mlx.h"
# include <mlx.h>
# include <X11/Xfuncproto.h>
# include <X11/extensions/shm.h>
# include <X11/Xlib.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <memory.h>
# define WALL "./pictures/wall.xpm"
# define EMPTY_SPACE "./pictures/space.xpm"
# define PLAYER "./pictures/player.xpm"
# define EXIT "./pictures/door.xpm"
# define COLLECT "./pictures/collectible.xpm"
# define WIN "./pictures/winner.xpm"
# define ESC 53
# define W 13
# define A 0
# define S 1
# define D 2 

//mlx_key_hook detects key up events

typedef struct s_map
{
	//count of variables, check that route is possible
	int		Start[2];
	int		Door[2];
	int		collectibles;
	int 	S_count;
	int		D_count;
	int		door_check_recursive;

	int 	rows;
	int 	columns;
	char	**map;
	char	**map2;
	int		hori_pos;
	int		vert_pos;
	int		player_on_exit;
	int		count_down_steps;
	void	*mlx_ptr;
	void	*win_ptr;

// pictures
	void	*wall;
	void	*space;
	void	*collectible;
	void	*door;
	void	*player;
	void	*winner;
} t_map;


t_map *init_map(t_map *grid);
void	check_and_malloc(t_map *grid, char *argv);
void start(t_map *grid, int row_count, int col_count);
void door(t_map *grid, int row_count, int col_count);
void collectibles(t_map *grid, int row_count, int col_count);
int	dfs(t_map *grid, int count_row, int count_col, int door);
int free_map(t_map *map, int exit_func);
void check_squares(t_map *grid);
int get_fd(char *argv);
void	fill_map(t_map *grid, char *argv);
void	fill_map2(t_map *grid, char *argv);
void filename_check(char *map);
void before_recursion(t_map *grid);
int main(int argc, char *argv[]);

int	handler_input_loop(int keysym, t_map *data);
int	no_event(void *data);
void	parse_map(t_map *render);
int		frame_program(t_map *data);
void	put_images_on_picture(t_map *data);
int		key_press(int keycode, t_map *data);
void	char_check(t_map *data);
void	wall_check(t_map *data);
void	result(t_map *data);
int	make_new_frame(t_map *data);
#endif