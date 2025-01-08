/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 15:09:30 by ebini             #+#    #+#             */
/*   Updated: 2025/01/07 16:19:01 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

void	ft_strcpy(const char *src, char *dest)
{
	size_t	i;

	i = -1;
	while (src[++i])
	{
		dest[i] = src[i];
	}
}

void	ft_strncpy(const char *src, char *dest, size_t n)
{
	size_t	i;

	i = 0;
	while (src[i] && i < n)
	{
		dest[i] = src[i];
		i++;
	}
}
