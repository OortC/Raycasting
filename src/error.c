/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeblee <jaeblee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 16:45:16 by seungbel          #+#    #+#             */
/*   Updated: 2024/09/17 16:44:18 by jaeblee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
#include "parse.h"

int	send_errmsg(char *msg, int exitcode)
{
	write(2, msg, ft_strlen(msg));
	exit(exitcode);
}

void	handle_error(int type)
{
	if (type == 0)
		write(2, "Error : Malloc failed\n", 22);
	if (type == 1)
		write(2, "Error : Fail to open the file\n", 30);
	exit(1);
}
