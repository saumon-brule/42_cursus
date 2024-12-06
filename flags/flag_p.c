/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 23:24:07 by ebini             #+#    #+#             */
/*   Updated: 2024/12/04 02:57:13 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include <stdarg.h>
#include <unistd.h>
#include <stdint.h>

int	print_p(va_list value)
{
	uintptr_t	p;

	p = va_arg(value, uintptr_t);
	if (!p)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	write(1, "0x", 2);
	return (2 + print_base(p, "0123456789abcdef", 16));
}
