/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 22:25:30 by ebini             #+#    #+#             */
/*   Updated: 2025/03/18 22:25:57 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "mlx.h"
#include "so_long_defs.h"

void	clean_mlx(t_mlx *mlx)
{
	mlx_destroy_display(mlx);
	free(mlx);
}
