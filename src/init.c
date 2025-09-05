/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeblee <jaeblee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 13:32:31 by jaeblee           #+#    #+#             */
/*   Updated: 2024/09/23 19:16:09 by jaeblee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	set_cmr_vec(t_mlx *var, char dir)
{
	var->cmr.dir_x = 0;
	var->cmr.dir_y = 0;
	var->cmr.cmr_x = 0;
	var->cmr.cmr_y = 0;
	if (dir == 'N')
	{
		var->cmr.dir_y = -1;
		var->cmr.cmr_x = 0.66;
	}
	else if (dir == 'S')
	{
		var->cmr.dir_y = 1;
		var->cmr.cmr_x = -0.66;
	}
	else if (dir == 'W')
	{
		var->cmr.dir_x = -1;
		var->cmr.cmr_y = -0.66;
	}
	else
	{
		var->cmr.dir_x = 1;
		var->cmr.cmr_y = 0.66;
	}
}

void	init_cmr(t_mlx *var)
{
	int	x;
	int	y;
	int	check;

	y = 0;
	check = 0;
	while (y < var->map.row && check == 0)
	{
		x = 0;
		while (x < var->map.col && check == 0)
		{
			if (var->map.map[y][x] == 'N' || var->map.map[y][x] == 'S'
				|| var->map.map[y][x] == 'E' || var->map.map[y][x] == 'W')
			{
				var->cmr.pos_x = x + 0.5;
				var->cmr.pos_y = y + 0.5;
				set_cmr_vec(var, var->map.map[y][x]);
				check = 1;
			}
			x++;
		}
		y++;
	}
}

void	init_image(t_mlx *var)
{
	int	width;
	int	height;

	width = WIDTH;
	height = HEIGHT;
	var->mlx = mlx_init();
	var->win = mlx_new_window(var->mlx, width, height, "3D");
	var->img.img = mlx_new_image(var->mlx, width, height);
	var->img.addr = mlx_get_data_addr(var->img.img, \
		&var->img.bpp, &var->img.len, &var->img.end);
}

void	init_ray(t_mlx *var, t_ray *ray, int x)
{
	double	screen_x;

	screen_x = 2 * x / (double)WIDTH - 1;
	ray->coord[0] = var->cmr.pos_x;
	ray->coord[1] = var->cmr.pos_y;
	ray->dir_ray[0] = var->cmr.dir_x + var->cmr.cmr_x * screen_x;
	ray->dir_ray[1] = var->cmr.dir_y + var->cmr.cmr_y * screen_x;
	ray->delta_ray[0] = fabs(1 / ray->dir_ray[0]);
	ray->delta_ray[1] = fabs(1 / ray->dir_ray[1]);
	ray->step[0] = 1;
	ray->step[1] = 1;
	ray->dist_wall[0] = (var->cmr.pos_x - ray->coord[0]) * ray->delta_ray[0];
	ray->dist_wall[1] = (var->cmr.pos_y - ray->coord[1]) * ray->delta_ray[1];
	if (ray->dir_ray[0] < 0)
		ray->step[0] = -1;
	else
		ray->dist_wall[0] = -ray->dist_wall[0] + ray->delta_ray[0];
	if (ray->dir_ray[1] < 0)
		ray->step[1] = -1;
	else
		ray->dist_wall[1] = -ray->dist_wall[1] + ray->delta_ray[1];
	if (isinf(ray->delta_ray[0]))
		ray->dist_wall[0] = INFINITY;
	if (isinf(ray->delta_ray[1]))
		ray->dist_wall[1] = INFINITY;
}

void	init_key(t_mlx *var)
{
	var->key.mov_x = -1;
	var->key.mov_y = -1;
	var->key.rotate = -1;
}
