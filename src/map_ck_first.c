/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_ck_first.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungbel <seungbel@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 19:47:11 by seungbel          #+#    #+#             */
/*   Updated: 2024/09/23 15:38:07 by seungbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
#include "parse.h"

void	it_is_map(char *str, int idx)
{
	int	idx2;

	idx2 = idx + 1;
	while (str[idx2] == '\n')
		idx2++;
	if (idx + 2 != idx2 && str[idx2])
		send_errmsg("Error : Empty line inside the map!\n", 1);
}

void	it_isnt_map(char *str, int idx, int *ismap)
{
	int	idx2;

	idx2 = idx;
	while (str[idx2] && str[idx2] != '\n')
	{
		if (str[idx2] == '1' || str[idx2] == ' ')
			idx2--;
		else
			break ;
	}
	if (str[idx2] == '\n')
		*ismap = 1;
	if (*ismap)
		it_is_map(str, idx);
}

void	ck_is_map_right(char *str)
{
	int	idx;
	int	ismap;

	idx = 0;
	ismap = 0;
	while (str[idx] && str[idx + 1])
	{
		if (str[idx] == '1' && str[idx + 1] == '\n')
		{
			if (ismap)
				it_is_map(str, idx);
			else
				it_isnt_map(str, idx, &ismap);
		}
		idx++;
	}
}
