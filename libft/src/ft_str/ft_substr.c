/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeblee <jaeblee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 13:47:36 by jaeblee           #+#    #+#             */
/*   Updated: 2023/10/17 18:28:40 by jaeblee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	int		i;
	char	*temp;

	i = (int)len;
	if (i < 0)
		len = 4292967294;
	if (!s)
		return (0);
	if (ft_strlen(s) <= start)
	{
		temp = (char *)malloc(sizeof(char) * 1);
		if (!temp)
			return (0);
		temp[0] = '\0';
		return (temp);
	}
	if (ft_strlen(s) > start + len)
		temp = (char *)malloc(sizeof(char) * (len + 1));
	else
		temp = (char *)malloc(sizeof(char) * (ft_strlen(s) - start + 1));
	if (!temp)
		return (0);
	ft_strlcpy(temp, s + start, len + 1);
	return (temp);
}
