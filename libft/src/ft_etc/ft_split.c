/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeblee <jaeblee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 14:49:07 by jaeblee           #+#    #+#             */
/*   Updated: 2023/10/17 16:41:09 by jaeblee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**free_all(char **temp)
{
	size_t	i;

	i = 0;
	while (temp[i])
		free(temp[i++]);
	free(temp);
	return (0);
}

int	count_words(char const *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] != c && (str[i + 1] == c || str[i + 1] == '\0'))
			count++;
		i++;
	}
	return (count);
}

char	*sperate_words(char const *str, char c)
{
	int		i;
	int		len;
	char	*temp;

	i = 0;
	len = 0;
	if (!str)
		return (0);
	while (str[len] != c && str[len])
		len++;
	temp = (char *)malloc(sizeof(char) * (len + 1));
	if (!temp)
		return (0);
	while (i < len)
	{
		temp[i] = str[i];
		i++;
	}
	temp[i] = '\0';
	return (temp);
}

char	**ft_split(char const *str, char c)
{
	int		i;
	int		count;
	char	**result;

	if (!str)
		return (0);
	i = 0;
	count = count_words(str, c);
	result = (char **)malloc(sizeof(char *) * (count + 1));
	if (!result)
		return (0);
	while (i < count && *str)
	{
		while (*str == c)
			str++;
		if (*str == '\0')
			break ;
		result[i] = sperate_words(str, c);
		if (!result[i])
			return (free_all(result));
		str += ft_strlen(result[i++]);
	}
	result[i] = 0;
	return (result);
}
