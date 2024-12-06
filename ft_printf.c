/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 14:01:46 by ebini             #+#    #+#             */
/*   Updated: 2024/12/05 18:59:45 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include "utils.h"

int	ft_printf(const char *format, ...)
{
	int		offset;
	int		printed_len;
	int		returned_value;
	va_list	args;

	va_start(args, format);
	printed_len = 0;
	while (*format)
	{
		offset = len_flag(format);
		write(1, format, offset);
		format += offset;
		printed_len += offset;
		if (*format)
		{
			format += 1;
			returned_value = handle_flag(format, args);
			if (returned_value >= 0)
			{
				printed_len += returned_value;
				format++;
			}
		}
	}
	return (printed_len);
}
