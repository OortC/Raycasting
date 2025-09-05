/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaebin <jaebin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 15:19:32 by jaeblee           #+#    #+#             */
/*   Updated: 2023/11/11 00:07:21 by jaebin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	signed_size(long long n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n *= -1;
		len++;
	}
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int			len;
	char		*result;
	long long	temp;

	temp = (long long)n;
	len = signed_size(temp);
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
