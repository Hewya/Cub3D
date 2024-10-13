/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabarnou <gabarnou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 00:52:21 by amoutill          #+#    #+#             */
/*   Updated: 2024/07/25 21:24:04 by gabarnou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/game_data.h"
#include "../include/cub_map.h"
#include "../lib/minilibx/mlx.h"

int	rgb_to_int(t_rgb	rgb)
{
	return ((rgb.r << 16) + (rgb.g << 8) + rgb.b);
}

void	free_textures(t_game_data *game_data)
{
	if (game_data->textures.north.image)
		mlx_destroy_image(game_data->mlx_connection,
			game_data->textures.north.image);
	if (game_data->textures.south.image)
		mlx_destroy_image(game_data->mlx_connection,
			game_data->textures.south.image);
	if (game_data->textures.east.image)
		mlx_destroy_image(game_data->mlx_connection,
			game_data->textures.east.image);
	if (game_data->textures.west.image)
		mlx_destroy_image(game_data->mlx_connection,
			game_data->textures.west.image);
}

void	init_texture(t_texture *texture, void *mlx_connection, char *text_path)
{
	texture->image = mlx_xpm_file_to_image(mlx_connection, text_path,
			&texture->width, &texture->height);
	if (!texture->image)
		return ;
	texture->texture = mlx_get_data_addr(texture->image,
			&(texture->bits_per_pixel), &(texture->size_line),
			&(texture->endian));
	if (!texture->texture)
	{
		mlx_destroy_image(mlx_connection, texture->image);
		texture->image = NULL;
	}
}

int	init_textures(t_textures *textures, void *mlx_connection,
	t_cub_map *cub_map)
{
	textures->floor = mlx_get_color_value(mlx_connection,
			rgb_to_int(cub_map->floor_color));
	textures->ceil = mlx_get_color_value(mlx_connection,
			rgb_to_int(cub_map->ceil_color));
	init_texture(&(textures->north), mlx_connection, cub_map->no_text_path);
	init_texture(&(textures->south), mlx_connection, cub_map->so_text_path);
	init_texture(&(textures->east), mlx_connection, cub_map->ea_text_path);
	init_texture(&(textures->west), mlx_connection, cub_map->we_text_path);
	if (!textures->north.image || !textures->south.image
		|| !textures->east.image || !textures->west.image)
		return (-1);
	return (0);
}
