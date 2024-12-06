/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 18:36:02 by ebini             #+#    #+#             */
/*   Updated: 2024/12/04 02:57:09 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H
# include <stddef.h>
# include <stdarg.h>
# include <stdint.h>

size_t	ft_strlen(const char *s);
size_t	len_flag(const char *s);
int		print_base(unsigned long long n, char *base, int base_len);

int		handle_flag(const char *format, va_list args);

#endif