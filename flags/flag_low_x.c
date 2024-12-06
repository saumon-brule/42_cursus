/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_low_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 23:24:07 by ebini             #+#    #+#             */
/*   Updated: 2024/12/04 01:44:50 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include <stdarg.h>

int	print_low_x(va_list value)
{
	return (print_base(va_arg(value, unsigned), "0123456789abcdef", 16));
}
