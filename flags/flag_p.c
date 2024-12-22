/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 23:24:07 by ebini             #+#    #+#             */
/*   Updated: 2024/12/22 14:55:20 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include <stdarg.h>
#include <unistd.h>
#include <stdint.h>

int	print_p(va_list value)
{
	uintptr_t	p;
	ssize_t		write_size;

	p = va_arg(value, uintptr_t);
	if (!p)
	{
		write_size = write(1, "(nil)", 5);
		if (write_size < 0)
			return (0);
		return (write_size);
	}
	write_size = write(1, "0x", 2);
	if (write_size < 0)
		write_size = 0;
	return (write_size + print_base(p, "0123456789abcdef", 16));
}
