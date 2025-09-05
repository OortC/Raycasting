/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_dfs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeblee <jaeblee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 17:28:35 by seungbel          #+#    #+#             */
/*   Updated: 2024/09/17 16:26:06 by jaeblee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
#include "parse.h"

void	find_zero(char **map, int ***vis, t_stack *stack)
{
	int		row;
	int		col;

	row = 0;
	while (map[row])
	{
		col = 0;
		while (map[row][col])
		{
			if (map[row][col] != '1' && map[row][col] != ' '
				&& (*vis)[row][col] == 0)
			{
				(*vis)[row][col] = 1;
				push(stack, row, col);
				return ;
			}
			col++;
		}
		row++;
	}
}

void	mk_dxdy(t_game *game)
{
	game->dx[0] = 1;
	game->dy[0] = 0;
	game->dx[1] = 0;
	game->dy[1] = 1;
	game->dx[2] = -1;
	game->dy[2] = 0;
	game->dx[3] = 0;
	game->dy[3] = -1;
}

void	do_dfs(char **map, int ***vis, t_game *game, t_stack *stack)
{
	int		idx;
	t_mat	mat;
	int		nx;
	int		ny;

	idx = 0;
	mat = pop(stack);
	while (idx < 4)
	{
		nx = mat.row + (game->dx)[idx];
		ny = mat.col + (game->dy)[idx++];
		if (nx < 0 || nx >= game->row
			|| ny < 0 || ny >= (int)ft_strlen(map[mat.row]))
		{
			if (map[mat.row][mat.col] != '1' && map[mat.row][mat.col] != ' ')
				send_errmsg("Error : map is not closed with 1\n", 1);
			continue ;
		}
		if (map[nx][ny] == '1' || (*vis)[nx][ny] == 1)
			continue ;
		if (map[nx][ny] == ' ')
			send_errmsg("Error : map is not closed with 1\n", 1);
		(*vis)[nx][ny] = 1;
		push(stack, nx, ny);
	}
}

void	map_dfs(char **map, int **vis, t_game *game, t_stack *stack)
{
	find_zero(map, &vis, stack);
	while (!isempty(stack))
	{
		do_dfs(map, &vis, game, stack);
		if (isempty(stack))
			find_zero(map, &vis, stack);
	}
}

void	ck_map_closed(char **map, t_game *game)
{
	int		**vis;
	int		row;
	t_stack	stack;

	game->row = ft_strlst_len(map);
	vis = (int **)malloc(sizeof(int *) * game->row);
	if (!vis)
		handle_error(0);
	row = 0;
	while (row < game->row)
	{
		vis[row] = (int *)malloc(sizeof(int) * ft_strlen(map[row]));
		if (!vis[row])
			handle_error(0);
		ft_intset(vis[row], 0, ft_strlen(map[row]));
		row++;
	}
	mk_dxdy(game);
	init_stack(&stack);
	map_dfs(map, vis, game, &stack);
	row = 0;
	while (row < game->row)
		free(vis[row++]);
	free(vis);
}
