/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeblee <jaeblee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 13:44:05 by jaeblee           #+#    #+#             */
/*   Updated: 2024/09/20 18:48:06 by jaeblee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	draw_grid(t_mlx *var)
{
	int	dx;
	int	dy;

	dy = 0;
	while (dy <= M_HEIGHT + 2)
	{
		dx = 0;
		while (dx <= M_WIDTH + 2)
		{
			if (dy == 0 || dx == 0 || dy == M_HEIGHT + 2 || dx == M_WIDTH + 2)
				pixel_put(var, 29 + dx, 29 + dy, 0);
			else
				pixel_put(var, 29 + dx, 29 + dy, 0xC0C0C0);
			dx++;
		}
		dy++;
	}
}

void	fill_mini_map(t_mlx *var, int x, int y, char type)
{
	int	dx;
	int	dy;
	int	pos_x;
	int	pos_y;
	int	color;

	if (type == ' ')
		return ;
	if (type == '1')
		color = 0x79EDFF;
	else
		color = 0xFFFFFF;
	dy = 0;
	pos_x = 30 + 9 * x;
	pos_y = 30 + 9 * y;
	while (dy < 9)
	{
		dx = 0;
		while (dx < 9)
		{
			pixel_put(var, pos_x + dx, pos_y + dy, color);
			dx++;
		}
		dy++;
	}
}

void	draw_mini_map(t_mlx *var)
{
	int	x;
	int	y;
	int	dx;
	int	dy;

	dy = 0;
	x = (int)var->cmr.pos_x - 8;
	y = (int)var->cmr.pos_y - 4;
	draw_grid(var);
	while (dy < 9)
	{
		if (y + dy >= 0 && y + dy < var->map.row)
		{
			dx = 0;
			while (dx < 17)
			{
				if (x + dx >= 0 && x + dx < var->map.col)
					fill_mini_map(var, dx, dy, var->map.map[y + dy][x + dx]);
				dx++;
			}
		}
		dy++;
	}
}

void	draw_player(t_mlx *var)
{
	int	dx;
	int	dy;
	int	pos_x;
	int	pos_y;

	dx = -1;
	pos_x = 30 + M_WIDTH / 2;
	pos_y = 30 + M_HEIGHT / 2;
	while (dx <= 1)
	{
		dy = -1;
		while (dy <= 1)
		{
			pixel_put(var, pos_x + dx, pos_y + dy, 0xFF00000);
			dy++;
		}
		dx++;
	}
}
