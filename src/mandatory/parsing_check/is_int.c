/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_int.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 16:54:28 by ebini             #+#    #+#             */
/*   Updated: 2025/03/04 19:26:59 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

bool	is_str_smaller(char *s1, char *s2)
{
	bool	negative1;
	bool	negative2;
	size_t	len1;
	size_t	len2;

	negative1 = *s1 == '-';
	negative2 = *s2 == '-';
	if (negative1)
		++s1;
	if (negative2)
		++s2;
	if (negative1 != negative2)
		return (negative1);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	if (len1 != len2)
	{
		if (negative1)
			return (len1 > len2);
		return (len1 < len2);
	}
	if (negative1)
		return (ft_strcmp(s1, s2) > 0);
	return (ft_strcmp(s1, s2) < 0);
}

bool	is_int(char *s)
{
	return (!is_str_smaller(s, "-2147483648")
		&& is_str_smaller(s, "2147483648"));
}
