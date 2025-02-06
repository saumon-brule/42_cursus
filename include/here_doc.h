/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 10:44:29 by ebini             #+#    #+#             */
/*   Updated: 2025/02/06 19:12:34 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef HERE_DOC_H
# define HERE_DOC_H

/**
 * @brief Generate a temporary file and write the STDIN in it.
 * @param limiter The limiter indicating EOF
 * @param path The path that will be set to unsync the temporary file
 * @warning The memory newly pointed by *path should be released using free().
 * @return A file path containing the writed stdin.
 */
char	*tmp_here_doc(char *limiter);

/**
 * @brief Open a temporary file with flag permission and returns its fd.
 * @param path The path that will be set to unsync the temporary file
 * @param flags The the flags used to open the new file with open() (from
 * fcntl.h)
 * @warning The memory newly pointed by *path should be released using free().
 * @return A new fd pointing to a new file in r/w right access.
 */
int		tmp_fd(char **path, int flags);

#endif
