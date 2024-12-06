/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_i.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 00:16:58 by ebini             #+#    #+#             */
/*   Updated: 2024/12/04 01:46:45 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include "utils.h"

int	print_int(int n)
{
	char	c;
	int		child_len;

	if (n < 0)
	{
		child_len = 2;
		write(1, "-", 1);
		c = '0' - n % 10;
		n = -(n / 10);
	}
	else
	{
		child_len = 1;
		c = '0' + n % 10;
		n /= 10;
	}
	if (n)
		child_len += print_int(n);
	write(1, &c, 1);
	return (child_len);
}

int	print_i(va_list value)
{
	return (print_int(va_arg(value, int)));
}
