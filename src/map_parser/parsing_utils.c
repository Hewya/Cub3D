/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoutill <amoutill@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 22:36:19 by amoutill          #+#    #+#             */
/*   Updated: 2024/07/10 23:40:00 by amoutill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/libft/libft.h"

char	*get_next_useful_line(const int fd)
{
	char	*buf;

	buf = get_next_line(fd);
	while (buf && buf[0] == '\n')
	{
		free(buf);
		buf = get_next_line(fd);
	}
	if (buf)
		buf[ft_strlen(buf) - 1] = '\0';
	return (buf);
}
