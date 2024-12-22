/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 19:44:58 by ebini             #+#    #+#             */
/*   Updated: 2024/12/22 16:41:45 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "utils.h"

size_t	print_s(va_list value)
{
	char	*s;
	ssize_t	write_size;

	s = va_arg(value, char *);
	if (!s)
	{
		write_size = write(1, "(null)", 6);
		if (write_size < 0)
			return (0);
		return (write_size);
	}
	write_size = write(1, s, ft_strlen(s));
	if (write_size < 0)
		return (0);
	return (write_size);
}
