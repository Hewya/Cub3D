/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabarnou <gabarnou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 18:21:11 by gabarnou          #+#    #+#             */
/*   Updated: 2024/07/19 17:34:46 by gabarnou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycast.h"

uint32_t	pixel(int32_t r, int32_t g, int32_t b, int32_t a)
{
	return ((r << 24) | (g << 16) | (b << 8) | a);
}

int	length_map(t_map *map)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	len = 0;
	while (map->map.map[i])
	{
		j = 0;
		while (map->map.map[i][j])
		{
			if (j > len)
				len++;
			j++;
		}
		i++;
	}
	return (len);
}
int	ft_tablen(char **tab)
{
	size_t	i;

	i = 0;
	if (tab)
		while (tab[i])
			i++;
	return (i);
}

void	init_img(t_map *map)
{
	double	max_dimension;

	map->map_length = length_map(map);
	map->map_height = ft_tablen(map->map.map);
	if (map->map_length >= map->map_height)
		max_dimension = map->map_length;
	else
		max_dimension = map->map_height;
	map->scale_width = DEFAULT_WIN_W / (max_dimension * (DEFAULT_WIN_W / 125));
	map->scale_height = DEFAULT_WIN_H / (max_dimension * (DEFAULT_WIN_H / 125));
}

void	put_pixel_to_background(t_game_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (x < DEFAULT_WIN_W)
	{
		y = 0;
		while (y < DEFAULT_WIN_H)
		{
			if (y < DEFAULT_WIN_H / 2)
				mlx_pixel_put(data->mlx_connection ,data->mlx_image,
					x, y, data->textures.ceil);
			else
				mlx_pixel_put(data->mlx_connection ,data->mlx_image,
					x, y, data->textures.floor);
			y++;
		}
		x++;
	}
}
