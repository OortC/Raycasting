/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeblee <jaeblee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 15:29:49 by jaeblee           #+#    #+#             */
/*   Updated: 2024/09/24 14:00:32 by jaeblee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	check_wall(t_mlx *var, double dx, double dy)
{
	char	c;

	c = var->map.map[(int)dy][(int)dx];
	if (dx < 0 || dx >= WIDTH)
		return ;
	if (dy < 0 || dy >= HEIGHT)
		return ;
	if (c != '1' && c != ' ')
	{
		var->cmr.pos_x = dx;
		var->cmr.pos_y = dy;
	}
}

void	move_x(int key, t_mlx *var)
{
	double	dx;
	double	dy;
	double	dir[2];

	dx = var->cmr.pos_x;
	dy = var->cmr.pos_y;
	dir[0] = cos(M_PI / 2) * var->cmr.dir_x - sin(M_PI / 2) * var->cmr.dir_y;
	dir[1] = sin(M_PI / 2) * var->cmr.dir_x + cos(M_PI / 2) * var->cmr.dir_y;
	dir[0] *= SPEED;
	dir[1] *= SPEED;
	if (key == KEY_A)
	{
		dir[0] *= -1;
		dir[1] *= -1;
	}
	dx += dir[0];
	dy += dir[1];
	check_wall(var, dx, dy);
}

void	move_y(int key, t_mlx *var)
{
	double	dx;
	double	dy;
	double	dir[2];

	dx = var->cmr.pos_x;
	dy = var->cmr.pos_y;
	dir[0] = var->cmr.dir_x * SPEED;
	dir[1] = var->cmr.dir_y * SPEED;
	if (key == KEY_S)
	{
		dir[0] *= -1;
		dir[1] *= -1;
	}
	dx += dir[0];
	dy += dir[1];
	check_wall(var, dx, dy);
}

void	rotate_dir(int key, t_mlx *var)
{
	double	temp_dir_x;
	double	temp_plane_x;
	double	angle;

	if (key == KEY_LEFT)
		angle = -M_PI / ROTATE;
	else
		angle = M_PI / ROTATE;
	temp_dir_x = var->cmr.dir_x;
	temp_plane_x = var->cmr.cmr_x;
	var->cmr.dir_x = cos(angle) * temp_dir_x - sin(angle) * var->cmr.dir_y;
	var->cmr.dir_y = sin(angle) * temp_dir_x + cos(angle) * var->cmr.dir_y;
	var->cmr.cmr_x = cos(angle) * temp_plane_x - sin(angle) * var->cmr.cmr_y;
	var->cmr.cmr_y = sin(angle) * temp_plane_x + cos(angle) * var->cmr.cmr_y;
}

void	move_loop(t_mlx *var)
{
	if (var->key.mov_x != -1)
		move_x(var->key.mov_x, var);
	if (var->key.mov_y != -1)
		move_y(var->key.mov_y, var);
	if (var->key.rotate != -1)
		rotate_dir(var->key.rotate, var);
}
