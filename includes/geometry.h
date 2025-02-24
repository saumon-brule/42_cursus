/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geometry.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 17:57:26 by ebini             #+#    #+#             */
/*   Updated: 2025/02/23 10:42:49 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef GEOMETRY_H
# define GEOMETRY_H

typedef struct s_point
{
	double	x;
	double	y;
}			t_point;

typedef struct s_vec
{
	double	x;
	double	y;
}			t_vec;

typedef struct s_dim
{
	double	w;
	double	h;
}			t_dim;

typedef struct s_segment
{
	t_point	pos;
	t_vec	vec;
}			t_segment;

typedef struct s_square
{
	t_point	pos;
	double	size;
}			t_square;

typedef struct s_index
{
	int	x;
	int	y;
}			t_index;

typedef struct s_area
{
	int	w;
	int	h;
}			t_area;

#endif