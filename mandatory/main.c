/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeblee <jaeblee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 15:44:34 by jaeblee           #+#    #+#             */
/*   Updated: 2024/09/24 13:36:15 by jaeblee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
#include "parse.h"

int	ck_file_cub(char *file)
{
	char	**name_lst;
	int		len;
	int		idx;

	name_lst = ft_split(file, '.');
	if (!name_lst)
		handle_error(0);
	idx = 0;
	while (name_lst[idx])
		idx++;
	len = idx;
	if (ft_strncmp(name_lst[len - 1], "cub", 4) != 0)
		return (0);
	idx = 0;
	while (idx < len)
		free(name_lst[idx++]);
	free(name_lst);
	return (1);
}

void	load_texture(t_mlx *var, t_tex *tex, char *path, t_img *img)
{
	int	x;
	int	y;
	int	*dest;

	img->img = mlx_xpm_file_to_image(var->mlx, path, &img->width, &img->height);
	if (!img->img)
		send_errmsg("Error : Not valid xpm file!\n", 1);
	img->addr = mlx_get_data_addr(img->img, &img->bpp, &img->len, &img->end);
	tex->texture = (int *)malloc(sizeof(int) * (img->width * img->height));
	tex->height = img->height;
	tex->width = img->width;
	y = 0;
	dest = (int *)img->addr;
	while (y < img->height)
	{
		x = 0;
		while (x < img->width)
		{
			tex->texture[img->width * y + x] = dest[img->width * y + x];
			x++;
		}
		y++;
	}
	mlx_destroy_image(var->mlx, img->img);
}

void	set_tex(t_mlx *var)
{
	t_img	img;

	load_texture(var, &var->tex[0], var->game.north, &img);
	load_texture(var, &var->tex[1], var->game.south, &img);
	load_texture(var, &var->tex[2], var->game.west, &img);
	load_texture(var, &var->tex[3], var->game.east, &img);
}

void	free_all(t_mlx *var)
{
	int		idx;

	idx = 0;
	while (var->map.map[idx])
		free(var->map.map[idx++]);
	free(var->map.map);
	free(var->game.north);
	free(var->game.south);
	free(var->game.east);
	free(var->game.west);
	idx = 0;
	while (idx < 4)
		free(var->tex[idx].texture);
}

int	main(int argc, char **argv)
{
	t_mlx	var;

	if (argc != 2)
		send_errmsg("Error: Input only 1 argument\n", 1);
	if (!ck_file_cub(argv[1]))
		send_errmsg("Error: Invalid file format\n", 1);
	set_map(argv[1], &var);
	init_cmr(&var);
	init_key(&var);
	init_image(&var);
	set_tex(&var);
	mlx_hook(var.win, KEY_PRESS, 0, key_hook, &var);
	mlx_hook(var.win, KEY_RELEASE, 0, key_release, &var);
	mlx_hook(var.win, 17, 0, exit_hook, &var);
	mlx_loop_hook(var.mlx, loop_main, &var);
	mlx_loop(var.mlx);
	free_all(&var);
	return (0);
}
