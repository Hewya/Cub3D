/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cub_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabarnou <gabarnou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 18:50:55 by amoutill          #+#    #+#             */
/*   Updated: 2024/07/18 20:45:06 by gabarnou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_map.h"

void	ft_free(void *p)
{
	if (p)
		free(p);
}

void	free_cub_map(t_cub_map *cub_map)
{
	ft_free(cub_map->no_text_path);
	ft_free(cub_map->so_text_path);
	ft_free(cub_map->we_text_path);
	ft_free(cub_map->ea_text_path);
	ft_free_split(cub_map->map);
}

int	parse_cub_map(t_cub_map *cub_map, int fd)
{
	char	*buf;

	ft_bzero(cub_map, sizeof(t_cub_map));
	cub_map->floor_color.r = -2;
	cub_map->ceil_color.r = -2;
	while (!is_settings_complete(cub_map))
	{
		buf = get_next_useful_line(fd);
		if (!buf)
			return (-1);
		if (set_setting(cub_map, buf))
		{
			free(buf);
			return (-1);
		}
		free(buf);
	}
	if (set_map(cub_map, fd))
		return (-1);
	return (0);
}

int	is_ok_path(char *cub_map_path)
{
	return (ft_strlen(cub_map_path) > 4
		&& ft_strcmp(&(cub_map_path[ft_strlen(cub_map_path) - 4]),
			".cub") == 0);
}
