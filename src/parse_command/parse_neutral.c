/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_neutral.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 06:41:00 by ebini             #+#    #+#             */
/*   Updated: 2025/02/06 19:05:14 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "pipex_utils.h"

static ssize_t	parse_var(char *s, size_t *i, t_list **vars, char **env)
{
	bool	is_isolated;
	char	*var_name;

	++*i;
	is_isolated = s[*i] == '{';
	if (is_isolated)
		++*i;
	var_name = s + *i;
	*i += var_name_len(var_name);
	if (is_isolated && s[*i] != '}')
	{
		ft_dprintf(2, "pipex: bad substitution\n");
		return (-1);
	}
	var_name = ft_strndup(var_name, s + *i - var_name);
	if (!var_name)
		return (-1);
	lstadd_front(vars, lstnew(get_from_env(var_name, env)));
	free(var_name);
	if (is_isolated)
		++*i;
	return (ft_strlen((*vars)->content));
}

static ssize_t	neutral_len(char *s, t_list **vars, char **env)
{
	size_t	i;
	size_t	len;
	ssize_t	var_result;

	i = 0;
	len = 0;
	while (s[i] && (!is_neutral_end(s[i]) || is_escaped(s, i)))
	{
		if (s[i] == '$' && !is_escaped(s, i) && (is_var_name(s[i + 1])
				|| (s[i + 1] == '{' && is_var_name(s[i + 2]))))
		{
			var_result = parse_var(s, &i, vars, env);
			if (var_result == -1)
				return (-1);
			len += var_result;
			continue ;
		}
		len += (!is_escaped(s, i)
				|| (s[i] != '$' && !is_neutral_end(s[i])));
		++i;
	}
	return (len);
}

static void	handle_backslash(char *src, char *dest, size_t *i, size_t *len)
{
	if (src[*i + 1] == '$' || is_neutral_end(src[*i + 1]))
	{
		dest[*len] = src[*i + 1];
		++*i;
		++*len;
	}
	else
	{
		dest[*len] = src[*i];
		++*len;
	}
}

static size_t	str_replace(char *src, char *dest, size_t n, t_list **vars)
{
	size_t	i;
	size_t	len;

	len = 0;
	i = 0;
	while (len < n || (*vars && len == 0))
	{
		if (src[i] == '$' && !is_escaped(src, i) && (is_var_name(src[i + 1])
				|| (src[i + 1] == '{' && is_var_name(src[i + 2]))))
		{
			len += ft_strcpy_len(lstpop(vars), dest + len);
			i += var_len(src + i);
			continue ;
		}
		if (src[i] == '\\')
			handle_backslash(src, dest, &i, &len);
		else
		{
			dest[len] = src[i];
			++len;
		}
		++i;
	}
	dest[n] = '\0';
	return (i);
}

char	*parse_neutral(char **s, char **env)
{
	ssize_t	size;
	t_list	*vars;
	char	*result;

	vars = NULL;
	size = neutral_len(*s, &vars, env);
	if (size == -1)
	{
		lstclear(&vars, NULL);
		return (NULL);
	}
	result = malloc(size + 1);
	if (!result)
		return (NULL);
	*s += str_replace(*s, result, size, &vars);
	return (result);
}
