/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeblee <jaeblee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 16:07:56 by jaeblee           #+#    #+#             */
/*   Updated: 2023/12/25 16:13:40 by jaeblee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*take_free(char *temp)
{
	free(temp);
	temp = NULL;
	return (temp);
}

char	*take_save(char	*str)
{
	int		i;
	int		j;
	int		len;
	char	*save;

	if (!str)
		return (0);
	len = gnl_strlen(str);
	save = gnl_strchr(str, '\n');
	if (save)
	{
		i = 0;
		j = save - str + 1;
		if (!str[j])
			return (take_free(str));
		save = (char *)malloc(sizeof(char) * (len - j + 1));
		if (!save)
			return (take_free(str));
		while (j <= len)
			save[i++] = str[j++];
	}
	take_free(str);
	return (save);
}

char	*take_line(char	*str)
{
	int		i;
	int		size;
	char	*temp;
	char	*line;

	if (!str)
		return (0);
	temp = gnl_strchr(str, '\n');
	if (temp)
		size = temp - str + 2;
	else
		size = gnl_strlen(str) + 1;
	line = (char *)malloc(sizeof(char) * size);
	if (!line)
		return (0);
	i = -1;
	while (++i < size - 1)
		line[i] = str[i];
	line[i] = '\0';
	return (line);
}

char	*read_buff(int fd, char *save)
{
	int		m_size;
	int		r_size;
	char	buff[BUFFER_SIZE + 1];

	m_size = gnl_strlen(save);
	while (!(gnl_strchr(save, '\n')))
	{
		r_size = read(fd, buff, BUFFER_SIZE);
		if (r_size < 0)
			return (take_free(save));
		if (r_size == 0)
			break ;
		buff[r_size] = '\0';
		if (!save)
			save = gnl_strdup(buff, &m_size);
		else
			save = gnl_strjoin(save, buff, &m_size);
		if (!save)
			return (0);
	}
	return (save);
}

char	*get_next_line(int fd)
{
	char		*result;
	static char	*save;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > OPEN_MAX)
		return (0);
	save = read_buff(fd, save);
	if (!save)
		return (0);
	result = take_line(save);
	if (!result)
	{
		save = take_free(save);
		return (0);
	}
	save = take_save(save);
	return (result);
}
