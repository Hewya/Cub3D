/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabarnou <gabarnou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 12:18:52 by gabarnou          #+#    #+#             */
/*   Updated: 2024/07/09 18:41:28 by gabarnou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buff[BUFFER_SIZE + 1];
	t_gnl		gnl;

	gnl.line = ft_strdup(buff);
	gnl.new_line = ft_strchr(gnl.line, '\n');
	gnl.read_counter = read(fd, buff, BUFFER_SIZE);
	while (!(gnl.new_line) && (gnl.read_counter))
	{
		buff[gnl.read_counter] = '\0';
		gnl.line = ft_strjoin_free(gnl.line, buff, 1);
	}
	if (ft_strlen(gnl.line) == 0)
		return (free(gnl.line), NULL);
	if (gnl.new_line != NULL)
	{
		gnl.to_copy = gnl.new_line - gnl.line + 1;
		ft_strcpy(buff, gnl.new_line + 1);
	}
	else
	{
		gnl.to_copy = ft_strlen(gnl.line);
		buff[0] = '\0';
	}
	return (gnl.line[gnl.to_copy] = '\0', gnl.line);
}
