/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungbel <seungbel@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 12:45:37 by seungbel          #+#    #+#             */
/*   Updated: 2024/09/21 17:43:02 by seungbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
#include "parse.h"

int	ft_strlst_len(char **strlst)
{
	int	idx;

	idx = 0;
	while (strlst[idx])
		idx++;
	return (idx);
}

void	free_strlst(char ***strlst)
{
	int	idx;

	idx = 0;
	while ((*strlst)[idx])
		free((*strlst)[idx++]);
	free((*strlst));
}

void	ft_intset(int *b, int c, size_t len)
{
	size_t	idx;

	idx = 0;
	while (idx < len)
	{
		*(b + idx) = c;
		idx++;
	}
}

char	*file_read(char *file)
{
	int		fd;
	char	*buffer;
	char	*str;
	char	*tmp;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		handle_error(1);
	str = ft_strdup("");
	if (!str)
		handle_error(0);
	while (1)
	{
		buffer = get_next_line(fd);
		if (!buffer)
			break ;
		tmp = str;
		str = ft_strjoin(tmp, buffer);
		free(tmp);
		free(buffer);
		if (!str)
			handle_error(0);
	}
	return (str);
}
