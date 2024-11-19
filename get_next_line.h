/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 03:51:36 by ebini             #+#    #+#             */
/*   Updated: 2024/11/19 02:07:13 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif
# include <stddef.h>

typedef struct s_reader
{
	char	buffer[BUFFER_SIZE];
	int		to_read;
	int		pos;
}			t_reader;

char		*get_next_line(int fd);
size_t		ft_strlen(const char *s);
size_t		ft_strnlen_nl(const char *s, size_t n);

# define GET_NEXT_LINE_H
#endif
