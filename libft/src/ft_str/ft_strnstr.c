/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaebin <jaebin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 15:07:23 by jaeblee           #+#    #+#             */
/*   Updated: 2023/11/09 22:52:56 by jaebin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	len_nd;

	if (!(*needle))
		return ((char *)haystack);
	if (len == 0)
		return (0);
	len_nd = ft_strlen(needle);
	while (*haystack && len >= len_nd)
	{
		if (ft_strncmp(haystack, needle, len_nd) == 0)
			return ((char *)(haystack));
		haystack++;
		len--;
	}
	return (0);
}
