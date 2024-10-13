/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabarnou <gabarnou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 18:21:11 by gabarnou          #+#    #+#             */
/*   Updated: 2024/07/25 17:40:59 by gabarnou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/raycast.h"

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
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
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

void	set_image_pixel_color(t_texture image, int color, size_t x, size_t y)
{
	int	*pixel;

	pixel = (int *)image.texture;
	pixel[x + (y * image.width)] = color;
}

void	put_pixel_to_background(t_game_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < WINDOW_HEIGHT)
	{
		x = 0;
		while (x < WINDOW_WIDTH)
		{
			if (y < WINDOW_HEIGHT / 2)
				set_image_pixel_color(data->mlx_image, data->textures.ceil, x,
					y);
			else
				set_image_pixel_color(data->mlx_image, data->textures.floor, x,
					y);
			x++;
		}
		y++;
	}
}
