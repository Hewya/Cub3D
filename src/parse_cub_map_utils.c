/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cub_map_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoutill <amoutill@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 18:05:18 by amoutill          #+#    #+#             */
/*   Updated: 2024/07/25 22:15:57 by amoutill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub_map.h"

t_setting_type	get_setting_type(const char *line)
{
	if (!ft_strncmp(line, "NO ", 3))
		return (NO);
	else if (!ft_strncmp(line, "SO ", 3))
		return (SO);
	else if (!ft_strncmp(line, "WE ", 3))
		return (WE);
	else if (!ft_strncmp(line, "EA ", 3))
		return (EA);
	else if (!ft_strncmp(line, "F ", 2))
		return (F);
	else if (!ft_strncmp(line, "C ", 2))
		return (C);
	return (ERR);
}

char	*get_text_path(const char *line)
{
	line += TEXT_PATH_PREFIX_LEN;
	while (*line == ' ')
		++line;
	return (ft_strdup(line));
}

int	str_to_color(const char *str)
{
	int	i;

	i = 0;
	if (ft_strlen(str) > 3)
		return (-1);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (-1);
		++i;
	}
	i = ft_atoi(str);
	if (i < 0 || i > 255)
		return (-1);
	return (i);
}

t_rgb	get_color(const char *line)
{
	char	**color_split;
	t_rgb	color;

	line += COLOR_PREFIX_LEN;
	while (*line == ' ')
		++line;
	color_split = ft_split(line, ',');
	if (!color_split)
	{
		color.r = -1;
		return (color);
	}
	if (line[ft_strlen(line) - 1] == ',' || ft_splitlen(color_split) != 3)
	{
		ft_free_split(color_split);
		color.r = -1;
		return (color);
	}
	color.r = str_to_color(color_split[0]);
	color.g = str_to_color(color_split[1]);
	color.b = str_to_color(color_split[2]);
	ft_free_split(color_split);
	return (color);
}

int	set_setting(t_cub_map *map, const char *line)
{
	const t_setting_type	setting_type = get_setting_type(line);

	if (setting_type == NO && !map->no_text_path)
		map->no_text_path = get_text_path(line);
	else if (setting_type == SO && !map->so_text_path)
		map->so_text_path = get_text_path(line);
	else if (setting_type == WE && !map->we_text_path)
		map->we_text_path = get_text_path(line);
	else if (setting_type == EA && !map->ea_text_path)
		map->ea_text_path = get_text_path(line);
	else if (setting_type == F && map->floor_color.r == -2)
		map->floor_color = get_color(line);
	else if (setting_type == C && map->ceil_color.r == -2)
		map->ceil_color = get_color(line);
	else
		return (-1);
	return (0);
}
