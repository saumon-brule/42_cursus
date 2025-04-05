/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_errors.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 02:25:27 by ebini             #+#    #+#             */
/*   Updated: 2025/04/05 18:07:37 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

char	*get_map_errors(int map_error_num)
{
	static char	*errors[] = {
		"",
		"The map file is empty",
		"Map format is invalid",
		"Unexpected character in map file",
		"The map isn't closed",
		"The map has no start",
		"The map has no exit",
		"The map contain too much start",
		"The map contain too much exit",
		"The map doesn't contain any collectible",
		"One or more collectibles are unreachable in the map",
		"The exit is unreachable",
		"The map is too big",
	};

	return (errors[map_error_num]);
}
