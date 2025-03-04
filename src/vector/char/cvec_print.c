/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cvec_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 18:10:56 by saumon            #+#    #+#             */
/*   Updated: 2025/03/04 19:27:30 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include "libft.h"

void	cvec_print(int fd, t_cvector *vector)
{
	size_t	i;

	if (!vector->len)
	{
		ft_dprintf(fd, "[]\n");
		return ;
	}
	ft_dprintf(fd, "[%d", (int)vector->data[0]);
	i = 0;
	while (++i < vector->len)
		ft_dprintf(fd, ", %d", (int)vector->data[i]);
	ft_dprintf(fd, "](%d/%d)\n", (int)vector->len, (int)vector->capacity);
}
