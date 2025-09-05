/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeblee <jaeblee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 13:42:34 by jaeblee           #+#    #+#             */
/*   Updated: 2024/09/23 19:15:32 by jaeblee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	exit_hook(void)
{
	exit(0);
}

int	key_hook(int key, t_mlx *var)
{
	if (key == ESC)
	{
		mlx_destroy_window(var->mlx, var->win);
		exit_hook();
	}
	else if (key == KEY_W || key == KEY_S)
		var->key.mov_y = key;
	else if (key == KEY_A || key == KEY_D)
		var->key.mov_x = key;
	else if (key == KEY_LEFT || key == KEY_RIGHT)
		var->key.rotate = key;
	return (0);
}

int	key_release(int key, t_mlx *var)
{
	if (key == KEY_W || key == KEY_S)
		var->key.mov_y = -1;
	else if (key == KEY_A || key == KEY_D)
		var->key.mov_x = -1;
	else if (key == KEY_LEFT || key == KEY_RIGHT)
		var->key.rotate = -1;
	return (0);
}
