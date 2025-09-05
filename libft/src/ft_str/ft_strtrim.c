/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeblee <jaeblee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 14:08:39 by jaeblee           #+#    #+#             */
/*   Updated: 2023/10/18 13:43:52 by jaeblee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*dup_result(char const *str, int *start, int *end)
{
	char	*result;

	if (str[*start] == '\0' && str[*end] == '\0')
	{
		result = (char *)malloc(sizeof(char) * 1);
		*start += 1;
	}
	else
		result = (char *)malloc(sizeof(char) * (*end - *start + 2));
	return (result);
}

char	*ft_strtrim(char const *str, char const *set)
{
	int		i;
	int		start;
	int		end;
	char	*result;

	if (!str)
		return (0);
	i = 0;
	start = 0;
	end = ft_strlen(str);
	while (ft_strchr(set, str[start]) && str[start])
		start++;
	while (ft_strrchr(set, str[end]) && end > start)
		end--;
	result = dup_result(str, &start, &end);
	if (!result)
		return (0);
	while (start <= end)
		result[i++] = str[start++];
	result[i] = '\0';
	return (result);
}
