/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 19:44:58 by ebini             #+#    #+#             */
/*   Updated: 2024/12/05 18:19:47 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>
#include "utils.h"
#include <stdio.h>

int	print_s(va_list value)
{
	char	*s;
	size_t	len;

	s = va_arg(value, char *);
	if (!s)
		return (write(1, "(null)", 6));
	len = ft_strlen(s);
	write(1, s, len);
	return (len);
}
