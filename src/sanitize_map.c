/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sanitize_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoutill <amoutill@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 22:26:17 by amoutill          #+#    #+#             */
/*   Updated: 2024/07/13 00:56:14 by amoutill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub_map.h"

static size_t	ft_max_strlen_split(char **split)
{
	size_t	maxlen;
	size_t	len;

	maxlen = 0;
	while (*split)
	{
		len = ft_strlen(*split);
		if (len > maxlen)
			maxlen = len;
		++split;
	}
	return (maxlen);
}

static char	*square_map_row(char const *old_row, size_t len)
{
	size_t	i;
	char	*row;

	row = malloc(sizeof(char) * (len + 1));
	if (!row)
		return (NULL);
	i = 0;
	while (old_row[i])
	{
		row[i] = old_row[i];
		++i;
	}
	while (i < len)
		row[i++] = ' ';
	row[i] = '\0';
	return (row);
}

char	**square_map(char **map)
{
	size_t const	cols = ft_max_strlen_split(map);
	size_t const	rows = ft_splitlen(map);
	char **const	square_map = malloc(sizeof(char *) * (rows + 1));
	size_t			i;

	if (!map || !square_map)
		return (NULL);
	i = 0;
	while (i < rows)
	{
		square_map[i] = square_map_row(map[i], cols);
		if (!square_map[i])
		{
			ft_free_split(square_map);
			return (NULL);
		}
		++i;
	}
	square_map[i] = NULL;
	return (square_map);
}

static void	replace_spaces(char **map)
{
	size_t	i;
	size_t	j;

	if (!map)
		return ;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == ' ')
				map[i][j] = '1';
			++j;
		}
		++i;
	}
}

char	**sanitize_map(char **map)
{
	char	**squared_map;

	if (!is_valid_map(map))
		return (NULL);
	squared_map = square_map(map);
	if (!squared_map)
		return (NULL);
	if (!is_enclosed(squared_map))
	{
		ft_free_split(squared_map);
		return (NULL);
	}
	replace_spaces(squared_map);
	return (squared_map);
}
