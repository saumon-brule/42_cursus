/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 03:50:32 by ebini             #+#    #+#             */
/*   Updated: 2024/11/18 23:53:34 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "./get_next_line.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

/**
 * This function will concatenate 2 strings and set the result
 * pointer to this new allocated string and then free s1.
 * It will return the length of s2 that was concatenated or -1 if
 * allocation fails.
 */
int	strjoin_nl(char **s1, t_reader *reader)
{
	size_t	i;
	size_t	pre_len;
	size_t	suf_len;
	char	*result;
	char	*suffix;

	pre_len = ft_strlen(*s1);
	suffix = reader->buffer + reader->pos;
	suf_len = ft_strnlen_nl(suffix, reader->to_read - reader->pos);
	result = malloc(pre_len + suf_len + 1);
	if (!result)
		return (-1);
	i = -1;
	while (++i < pre_len)
		result[i] = (*s1)[i];
	i = -1;
	while (++i < suf_len)
		result[pre_len + i] = suffix[i];
	result[pre_len + i] = '\0';
	reader->pos += suf_len;
	if (*s1)
		free(*s1);
	*s1 = result;
	return (result[pre_len + i - 1] == '\n');
}

int	secure_eof_read(int fd, t_reader *reader, size_t buffer_size, char *result)
{
	reader->to_read = read(fd, reader->buffer, buffer_size);
	if (reader->to_read < 0 || (reader->to_read == 0 && !result))
		return (-1);
	reader->pos = 0;
	return (0);
}

char	*get_next_line(int fd)
{
	static t_reader	reader;
	char			*result;
	int				join_value;

	result = NULL;
	while (1)
	{
		if (reader.pos < reader.to_read)
		{
			join_value = strjoin_nl(&result, &reader);
			if (join_value < 0)
			{
				free(result);
				return (NULL);
			}
			if (join_value)
				return (result);
		}
		else
		{
			if (secure_eof_read(fd, &reader, BUFFER_SIZE, result) < 0)
			{
				free(result);
				return (NULL);
			}
			else if (reader.to_read == 0 && *result != '\0')
				return (result);
		}
	}
}
