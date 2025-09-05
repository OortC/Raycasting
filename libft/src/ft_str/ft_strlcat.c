/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeblee <jaeblee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 17:42:01 by jaeblee           #+#    #+#             */
/*   Updated: 2023/10/13 14:34:29 by jaeblee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t len)
{
	size_t	dst_len;
	size_t	src_len;

	if (len == 0)
		return (len + ft_strlen(src));
	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
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
