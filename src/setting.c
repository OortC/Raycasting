/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungbel <seungbel@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 18:24:04 by seungbel          #+#    #+#             */
/*   Updated: 2024/09/23 15:11:25 by seungbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
#include "parse.h"

int	is_path(char **lst)
{
	if (ft_strncmp(lst[0], "NO", 3) == 0 || ft_strncmp(lst[0], "SO", 3) == 0
		|| ft_strncmp(lst[0], "WE", 3) == 0 || ft_strncmp(lst[0], "EA", 3) == 0)
		return (1);
	else if (ft_strncmp(lst[0], "F", 2) == 0 || ft_strncmp(lst[0], "C", 2) == 0)
		return (0);
	else
		send_errmsg("Error : Not Valid Identifier\n", 1);
	return (0);
}

void	set_texture(char **strlst, t_game *game)
{
	char	*name;
	char	*content;
	char	*content_cp;
	int		fd;

	name = strlst[0];
	content = strlst[1];
	ck_texture_isxpm(content);
	fd = open(content, O_RDONLY);
	if (fd == -1)
		send_errmsg("Error : Wrong Texture Path\n", 1);
	close(fd);
	content_cp = ft_strdup(content);
	if (!content_cp)
		handle_error(0);
	if (ft_strncmp(name, "NO", 3) == 0)
		game->north = content_cp;
	else if (ft_strncmp(name, "SO", 3) == 0)
		game->south = content_cp;
	else if (ft_strncmp(name, "WE", 3) == 0)
		game->west = content_cp;
	else
		game->east = content_cp;
}

void	set_color(char **strlst, t_game *game)
{
	char	**rgb;
	int		color[4];
	int		idx;

	rgb = ft_split(strlst[1], ',');
	if (!rgb)
		handle_error(0);
	if (ft_strlst_len(rgb) != 3)
		send_errmsg("Error : Wrong RGB Format\n", 1);
	idx = -1;
	while (rgb[++idx])
	{
		if (!ck_is_digit(rgb[idx]))
			send_errmsg("Error : RGB should be digit\n", 1);
		if (ft_atoi(rgb[idx]) < 0 || ft_atoi(rgb[idx]) > 255)
			send_errmsg("Error : Over RGB Boundary\n", 1);
		color[idx] = ft_atoi(rgb[idx]);
	}
	free_strlst(&rgb);
	color[3] = (color[0] * 16 * 16 * 16 * 16) + (color[1] * 16 * 16) + color[2];
	if (ft_strncmp(strlst[0], "F", 2) == 0)
		game->floor_color = color[3];
	else
		game->ceiling_color = color[3];
}

int	ck_all_filled(t_game *game)
{
	if (!(game->north) || !(game->south) || !(game->east) || !(game->west)
		|| game->ceiling_color == -1
		|| game->floor_color == -1)
		return (0);
	else
		return (1);
}

void	set_texture_color(char **whole, t_game *game)
{
	int		idx;
	char	**strlst;

	idx = 0;
	while (whole[idx] && idx < 6)
	{
		strlst = ft_split(whole[idx], ' ');
		if (!strlst)
			handle_error(0);
		if (ft_strlst_len(strlst) != 2)
		{
			free_strlst(&strlst);
			send_errmsg("Error : Check your setting lines\n", 1);
		}
		if (is_path(strlst))
			set_texture(strlst, game);
		else
			set_color(strlst, game);
		free_strlst(&strlst);
		idx++;
	}
	if (ck_all_filled(game))
		return ;
	else
		send_errmsg("Error : Not Exact Number of Setting lines\n", 1);
}
