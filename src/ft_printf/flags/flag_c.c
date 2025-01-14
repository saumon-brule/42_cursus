/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 19:21:47 by ebini             #+#    #+#             */
/*   Updated: 2024/12/22 16:20:05 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>

size_t	print_c(va_list value)
{
	char	c;
	int		write_size;

	c = va_arg(value, int);
	write_size = write(1, &c, 1);
	if (write_size < 0)
		return (0);
	return (write_size);
}
