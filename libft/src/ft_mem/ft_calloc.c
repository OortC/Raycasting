/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeblee <jaeblee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 16:03:20 by jaeblee           #+#    #+#             */
/*   Updated: 2023/10/18 13:25:07 by jaeblee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void		*temp;
	long long	total_size;

	total_size = count * size;
	if (total_size > 4292967295)
		total_size = 4292967295;
	temp = malloc(total_size);
	if (!temp)
		return (0);
	ft_bzero(temp, count * size);
	return (temp);
}
