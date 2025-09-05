/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungbel <seungbel@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 14:53:52 by seungbel          #+#    #+#             */
/*   Updated: 2024/09/23 15:07:55 by seungbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
#include "parse.h"

char	**mk_map(char **whole)
{
	int		idx;
	int		idx2;
	int		len;
	char	**map;

	idx = 6;
	len = ft_strlst_len(&whole[idx]);
	map = (char **)malloc(sizeof(char *) * (len + 1));
	if (!map)
		handle_error(0);
	idx2 = 0;
	while (whole[idx])
	{
		map[idx2] = ft_strdup(whole[idx++]);
		if (!map[idx2])
		{
			while (idx2 > 0)
				free(map[--idx2]);
			free(map);
			handle_error(0);
		}
		idx2++;
	}
	map[idx2] = 0;
	return (map);
}

void	fill_the_map(char **map)
{
	int		max_col;
	int		idx;
	int		idx2;
	char	*tmp;

	max_col = ck_map_max_col(map);
	idx = -1;
	while (map[++idx])
	{
		if ((int)ft_strlen(map[idx]) < max_col)
		{
			tmp = (char *)malloc(sizeof(char) * (max_col + 1));
			if (!tmp)
				handle_error(0);
			idx2 = -1;
			while (map[idx][++idx2])
				tmp[idx2] = map[idx][idx2];
			while (idx2 < max_col)
				tmp[idx2++] = ' ';
			tmp[idx2] = 0;
			free(map[idx]);
			map[idx] = tmp;
		}
	}
}

void	init_texture_color(t_mlx *var)
{
	var->game.north = 0;
	var->game.south = 0;
	var->game.west = 0;
	var->game.east = 0;
	var->game.ceiling_color = -1;
	var->game.floor_color = -1;
}

void	set_map(char *file, t_mlx *var)
{
	char	*str;
	char	**whole;
	char	**map;

	str = file_read(file);
	ck_is_map_right(str);
	whole = ft_split(str, '\n');
	free(str);
	if (!whole)
		handle_error(0);
	init_texture_color(var);
	set_texture_color(whole, &(var->game));
	map = mk_map(whole);
	free_strlst(&whole);
	ck_map_valid(map, &(var->game));
	fill_the_map(map);
	var->map.map = map;
	var->map.row = var->game.row;
	var->map.col = ck_map_max_col(map);
}
