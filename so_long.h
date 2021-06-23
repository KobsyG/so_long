/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbeco <gbeco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 15:21:58 by gbeco             #+#    #+#             */
/*   Updated: 2021/06/23 14:58:07 by gbeco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"
# include "mlx/mlx.h"

# define RES_X 640
# define RES_Y 480
# define PATH_GUY "textures/guy.xpm"
# define PATH_FLOOR "textures/sand.xpm"
# define PATH_WALL "textures/bush.xpm"
# define PATH_COLLECT "textures/fish.xpm"
# define PATH_EXIT "textures/campfire.xpm"
# define PATH_PATROL_HORI "textures/crab_hori.xpm"
# define PATH_PATROL_VERT "textures/crab_vert.xpm"
# define ANIMATION_SPEED 8
# define PATROL_SPEED 30
# define BONUS 1
# define CLEAN 0

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}t_img;

typedef struct s_text
{
	int		width;
	int		height;
	int		*addr;
	char	*path;
	t_img	img;
}t_text;

typedef struct s_guy
{
	int		x;
	int		y;
	t_text	text;
}t_guy;

typedef struct s_press
{
	int	up;
	int	down;
	int	left;
	int	right;
}t_press;

typedef struct s_vars
{
	char	*path_map;
	int		length_map;
	int		height_map;
	int		nbr_collect;
	char	**map;
	void	*mlx;
	void	*win;
	int		pixel_x;
	int		pixel_y;
	int		nbr_exit;
	int		nbr_start;
	int		nbr_patrol_hori;
	int		nbr_patrol_vert;
	t_img	img;
	t_guy	guy;
	t_text	floor;
	t_text	wall;
	t_text	collect;
	t_text	exit;
	t_text	text_patrol_hori;
	t_text	text_patrol_vert;
	t_press	press;
	int		time;
	int		count;
	int		nbr_step;
	char	*step;
	int		**patrol_hori;
	int		**patrol_vert;
}t_vars;

void	my_mlx_pixel_put(t_vars *vars, int x, int y, int color);

//parsing
int		size_map(int fd, t_vars *vars);
int		allowed_char(char c);
int		complete_and_check_char(char *line, t_vars *vars, int nbr_line);
int		complete_map(int fd, t_vars *vars);
int		parse_map(t_vars *vars);
void	flood_fill(t_vars *vars, char **tab, int x, int y);
char	**copy_map(t_vars *vars);
int		check_nbr_elem(t_vars *vars);
int		check_nbr_elem(t_vars *vars);
void	get_guy_pos(t_vars *vars, int x, int y);
int		set_patrol_hori(t_vars *vars, int x, int y);
int		set_patrol_vert(t_vars *vars, int x, int y);
int		check_last_line(t_vars *vars, char *line);
int		check_first_line(t_vars *vars, char *line);

//exit
void	freemap(char **tab);
int		freemap_unfinished(char **tab, int i);
int		error(t_vars *vars, char *s);
void	freetab_int(int **tab);
int		red_cross(t_vars *vars);

//img
int		frame_gen(t_vars *vars);
void	print_img(t_vars *vars);
void	print_big_pixel(t_vars *vars, int y, int x, int color);
void	print_floor(t_vars *vars, int y, int x);
void	print_wall(t_vars *vars, int y, int x);
void	print_collect(t_vars *vars, int y, int x);
void	print_exit(t_vars *vars, int y, int x);
void	print_patrol_hori(t_vars *vars, int y, int x);
void	print_patrol_vert(t_vars *vars, int y, int x);
void	check_patrol(t_vars *vars);

//text
void	print_guy(t_vars *vars);

//hook
int		key_hook(int keycode, t_vars *vars);

//movement
void	move_up(t_vars *vars);
void	move_down(t_vars *vars);
void	move_left(t_vars *vars);
void	move_right(t_vars *vars);

void	check_collect_and_exit(t_vars *vars);

//patrol
void	move_patrol(t_vars *vars);
void	move_patrol_hori(t_vars *vars, int i);
void	move_patrol_vert(t_vars *vars, int i);
int		check_change_side_hori(t_vars *vars, int i);
int		check_change_side_vert(t_vars *vars, int i);
void	check_collision_patrol_hori(t_vars *vars, int i);
void	check_collision_patrol_vert(t_vars *vars, int i);

//init
int		init_vars(t_vars *vars);
int		init_text(t_vars *vars);
int		init_guy(t_vars *vars);
int		init_floor(t_vars *vars);
int		init_wall(t_vars *vars);
int		init_collect(t_vars *vars);
int		init_exit(t_vars *vars);
int		init_patrol_hori(t_vars *vars);
int		init_patrol_vert(t_vars *vars);
int		init_win_img(t_vars *vars);
void	init_vars_map(t_vars *vars);

#endif