/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabarnou <gabarnou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 01:35:13 by amoutill          #+#    #+#             */
/*   Updated: 2024/07/25 19:02:35 by amoutill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/game_data.h"
#include "../include/raycast.h"
#include <math.h>

int	get_texture_pixel_at(float x, float y, t_texture texture)
{
	int	*pixel;
	int	int_x;
	int	int_y;

	pixel = (int *)texture.texture;
	int_x = x * texture.width;
	if (int_x >= texture.width)
		int_x = texture.width - 1;
	int_y = y * texture.height;
	if (int_y >= texture.height)
		int_y = texture.height - 1;
	return (pixel[int_x + (int_y * texture.width)]);
}

int	get_column_wall_color(t_game_data game_data, t_wall ray, int col_y,
		int h_proj_slice)
{
	float	ballec;
	float	y;

	y = (float)col_y / h_proj_slice;
	if (ray.walldirection == 'N')
		return (get_texture_pixel_at(modff(ray.intercept.x, &ballec), y,
				game_data.textures.north));
	else if (ray.walldirection == 'S')
		return (get_texture_pixel_at(modff(ray.intercept.x, &ballec), y,
				game_data.textures.south));
	else if (ray.walldirection == 'E')
		return (get_texture_pixel_at(modff(ray.intercept.y, &ballec), y,
				game_data.textures.east));
	else if (ray.walldirection == 'W')
		return (get_texture_pixel_at(modff(ray.intercept.y, &ballec), y,
				game_data.textures.west));
	else
		return (0xFFFFFFFF);
	(void)ballec;
}

void	draw_column(t_game_data game_data, int col, t_wall ray)
{
	int const	d_proj_wall = WINDOW_WIDTH / (2 * tanf(FOV_RAD / 2));
	int const	h_proj_slice = d_proj_wall / ray.ray_len;
	int const	begin = WINDOW_HEIGHT / 2 - h_proj_slice / 2;
	int const	end = begin + h_proj_slice;
	int			i;

	i = begin;
	if (i < 0)
		i = 0;
	while (i <= end && i < WINDOW_HEIGHT)
	{
		set_image_pixel_color(game_data.mlx_image,
			get_column_wall_color(game_data, ray, i - begin, h_proj_slice), col,
			i);
		++i;
	}
}
