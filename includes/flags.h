/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 18:43:39 by ebini             #+#    #+#             */
/*   Updated: 2024/12/18 22:48:09 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FLAGS_H
# define FLAGS_H
# include <stdarg.h>
# include <sys/types.h>

ssize_t	print_c(va_list value);
ssize_t	print_s(va_list value);
ssize_t	print_p(va_list value);
ssize_t	print_i(va_list value);
ssize_t	print_u(va_list value);
ssize_t	print_low_x(va_list value);
ssize_t	print_up_x(va_list value);
ssize_t	print_up_x(va_list value);

#endif