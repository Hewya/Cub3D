/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabarnou <gabarnou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 14:05:05 by gabarnou          #+#    #+#             */
/*   Updated: 2024/07/04 15:05:56 by gabarnou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	parse_input(char *str)
{
	int	i;

	i = ft_strlen(str) - 4;
	return (ft_strncmp(str + i, ".cub", 4) != 0);
}

char	*translate_cub_file(int fd)
{
	char	*file_content;
	char	*line;
	char	*new_content;
	size_t	new_length;

	file_content = malloc(1);
	if (!file_content)
	{
		perror("malloc");
		close(fd);
		return (NULL);
	}
	file_content[0] = '\0';
	while ((line = get_next_line(fd)) != NULL)
	{
		new_length = ft_strlen(file_content) + ft_strlen(line) + 1;
		new_content = ft_realloc(file_content, new_length);
		if (!new_content)
		{
			perror("realloc");
			free(file_content);
			free(line);
			close(fd);
			return (NULL);
		}
		file_content = new_content;
		ft_strcat(file_content, line);
		free(line);
	}
	close(fd);
	printf("resultat: %s\n", file_content);
	return (file_content);
}
