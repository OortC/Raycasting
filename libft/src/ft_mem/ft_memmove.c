/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaebin <jaebin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 16:31:49 by jaeblee           #+#    #+#             */
/*   Updated: 2023/10/11 18:27:33 by jaebin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*temp_dst;
	unsigned char	*temp_src;

	temp_dst = (unsigned char *)dst;
	temp_src = (unsigned char *)src;
	if (!dst && !src)
		return (0);
	if (temp_dst <= temp_src)
	{
		while (len-- > 0)
			*temp_dst++ = *temp_src++;
	}
	else
	{
		while (len-- > 0)
			*(temp_dst + len) = *(temp_src + len);
	}
	return (dst);
}
