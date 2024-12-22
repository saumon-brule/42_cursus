/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 14:01:46 by ebini             #+#    #+#             */
/*   Updated: 2024/12/22 16:44:11 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include "utils.h"

size_t	print_text(const char **format)
{
	size_t	offset;
	ssize_t	writed_len;

	offset = len_flag(*format);
	writed_len = write(1, *format, offset);
	*format += offset;
	if (writed_len < 0)
		return (0);
	return (writed_len);
}

size_t	print_flag(const char **format, va_list args)
{
	size_t	flag_value;

	++(*format);
	flag_value = handle_flag(*format, args);
	++(*format);
	return (flag_value);
}

int	ft_printf(const char *format, ...)
{
	int		text_len;
	int		printed_len;
	int		flag_value;
	va_list	args;

	if (!format)
		return (-1);
	va_start(args, format);
	printed_len = 0;
	while (*format)
	{
		text_len = print_text(&format);
		if (text_len < 0)
			printed_len += text_len;
		printed_len += text_len;
		if (*format)
		{
			flag_value = print_flag(&format, args);
			printed_len += flag_value;
		}
	}
	return (printed_len);
}
