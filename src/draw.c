/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeblee <jaeblee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 14:10:13 by jaeblee           #+#    #+#             */
/*   Updated: 2024/09/24 13:15:12 by jaeblee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	proc_dda(t_ray *ray)
{
	if (ray->dist_wall[0] < ray->dist_wall[1])
	{
		ray->dist_wall[0] += ray->delta_ray[0];
		ray->coord[0] += ray->step[0];
		return (0);
	}
	else
	{
		ray->dist_wall[1] += ray->delta_ray[1];
		ray->coord[1] += ray->step[1];
		return (1);
	}
}

int	get_tex_num(t_ray ray, int side)
{
	if (side == 0)
	{
		if (ray.step[0] > 0)
			return (3);
		else
			return (2);
	}
	else
	{
		if (ray.step[1] > 0)
			return (1);
		else
			return (0);
	}
}

void	draw_tex_wall(t_mlx *var, t_tex tex, t_draw draw, int x)
{
	int		start;
	int		end;
	int		height;
	int		color;

	height = (int)(1.2 * HEIGHT / draw.vert_len);
	start = (HEIGHT - height) / 2;
	end = (HEIGHT + height) / 2;
	draw.pos_tex = 0;
	draw.delta_tex = (double)tex.height / height;
	if (height >= HEIGHT)
	{
		draw.pos_tex = fabs((double)start / height) * tex.height;
		start = 0;
		end = HEIGHT - 1;
	}
	while (start <= end)
	{
		draw.tex_y = (int)draw.pos_tex & (tex.width - 1);
		draw.pos_tex += draw.delta_tex;
		color = tex.texture[draw.tex_y * tex.width + draw.tex_x];
		pixel_put(var, x, start, color);
		start++;
	}
}

void	draw_wall(t_mlx *var, t_ray ray, int side, int x)
{
	t_tex	tex;
	t_draw	draw;
	double	wall_x;

	if (side == 0)
	{
		draw.vert_len = (ray.coord[0] - var->cmr.pos_x + (1 - ray.step[0]) / 2);
		draw.vert_len /= ray.dir_ray[0];
		wall_x = var->cmr.pos_y + draw.vert_len * ray.dir_ray[1];
	}
	else
	{
		draw.vert_len = (ray.coord[1] - var->cmr.pos_y + (1 - ray.step[1]) / 2);
		draw.vert_len /= ray.dir_ray[1];
		wall_x = var->cmr.pos_x + draw.vert_len * ray.dir_ray[0];
	}
	wall_x -= floor(wall_x);
	tex = var->tex[get_tex_num(ray, side)];
	draw.tex_x = (int)(wall_x * (double)tex.width);
	if (side == 0 && ray.dir_ray[0] > 0)
		draw.tex_x = tex.width - draw.tex_x - 1;
	if (side == 1 && ray.dir_ray[1] < 0)
		draw.tex_x = tex.width - draw.tex_x - 1;
	draw_tex_wall(var, tex, draw, x);
}

void	ray_cast(t_mlx *var)
{
	int		x;
	int		side;
	t_ray	ray;

	x = 0;
	while (x < WIDTH)
	{
		init_ray(var, &ray, x);
		while (1)
		{
			side = proc_dda(&ray);
			if (var->map.map[ray.coord[1]][ray.coord[0]] == '1')
				break ;
		}
		draw_wall(var, ray, side, x);
		x++;
	}
}
