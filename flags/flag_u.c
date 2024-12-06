/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_u.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 00:34:32 by ebini             #+#    #+#             */
/*   Updated: 2024/12/04 01:48:15 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include "utils.h"

int	print_unsigned(unsigned int n)
{
	char	c;
	int		child_len;

	c = '0' + n % 10;
	n /= 10;
	child_len = 1;
	if (n)
		child_len += print_unsigned(n);
	write(1, &c, 1);
	return (child_len);
}

int	print_u(va_list value)
{
	return (print_unsigned(va_arg(value, unsigned)));
}
