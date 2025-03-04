/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saumon <saumon@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 07:33:43 by saumon            #+#    #+#             */
/*   Updated: 2025/03/03 22:15:18 by saumon           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

# include "defs.h"

typedef struct s_cvector
{
	char	*data;
	size_t	capacity;
	size_t	len;
}			t_cvector;

t_cvector	*cvec_create(char *array, size_t len);
int			cvec_init(t_cvector *vector, char *array, size_t len);
int			cvec_push(t_cvector *vector, char element);
char		cvec_get(t_cvector *vector, ssize_t index);
char		cvec_pop(t_cvector *vector);
void		cvec_print(int fd, t_cvector *vector);
void		cvec_clear(t_cvector *vector);
void		cvec_destroy(t_cvector *vector);

typedef struct s_ivector
{
	int		*data;
	size_t	capacity;
	size_t	len;
}			t_ivector;

t_ivector	*ivec_create(int *array, size_t len);
int			ivec_init(t_ivector *vector, int *array, size_t len);
int			ivec_push(t_ivector *vector, int element);
int			ivec_get(t_ivector *vector, ssize_t index);
int			ivec_pop(t_ivector *vector);
void		ivec_print(int fd, t_ivector *vector);
void		ivec_clear(t_ivector *vector);
void		ivec_destroy(t_ivector *vector);

typedef struct s_lvector
{
	long	*data;
	size_t	capacity;
	size_t	len;
}			t_lvector;

typedef struct s_fvector
{
	float	*data;
	size_t	capacity;
	size_t	len;
}			t_fvector;

typedef struct s_dvector
{
	double	*data;
	size_t	capacity;
	size_t	len;
}			t_dvector;

typedef struct s_pvector
{
	void	**data;
	size_t	capacity;
	size_t	len;
}			t_pvector;

#endif