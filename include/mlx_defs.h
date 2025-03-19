/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_defs.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 10:58:10 by ebini             #+#    #+#             */
/*   Updated: 2025/02/23 10:58:11 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_DEFS_H
# define MLX_DEFS_H

# include <X11/Xlib.h>
# include <X11/Xutil.h>
# include <X11/extensions/XShm.h>

typedef struct s_img
{
	XImage			*image;
	Pixmap			pix;
	GC				gc;
	int				size_line;
	int				bpp;
	int				width;
	int				height;
	int				type;
	int				format;
	char			*data;
	XShmSegmentInfo	shm;
}				t_img;

#endif
