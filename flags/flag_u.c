/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_u.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 00:34:32 by ebini             #+#    #+#             */
/*   Updated: 2024/12/22 16:42:33 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include "utils.h"

size_t	print_unsigned(unsigned int n)
{
	char	c;
	size_t	child_len;

	c = '0' + n % 10;
	n /= 10;
	if (n)
		child_len = print_unsigned(n);
	else
		child_len = 0;
	child_len += write(1, &c, 1) > 0;
	return (child_len);
}

size_t	print_u(va_list value)
{
	return (print_unsigned(va_arg(value, unsigned)));
}
