/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeblee <jaeblee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 17:29:11 by jaeblee           #+#    #+#             */
/*   Updated: 2023/12/25 16:13:46 by jaeblee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

# ifndef OPEN_MAX
#  define OPEN_MAX 256
# endif

size_t	gnl_strlen(const char *str);
size_t	gnl_strlcat(char *dst, const char *src, size_t len);
char	*gnl_strdup(char *buff, int *m_size);
char	*gnl_strchr(const char *str, int c);
char	*gnl_strjoin(char *save, char const *buff, int *m_size);

char	*take_free(char *temp);
char	*take_save(char	*str);
char	*take_line(char	*str);
char	*read_buff(int fd, char *save);
char	*get_next_line(int fd);

#endif