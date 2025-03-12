/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 02:01:37 by ebini             #+#    #+#             */
/*   Updated: 2025/03/05 19:35:10 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_UTILS_H
# define PIPEX_UTILS_H

# include "libft.h"

# define WESC 0b00100000
# define AESC 0b00010000
# define WDQ  0b00001000
# define ADQ  0b00000100
# define WSQ  0b00000010
# define ASQ  0b00000001

typedef struct s_pipex_fd
{
	int	in;
	int	out;
	int	next_out;
	int	last_out;
}			t_pipex_fd;

/**
 * @brief Will give you the path depending of the env variables given in
 * parameter.
 * @param env The env a list of string of format "KEY=value" (the same as the
 * shell env)
 * @return The value assigned to the key PATH or NULL if nothing is found.
 */
char	*get_from_env(char *var, char **env);

/**
 * @brief This function will give you the full path of a shell comand using its
 * name and the path from the env.
 * @param cmd A string containing a potential command
 * @param path The env path containing all directories of bin separated by ":"
 * @return A malloced string with the path to go to command.
 * @note If the command contains a "/" we consider that it's a relative path so
 * we don't parse it an returns a duplicated and malloced string identical to
 * cmd
 */
int		parse_command(char *cmd, char *path, char **result);

/**
 * @brief Count the number of arguments of a command.
 * @param s The command
 * @return The number of arguments in the command s.
 */
size_t	count_args(char *s);

/**
 * @brief Will change pipe fd position according to their values. The read
 * fd will be set to the next one, the new write fd will be closed and a new
 * pipe will be created to replace the write and next read fd.
 * @param fd_arr And array of fd. The first one is the read fd, the second
 * one is the write fd and the last one is the next read fd
 * @return 0 if everything is good. -1 if there was an error with pipe.
 */
int		swap_fd(t_pipex_fd *pipe_fd);

/**
 * @brief Uses dup2 to make fd new point on the same file as fd old and then
 * delete old.
 * @param old A deleted fd
 * @param new A fd redirected to old
 */
int		change_fd(int old, int new);

/**
 * @brief Tells if a character is a separator or not.
 * @param c The character
 * @return 1 if the character is a separator, 0 if it isn't.
 */
bool	issep(int c);
bool	isquote(int c);

/**
 * @brief Tells if a character is escapable character, a character used for
 * special syntaxe, the list in this programm are space, tab, single and double
 * quotes, dollars and backslash
 * @param c The character
 */
bool	isescapable(int c);

/**
 * @brief Tells if the character at position pos of s is escaped by '\' or not.
 * It will be if the number of '\' before the character is odd.
 * @param s The string containing the character
 * @param pos the epositon of the character
 */
bool	is_escaped(char *s, size_t pos);

/**
 * @brief Tells if the character is a separator of arguments in a unquotted
 * context (basically space or tab) or a quote (marking the beggining of a
 * quoted context).
 * @param c The character
 */
bool	is_neutral_end(int c);

/**
 * @brief Tells if a character is part of the authorised character for shell
 * variables.
 * @param c The character
 * @note Shell variables can be composed of alnum characters and underscores.
 */
bool	is_var_name(int c);

/**
 * @brief Will parse an argument starting by a single quote.
 * @param s This is a douple pointer to a string because the function will
 * offset the string while parsing it, the function will assume that the string
 * starts by a single quote
 * @note Difference in parsing between squote and dquote is that squote will not
 * handle any special character (except the squote for the end). The dquote will
 * need to parse variables and/or character escaping by '\'.
 */
char	*parse_squote(char **s);

/**
 * @brief Will parse an argument starting by a double quote.
 * @param s This is a douple pointer to a string because the function will
 * offset the string while parsing it, the function will assume that the string
 * starts by a double quote
 * @note Difference in parsing between squote and dquote is that squote will not
 * handle any special character (except the squote for the end). The dquote will
 * need to parse variables and/or character escaping by '\'.
 */
char	*parse_dquote(char **s, char **env);

/**
 * @brief Will parse an argument in a unquoted contexte and stop at first space
 * or tab.
 * @param s This is a douple pointer to a string because the function will
 * offset the string while parsing it.
 */
char	*parse_neutral(char **s, char **env);

size_t	var_name_len(char *s);

/**
 * @brief Give the length of the use of a variable in a command. ($PATH will
 * return 5 and ${PATH} will return 7)
 * @param s The start of the var usage. The function assumes that it starts by a
 * '$'
 */
size_t	var_len(char *s);

int		pipex_fork(t_pipex_fd *pipe_fd, int pc, char **pv, char **env);

/**
 * @brief This function will exec a raw command as if it was parsed by the shell
 * (in an easy way)
 * @param cmd The raw command
 * @param env The env of the parent process
 * @note This function should handle env variables, squote/dquote and '\'.
 */
int		exec_shell(char *cmd, char **env);

int		pipex(int pc, char **pv, char **env, bool here_doc);

#endif