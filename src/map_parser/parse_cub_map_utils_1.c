/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cub_map_utils_1.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoutill <amoutill@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 18:45:14 by amoutill          #+#    #+#             */
/*   Updated: 2024/07/15 00:48:58 by amoutill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub_map.h"

int	is_settings_complete(const t_cub_map *cub_map)
{
	return (cub_map->no_text_path && cub_map->so_text_path
		&& cub_map->we_text_path && cub_map->ea_text_path
		&& cub_map->floor_color.r >= 0 && cub_map->floor_color.g >= 0
		&& cub_map->floor_color.b >= 0 && cub_map->ceil_color.r >= 0
		&& cub_map->ceil_color.g >= 0 && cub_map->ceil_color.b >= 0);
}

size_t	ft_splitlen(char **split)
{
	size_t	len;

	len = 0;
	while (*(split++))
		++len;
	return (len);
}

int	ft_striswhitespaces(char *s)
{
	while (*s)
	{
		if (!ft_isspace(*s))
			return (0);
		++s;
	}
	return (1);
}

int	ft_split_add_str(char ***split, char *str)
{
	char	**tmp;
	int		i;

	i = 0;
	if (*split)
	{
		tmp = *split;
		*split = malloc(sizeof(char **) * (ft_splitlen(*split) + 2));
		if (!*split)
		{
			ft_free_split(tmp);
			return (-1);
		}
		while (tmp[i])
		{
			(*split)[i] = tmp[i];
			++i;
		}
		free(tmp);
	}
	else
		*split = malloc(sizeof(char **) * 2);
	(*split)[i++] = str;
	(*split)[i] = NULL;
	return (0);
}

int	set_map(t_cub_map *cub_map, int fd)
{
	char	*buf;

	while (42)
	{
		if (!cub_map->map)
			buf = get_next_useful_line(fd);
		else
			buf = get_next_line(fd);
		if (!buf)
			return (0);
		if (buf[0] == '\n' || ft_striswhitespaces(buf))
		{
			free(buf);
			return (-1);
		}
		if (ft_split_add_str(&cub_map->map, buf))
		{
			free (buf);
			return (-1);
		}
		if (buf[ft_strlen(buf) - 1] == '\n')
			buf[ft_strlen(buf) - 1] = '\0';
	}
}
