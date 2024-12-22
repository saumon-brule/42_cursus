/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_flag.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 18:43:28 by ebini             #+#    #+#             */
/*   Updated: 2024/12/18 23:02:20 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "flags.h"

ssize_t	handle_flag(const char *format, va_list args)
{
	if (*format == 'c')
		return (print_c(args));
	else if (*format == 's')
		return (print_s(args));
	else if (*format == 'p')
		return (print_p(args));
	else if (*format == 'd' || *format == 'i')
		return (print_i(args));
	else if (*format == 'u')
		return (print_u(args));
	else if (*format == 'x')
		return (print_low_x(args));
	else if (*format == 'X')
		return (print_up_x(args));
	else if (*format == '%')
		return (write(1, format, 1));
	return (-1);
}
