/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 19:03:25 by ebini             #+#    #+#             */
/*   Updated: 2025/01/15 19:14:29 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdarg.h>

int	ft_printf(const char *format, ...)
{
	va_list	args;

	va_start(args, format);
	ft_fprintf(1, format, args);
	va_end(args);
}
