/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeblee <jaeblee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 16:08:18 by jaeblee           #+#    #+#             */
/*   Updated: 2023/12/25 16:13:32 by jaeblee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	gnl_strlen(const char *str)
{
	int	len;

	if (!str)
		return (0);
	len = 0;
	while (str[len])
		len++;
	return (len);
}

char	*gnl_strchr(const char *str, int c)
{
	size_t			i;
	unsigned char	uc;

	if (!str)
		return (0);
	i = 0;
	uc = (unsigned char)c;
	while (str[i])
	{
		if (str[i] == uc)
			return ((char *)(str + i));
		i++;
	}
	if (uc == '\0')
		return ((char *)(str + i));
	return (0);
}

size_t	gnl_strlcat(char *dst, const char *src, size_t len)
{
	size_t	dst_len;
	size_t	src_len;

	if (len == 0)
		return (len + gnl_strlen(src));
	dst_len = gnl_strlen(dst);
	src_len = gnl_strlen(src);
	if (len > dst_len)
	{
		len -= dst_len;
		while (*dst)
			dst++;
		while (*src && len > 1)
		{
			*dst++ = *src++;
			len--;
		}
		*dst = '\0';
		return (dst_len + src_len);
	}
	return (len + src_len);
}

char	*gnl_strdup(char *buff, int *m_size)
{
	int		size;
	char	*result;

	size = gnl_strlen(buff) + 1;
	result = (char *)malloc(sizeof(char) * (BUFFER_SIZE * 2));
	if (!result)
		return (take_free(result));
	*m_size = BUFFER_SIZE * 2;
	result[0] = '\0';
	gnl_strlcat(result, buff, size);
	return (result);
}

char	*gnl_strjoin(char *save, char const *buff, int *m_size)
{
	int		i;
	int		size;
	char	*result;

	result = NULL;
	if (save && buff)
	{
		size = gnl_strlen(save) + gnl_strlen(buff) + 1;
		if (*m_size >= size)
		{
			gnl_strlcat(save, buff, size);
			return (save);
		}
		*m_size = (size / BUFFER_SIZE + 1) * BUFFER_SIZE * 2;
		result = (char *)malloc(sizeof(char) * (*m_size));
		if (!result)
			return (take_free(save));
		i = -1;
		while (++i < (int)gnl_strlen(save))
			result[i] = save[i];
		result[i] = '\0';
		gnl_strlcat(result, buff, size);
	}
	take_free(save);
	return (result);
}
