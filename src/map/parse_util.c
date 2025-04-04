/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 06:02:19 by ebini             #+#    #+#             */
/*   Updated: 2025/04/03 06:07:12 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	convert_line_to_string(char *line)
{
	const size_t	line_len = ft_strlen(line);

	if (line[line_len - 1] == '\n')
		line[line_len - 1] = '\0';
}
