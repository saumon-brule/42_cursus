/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 14:06:12 by ebini             #+#    #+#             */
/*   Updated: 2024/12/04 02:56:51 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <unistd.h>

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = -1;
	while (s[++i])
		;
	return (i);
}

size_t	len_flag(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != '%')
		i++;
	return (i);
}

int	print_base(unsigned long long n, char *base, int base_len)
{
	char	c;
	int		child_len;

	c = n % base_len;
	n /= base_len;
	child_len = 1;
	if (n)
		child_len += print_base(n, base, base_len);
	write(1, base + c, 1);
	return (child_len);
}
