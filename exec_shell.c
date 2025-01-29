/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_shell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 19:01:57 by ebini             #+#    #+#             */
/*   Updated: 2025/01/28 15:17:06 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "pipex_utils.h"
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

size_t	count_arg(char *s)
{
	size_t	count;
	int		state;

	if (!*s)
		return (0);
	count = (!issep(*s) && *(s + 1) != '\'' && *(s + 1) != '"');
	state = ((*s == '\'') * ASQ) | ((*s == '"') * ADQ) | ((*s == '\\') * AESC);
	while (*++s)
	{
		if (state & ASQ)
			state = state & (ASQ * (*s != '\''));
		else if (state & AESC)
			state = (state & ~AESC) | WESC;
		else if (state & ADQ)
			state = state & (ADQ * (*s != '"'));
		else
		{
			if (!(state & WESC) && issep(*(s - 1)) && !issep(*s))
				++count;
			state = ((*s == '\'') * ASQ) | ((*s == '"') * ADQ) | ((*s == '\\')
						* AESC);
		}
	}
	return (count);
}

char	*parse_split(int escaped, char **s, char **env)
{
	static int	calls = 0;

	calls += 1;
	// ft_dprintf(2, "\n==call nb %d==\n", calls);
	if (escaped)
	{
		if (isescapable(**(s + 1)))
			*s += 2;
		*s += 1;
		return (ft_strndup(*(s - 1), 1));
	}
	if (**s == '\'')
	{
		return (parse_squote(s));
	}
	if (**s == '"')
	{
		return (parse_dquote(s, env));
	}
	else
		return (parse_neutral(s, env));
}

int	update_result(size_t count, char **result, char *new_string)
{
	char	*temp_result;
	if (result[count])
	{
		temp_result = ft_strjoin(result[count], new_string);
		free(result[count]);
		if (!temp_result)
		{
			free_n(result, count);
			return (-1);
		}
		result[count] = temp_result;
		return (0);
	}
	result[count] = new_string;
	return (0);
}

char	**fill_split(char *s, char **result, char **env)
{
	int		escaped;
	size_t	count;
	char	*parse_result;

	count = 0;
	escaped = *s == '\\';
	while (*s)
	{
		while (issep(*s))
			++s;
		parse_result = parse_split(escaped, &s, env);
		if (!parse_result)
		{
			free_n(result, count);
			return (NULL);
		}
		update_result(count, result, parse_result);
		if (issep(*s))
			++count;
		escaped = !escaped && *s == '\\';
	}
	return (result);
}

int	exec_shell(char *cmd, char **env)
{
	char	*cmd_file;
	char	**splited_cmd;
	size_t	arg_count;
	int		result;

	arg_count = count_arg(cmd);
	splited_cmd = ft_calloc((arg_count + 1), sizeof(char *));
	splited_cmd = fill_split(cmd, splited_cmd, env);
	if (!splited_cmd)
		return (-1);
	cmd_file = parse_command(splited_cmd[0], get_from_env("PATH", env));
	result = execve(cmd_file, splited_cmd, env);
	free_split(splited_cmd);
	free(cmd_file);
	return (result);
}
