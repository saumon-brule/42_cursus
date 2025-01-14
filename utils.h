/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 02:01:37 by ebini             #+#    #+#             */
/*   Updated: 2025/01/14 02:35:35 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H


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
char	*parse_command(char *cmd, char *path);

#endif