/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_i.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 00:16:58 by ebini             #+#    #+#             */
/*   Updated: 2024/12/22 15:18:10 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <aio.h>
#include <stdarg.h>
#include <unistd.h>

static int	handle_n(int n, char *c, ssize_t *write_len)
{
	if (n < 0)
	{
		*write_len = write(1, "-", 1);
		*c = '0' - n % 10;
		return (-(n / 10));
	}
	else
	{
		*write_len = 0;
		*c = '0' + n % 10;
		return (n / 10);
	}
}

ssize_t	print_int(int n)
{
	char	c;
	ssize_t	printed_len;
	ssize_t	write_size;

	n = handle_n(n, &c, &write_size);
	write_size = write_size == 1;
	printed_len = write_size;
	if (n)
		printed_len += print_int(n);
	write_size = write(1, &c, 1);
	if (write_size < 1)
		printed_len = 0;
	return (printed_len + write_size);
}

ssize_t	print_i(va_list value)
{
	return (print_int(va_arg(value, int)));
}
