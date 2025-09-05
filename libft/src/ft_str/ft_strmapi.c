/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaebin <jaebin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 16:03:30 by jaeblee           #+#    #+#             */
/*   Updated: 2023/10/12 23:44:13 by jaebin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *str, char (*f)(unsigned int, char))
{
	int		i;
	int		len;
	char	*result;

	if (!str)
		return (0);
	i = 0;
	len = ft_strlen(str);
	result = (char *)malloc(sizeof(char) * len + 1);
	if (!result)
		return (0);
	while (i < len)
	{
		result[i] = f(i, str[i]);
		i++;
	}
	result[i] = '\0';
	return (result);
}
