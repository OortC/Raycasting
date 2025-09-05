/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaebin <jaebin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 17:15:56 by jaeblee           #+#    #+#             */
/*   Updated: 2023/10/11 20:00:14 by jaebin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = ft_strlen(src);
	while (size > 0)
	{
		if (*src == '\0' || size == 1)
		{
			*dst = '\0';
			break ;
		}
		*dst++ = *src++;
		size--;
	}
	return (i);
}
