/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeblee <jaeblee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 13:38:24 by jaeblee           #+#    #+#             */
/*   Updated: 2024/09/24 13:47:08 by jaeblee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include <math.h>
# include <errno.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <sys/time.h>
# include "../mlx/mlx.h"
# include "../libft/includes/libft.h"
# include "../libft/includes/get_next_line.h"

// MAP
# define WIDTH			960
# define HEIGHT			540
# define M_WIDTH		153
# define M_HEIGHT		81
# define T_WIDTH		64
# define T_HEIGHT		64

# define SPEED			0.03
# define ROTATE			180

// KEY
# define ESC			53
# define KEY_W			13
# define KEY_A			0
# define KEY_S			1
# define KEY_D			2
# define KEY_LEFT		123
# define KEY_RIGHT		124

// COLOR
# define KEY_EXIT		17
# define KEY_PRESS		2
# define KEY_RELEASE	3

typedef struct s_game
{
	int		row;
	int		dx[4];
	int		dy[4];
	int		is_player;
	char	*north;
	char	*south;
	char	*west;
	char	*east;
	int		floor_color;
	int		ceiling_color;
}	t_game;

// [0] = x, [1] = y
typedef struct s_ray
{
	int			coord[2];
	int			step[2];
	double		dir_ray[2];
	double		delta_ray[2];
	double		dist_wall[2];
}	t_ray;

typedef struct s_draw
{
	int			tex_x;
	int			tex_y;
	double		pos_tex;
	double		delta_tex;
	double		vert_len;
}	t_draw;

typedef struct s_img
{
	int			bpp;
	int			end;
	int			len;
	int			width;
	int			height;
	char		*addr;
	void		*img;
}	t_img;

typedef struct s_cmr
{
	double		pos_x;
	double		pos_y;
	double		dir_x;
	double		dir_y;
	double		cmr_x;
	double		cmr_y;
}	t_cmr;

typedef struct s_tex
{
	int		width;
	int		height;
	int		*texture;
}	t_tex;

typedef struct s_map
{
	int		row;
	int		col;
	char	**map;
}	t_map;

typedef struct s_key
{
	int			mov_x;
	int			mov_y;
	int			rotate;
}	t_key;

typedef struct s_mlx
{
	void		*mlx;
	void		*win;
	t_img		img;
	t_map		map;
	t_cmr		cmr;
	t_game		game;
	t_tex		tex[4];
	t_key		key;
}	t_mlx;

// init.c
void	init_cmr(t_mlx *var);
void	init_key(t_mlx *var);
void	init_image(t_mlx *var);
void	init_ray(t_mlx *var, t_ray *ray, int x);

// hook.c
int		exit_hook(void);
int		key_hook(int key, t_mlx *var);
int		key_release(int key, t_mlx *var);

// event.c
void	move_loop(t_mlx *var);
void	move_x(int key, t_mlx *var);
void	move_y(int key, t_mlx *var);
void	rotate_dir(int key, t_mlx *var);

// image.c
int		loop_main(t_mlx *var);
void	reset_image(t_mlx *var);
void	print_image(t_mlx *var);
void	pixel_put(t_mlx *var, int x, int y, int color);

// mini_map.c
void	draw_player(t_mlx *var);
void	draw_mini_map(t_mlx *var);

// draw.c
void	ray_cast(t_mlx *var);

#endif