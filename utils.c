/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 14:06:12 by ebini             #+#    #+#             */
/*   Updated: 2024/12/22 15:22:23 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

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
	int		writed_size;

	c = n % base_len;
	n /= base_len;
	if (n)
		writed_size = print_base(n, base, base_len);
	else
		writed_size = 0;
	if (write(1, base + c, 1) >= 0)
		++writed_size;
	return (writed_size);
}
