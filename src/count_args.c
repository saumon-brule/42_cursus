/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 12:30:53 by ebini             #+#    #+#             */
/*   Updated: 2025/03/01 14:55:11 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "pipex_utils.h"

void	offset_squote(char **s)
{
	size_t	i;

	i = 0;
	while ((*s)[++i] && (*s)[i] != '\'')
		;
	(*s) += i + 1;
}

void	offset_dquote(char **s)
{
	size_t	i;

	i = 0;
	while ((*s)[++i] && ((*s)[i] != '\"' || is_escaped((*s), i)))
		;
	(*s) += i + 1;
}

void	offset_neutral(char **s)
{
	int	i;

	i = -1;
	while ((*s)[++i] && (!is_neutral_end((*s)[i]) || is_escaped((*s), i)))
		;
	(*s) += i;
}

void	offset_separator(char **s)
{
	while (**s == ' ' || **s == '\t')
		++*s;
}

size_t	count_args(char *s)
{
	size_t	count;

	count = 1;
	while (*++s)
	{
		if (*s == '\'')
			offset_squote(&s);
		else if (*s == '\"')
			offset_squote(&s);
		else if (*s != ' ' && *s != '\t')
			offset_neutral(&s);
		if (*s == ' ' || *s == '\t')
		{
			offset_separator(&s);
			++count;
		}
	}
	return (count);
}
