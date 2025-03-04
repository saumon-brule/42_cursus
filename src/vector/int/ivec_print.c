/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ivec_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saumon <saumon@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 17:56:02 by saumon            #+#    #+#             */
/*   Updated: 2025/03/03 18:16:14 by saumon           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include "libft.h"

void	ivec_print(int fd, t_ivector *vector)
{
	size_t	i;

	if (!vector->len)
	{
		ft_dprintf(fd, "[](%d/%d)\n", (int)vector->len, (int)vector->capacity);
		return ;
	}
	ft_dprintf(fd, "[%d", vector->data[0]);
	i = 0;
	while (++i < vector->len)
		ft_dprintf(fd, ", %d", vector->data[i]);
	ft_dprintf(fd, "](%d/%d)\n", (int)vector->len, (int)vector->capacity);
}
