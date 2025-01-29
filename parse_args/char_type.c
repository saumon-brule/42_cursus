/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_type.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 06:19:48 by ebini             #+#    #+#             */
/*   Updated: 2025/01/28 09:27:52 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

bool	issep(int c)
{
	return ((unsigned char)c == ' '
		|| (unsigned char)c == '\t'
		|| (unsigned char)c == '\n');
}

bool	isquote(int c)
{
	return ((unsigned char)c == '\'' || (unsigned char)c == '"');
}

bool	isescapable(int c)
{
	return ((unsigned char)c == '\''
		|| (unsigned char)c == '"'
		|| (unsigned char)c == '$'
		|| (unsigned char)c == '\\'
		|| (unsigned char)c == ' '
		|| (unsigned char)c == '\t');
}

bool	is_var_name(int c)
{
	return (ft_isalnum(c) || c == '_');
}

bool	is_neutral_end(int c)
{
	return (issep(c) || isquote(c));
}
