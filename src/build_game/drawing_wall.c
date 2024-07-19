/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_wall.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabarnou <gabarnou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 19:19:18 by gabarnou          #+#    #+#             */
/*   Updated: 2024/07/19 17:20:04 by gabarnou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycast.h"

uint32_t	get_texture_color(t_texture texture, int tex_x, int tex_y)
{
	uint8_t		*pixel;

	if (tex_x >= (int)texture.width)
		tex_x = (int)texture.width - 1;
	if (tex_y >= (int)texture.height)
		tex_y = (int)texture.height - 1;
	if (tex_x < 0 || tex_y < 0)
		return (0xFF000000);
	pixel = texture.pixels
		+ (tex_y * texture.width + (texture.width - 1 - tex_x))
		* texture.bits_per_pixel;
	return ((pixel[0] << 24) | (pixel[1] << 16) | (pixel[2] << 8)
		| pixel[3]);
}
t_texture	get_texture_side(t_game_data *data, t_wall wall)
{
	t_texture	texture_wall;

	if (wall.walldirection == 'N')
		texture_wall = data->textures.north;
	if (wall.walldirection == 'S')
		texture_wall = data->textures.south;
	if (wall.walldirection == 'W')
		texture_wall = data->textures.west;
	if (wall.walldirection == 'E')
		texture_wall = data->textures.east;
	return (texture_wall);
}

static void	draw_wall_2(t_wall wall, t_pos *pos_tex, t_texture texture)
{
	if (wall.walldirection == 'N')
		pos_tex->x = ((int)wall.intercept.x % BLOCK_RES);
	else if (wall.walldirection == 'S')
		pos_tex->x = (BLOCK_RES - ((int)wall.intercept.x % BLOCK_RES));
	else if (wall.walldirection == 'E')
		pos_tex->x = ((int)wall.intercept.y % BLOCK_RES);
	else if (wall.walldirection == 'W')
		pos_tex->x = (BLOCK_RES - ((int)wall.intercept.y % BLOCK_RES));
	pos_tex->x = (pos_tex->x * texture.width) / BLOCK_RES;
}

void	draw_wall(t_game_data *data, t_wall wall, int i)
{
	float		proj_height;
	int			start;
	t_pos		pos_tex;
	float		scale;
	t_texture	texture;

	proj_height = (((DEFAULT_WIN_W / 2) / tan(FOV_RAD / 2)) * BLOCK_RES)
		/ wall.ray_len;
	start = (DEFAULT_WIN_H / 2) - (proj_height / 2);
	if (start < 0)
		start = 0;
	texture = get_texture_side(data, wall);
	pos_tex.y = 0;
	if (proj_height >= DEFAULT_WIN_H)
		pos_tex.y = ((proj_height - DEFAULT_WIN_H) / 2)
			* (texture.height / proj_height);
	draw_wall_2(wall, &pos_tex, texture);
	scale = texture.height / proj_height;
	while (proj_height-- > 0 && start < DEFAULT_WIN_H)
	{
		mlx_pixel_put(data->mlx_window, data->mlx_image, i, start++,
			get_texture_color(texture, pos_tex.x, pos_tex.y));
		pos_tex.y += scale;
	}
}
