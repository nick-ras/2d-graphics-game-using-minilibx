/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nick <nick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 09:49:19 by nickras           #+#    #+#             */
/*   Updated: 2022/11/25 15:53:17 by nick             ###   ########.fr       */
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
# define ESC 65307
# define LEFT 97
# define RIGHT 100
# define UP 119
# define DOWN 115 
# define KEYPRESS_EVENT 2
# define KEYPRESS_EXIT 17

//mlx_key_hook detects key up events

typedef struct s_map
{
	int		start_pos[2];
	int		exit_pos[2];
	int		count_s;
	int		door_count;
	int		door_check_recursive;

	int		rows;
	int		columns;
	char	**map;
	char	**map2;
	char	lst_pos;
	int		hori_pos;
	int		vert_pos;
	int		collectibles;
	int		player_on_exit;
	int		count_down_steps;
	void	*mlx_ptr;
	void	*win_ptr;

	void	*wall_pic;
	void	*space_pic;
	void	*collectible_pic;
	void	*door_pic;
	void	*player_pic;
	void	*winner_pic;
}	t_map;

void	set_columns(t_map *grid, char *line_as_str);
void	start(t_map *grid, int row_count, int col_count);
void	door(t_map *grid, int row_count, int col_count);
void	collectibles(t_map *grid, int row_count, int col_count);
int		dfs(t_map *grid, int count_row, int count_col, int door);
int		free_map(t_map *map, int exit_func);
void	check_squares(t_map *grid);
int		get_fd(char *argv);
void	fill_map(t_map *grid, char *argv);
void	fill_map2(t_map *grid, char *argv);
void	filename_check(char *map);
void	before_recursion(t_map *grid);
void	put_images_on_picture_nested(t_map *data, int i, int j);
int		main(int argc, char *argv[]);
void	init_map(t_map *grid);
void	check_and_malloc(t_map *grid, char *argv);
int		no_event(void *data);
void	parse_map(t_map *render);
void	put_images_on_picture(t_map *data);
void	put_part_images_on_picture(t_map *data);
int		key_press(int keycode, t_map *data);
void	char_check(t_map *data);
void	wall_check(t_map *data);
void	result(t_map *data);
void	check_ptr(t_map *map, void *ptr);
#endif