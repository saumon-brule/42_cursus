/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_shell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 19:01:57 by ebini             #+#    #+#             */
/*   Updated: 2025/03/01 16:16:00 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "pipex_utils.h"

char	*parse_split(bool *escaped, char **s, char **env)
{
	if (*escaped)
	{
		ft_dprintf(2, "%s\n", *s);
		if (isescapable(*(*s + 1)))
		{
			*s += 2;
			*escaped = false;
		}
		else
			*s += 1;
		return (ft_strndup((*s - 1), 1));
	}
	if (**s == '\'')
		return (parse_squote(s));
	if (**s == '"')
		return (parse_dquote(s, env));
	return (parse_neutral(s, env));
}

int	update_result(size_t count, char **result, char *new_string)
{
	char	*tmp_result;

	if (result[count])
	{
		tmp_result = ft_strjoin(result[count], new_string);
		free(result[count]);
		if (!tmp_result)
		{
			free_n(result, count);
			return (-1);
		}
		result[count] = tmp_result;
		return (0);
	}
	result[count] = new_string;
	return (0);
}

int	fill_split(char *s, char **result, char **env)
{
	bool	escaped;
	size_t	count;
	char	*parse_result;

	if (!*s)
		result[0] = ft_strdup("");
	count = 0;
	escaped = *s == '\\';
	while (*s)
	{
		while (issep(*s))
			++s;
		parse_result = parse_split(&escaped, &s, env);
		if (!parse_result)
		{
			free_n(result, count);
			return (1);
		}
		update_result(count, result, parse_result);
		if (issep(*s))
			++count;
		escaped = !escaped && *s == '\\';
	}
	return (0);
}

int	exec_shell(char *cmd, char **env)
{
	const size_t	arg_count = count_args(cmd);
	char			*cmd_path;
	char			**splited_cmd;
	int				result;

	cmd = ft_strtrim(cmd, " \t");
	splited_cmd = ft_calloc((arg_count + 1), sizeof(char *));
	if (!splited_cmd || fill_split(cmd, splited_cmd, env) == 1)
		return (1);
	result = parse_command(splited_cmd[0], get_from_env("PATH", env),
			&cmd_path);
	if (result)
	{
		free_split(splited_cmd);
		return (result);
	}
	result = execve(cmd_path, splited_cmd, env);
	free_split(splited_cmd);
	free(cmd_path);
	return (result);
}
