/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungbel <seungbel@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 16:08:51 by seungbel          #+#    #+#             */
/*   Updated: 2024/09/23 15:16:57 by seungbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include "cub.h"

typedef struct s_mat
{
	int	row;
	int	col;
}	t_mat;

typedef struct s_node
{
	t_mat			mat;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	t_node	*top;
}	t_stack;

// error.c
int		send_errmsg(char *msg, int exitcode);
void	handle_error(int type);

// utils.c
int		ft_strlst_len(char **strlst);
void	free_strlst(char ***strlst);
void	ft_intset(int *b, int c, size_t len);
char	*file_read(char *file);

// setting.c
int		is_path(char **lst);
void	set_texture(char **strlst, t_game *game);
void	set_color(char **strlst, t_game *game);
int		ck_all_filled(t_game *game);
void	set_texture_color(char **whole, t_game *game);

// map.c
void	set_map(char *file, t_mlx *var);
char	**mk_map(char **whole);
void	fill_the_map(char **map);

// map_ck_first.c
void	ck_is_map_right(char *str);
void	it_is_map(char *str, int idx);
void	it_isnt_map(char *str, int idx, int *ismap);

// map_ck.c
int		ck_str_character(char *str, t_game *game);
void	ck_map_valid(char **map, t_game *game);
int		ck_map_max_col(char **map);
int		ck_is_digit(char *rgb);
void	ck_texture_isxpm(char *content);

// map_dfs.c
void	mk_dxdy(t_game *game);
void	map_dfs(char **map, int **vis, t_game *game, t_stack *stack);
void	ck_map_closed(char **map, t_game *game);

// map_stack.c
void	init_stack(t_stack *stack);
int		isempty(t_stack *stack);
void	push(t_stack *stack, int row, int col);
t_mat	pop(t_stack *stack);

#endif