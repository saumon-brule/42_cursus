/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defs.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 16:22:00 by ebini             #+#    #+#             */
/*   Updated: 2025/01/07 17:13:39 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFS_H
# include <limits.h>
# include <stdbool.h>
# include <stddef.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}		t_list;

# define DEFS_H
#endif
