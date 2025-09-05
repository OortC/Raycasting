/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_ck.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungbel <seungbel@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 17:44:42 by seungbel          #+#    #+#             */
/*   Updated: 2024/09/23 15:20:55 by seungbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
#include "parse.h"

int	ck_str_character(char *str, t_game *game)
{
	int	idx;

	idx = 0;
	while (str[idx])
	{
		if (str[idx] == '1' || str[idx] == '0' || str[idx] == ' ')
			idx++;
		else if (str[idx] == 'N' || str[idx] == 'S'
			|| str[idx] == 'E' || str[idx] == 'W')
		{
			if (game->is_player != 0)
				send_errmsg("Error : Check the player\n", 1);
			game->is_player = 1;
			idx++;
		}
		else
			return (0);
	}
	return (1);
}

void	ck_map_valid(char **map, t_game *game)
{
	int	idx;

	game->is_player = 0;
	idx = -1;
	while (map[++idx])
	{
		if (!ck_str_character(map[idx], game))
			send_errmsg("Error : Check the map characters\n", 1);
	}
	if (game->is_player != 1)
		send_errmsg("Error : Check the player\n", 1);
	ck_map_closed(map, game);
}

int	ck_map_max_col(char **map)
{
	int		idx;
	int		len;
	int		max_len;

	if (!map)
		return (0);
	idx = 0;
	max_len = 0;
	while (map[idx])
	{
		if (!map[idx])
			len = 0;
		else
			len = ft_strlen(map[idx]);
		if (!max_len || len > max_len)
			max_len = len;
		idx++;
	}
	return (max_len);
}

int	ck_is_digit(char *rgb)
{
	int	idx;

	idx = 0;
	while (rgb[idx])
	{
		if (!ft_isdigit(rgb[idx]))
			return (0);
		idx++;
	}
	return (1);
}

void	ck_texture_isxpm(char *content)
{
	char	**name_lst;
	int		len;
	int		idx;

	name_lst = ft_split(content, '.');
	if (!name_lst)
		handle_error(0);
	idx = 0;
	while (name_lst[idx])
		idx++;
	len = idx;
	if (ft_strncmp(name_lst[len - 1], "xpm", 4) != 0)
	{
		free(name_lst);
		send_errmsg("Error : Texture file should end with .xpm\n", 1);
	}
	idx = 0;
	while (idx < len)
		free(name_lst[idx++]);
	free(name_lst);
}
