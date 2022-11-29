/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nick <nick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 09:49:19 by nickras           #+#    #+#             */
/*   Updated: 2022/11/28 23:33:15 by nick             ###   ########.fr       */
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
# include <X11/X.h>
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
# define ESC XK_Escape //65307
# define LEFT XK_a //0x0061 //97
# define RIGHT XK_d  //0xff53  // 0x0064 //100
# define UP XK_w //0xff52 //0x0077 //119
# define DOWN XK_s //0x0073 //115 
# define KEYPRESS_EVENT 2
# define KEYPRESS_EXIT 17

//mlx_key_hook detects key up events

typedef struct s_map
{
	int		start_pos[2];
	int		exit_pos[2];
	int		count_start;
	int		door_count;

	int		rows;
	int		columns;
	char	**map;
	char	**map2;
	char	lst_pos;
	int		collectibles;
	int		won_game;
	int		moves;
	void	*mlx_ptr;
	void	*win_ptr;

	int		img_hori;
	int		img_vert;
	void	*wall_pic;
	void	*space_pic;
	void	*collectible_pic;
	void	*door_pic;
	void	*player_pic;
	void	*finish_pic;
	int		esc;
}	t_map;

void	check_squares(t_map *grid);
void	start(t_map *grid, int row_count, int col_count);
void	door(t_map *grid, int row_count, int col_count);
void	collectibles(t_map *grid, int row_count, int col_count);
void	init_map(t_map *grid);

void	filename_check(char *map);
void	check_valid_route(t_map *grid);
void	char_check(t_map *data, int i, int j);
void	wall_check(t_map *data);
int		dfs(t_map *grid, int count_row, int count_col, int door);

int		get_fd(char *argv);
void	check_and_malloc(t_map *grid, char *argv);
void	fill_map(t_map *grid, char *argv);
void	fill_map2(t_map *grid, char *argv);
int		free_map(t_map *map, int exit_func);
int		free_map2(t_map *map);

void	check_rows(t_map *map);
void	check_ptr(t_map *map, void *ptr);
void	set_columns(t_map *grid, char *line_as_str);
int		main(int argc, char *argv[]);

int		no_event(t_map *data);
int		update_window(t_map *map);

void	set_picture_pointers(t_map *render);
void	put_images_on_picture_nested(t_map *data, int i, int j);
void	put_images_on_picture(t_map *data);

int		key_press(int keycode, t_map *data);
void	move_w(t_map *data);
void	move_d(t_map *data);
void	move_a(t_map *data);
void	move_s(t_map *data);
#endif