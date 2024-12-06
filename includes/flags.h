/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 18:43:39 by ebini             #+#    #+#             */
/*   Updated: 2024/12/04 01:44:25 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FLAGS_H
# define FLAGS_H
# include <stdarg.h>

int	print_c(va_list value);
int	print_s(va_list value);
int	print_p(va_list value);
int	print_i(va_list value);
int	print_u(va_list value);
int	print_low_x(va_list value);
int	print_up_x(va_list value);
int	print_up_x(va_list value);

#endif