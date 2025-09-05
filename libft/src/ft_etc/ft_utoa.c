/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeblee <jaeblee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 15:49:10 by jaeblee           #+#    #+#             */
/*   Updated: 2023/11/09 15:05:47 by jaeblee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	unsigned_size(long long n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_utoa(unsigned int n)
{
	int			len;
	char		*result;
	long long	temp;

	temp = (long long)n;
	len = unsigned_size(temp);
	result = (char *)malloc(sizeof(char) * (len + 1));
	if (!result)
		return (0);
	if (temp < 0)
	{	
		result[0] = '-';
		temp *= -1;
	}
	if (temp == 0)
		result[0] = '0';
	result[len--] = '\0';
	while (temp > 0)
	{
		result[len] = temp % 10 + '0';
		temp /= 10;
		len--;
	}
	return (result);
}
