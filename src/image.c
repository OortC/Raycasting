/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeblee <jaeblee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 15:54:21 by jaeblee           #+#    #+#             */
/*   Updated: 2024/09/24 13:14:18 by jaeblee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	pixel_put(t_mlx *var, int x, int y, int color)
{
	char	*dest;

	dest = var->img.addr + (y * var->img.len + x * (var->img.bpp / 8));
	*(unsigned int *)dest = color;
}

void	reset_image(t_mlx *var)
{
	int	i;
	int	*dest;

	i = 0;
	dest = (int *)var->img.addr;
	while (i < WIDTH * HEIGHT / 2 - 1)
	{
		dest[i] = var->game.ceiling_color;
		i++;
	}
	while (i < WIDTH * HEIGHT)
	{
		dest[i] = var->game.floor_color;
		i++;
	}
}

void	print_image(t_mlx *var)
{
	reset_image(var);
	ray_cast(var);
	draw_mini_map(var);
	draw_player(var);
	mlx_put_image_to_window(var->mlx, var->win, var->img.img, 0, 0);
}

int	loop_main(t_mlx *var)
{
	print_image(var);
	move_loop(var);
	return (0);
}
