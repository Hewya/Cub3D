/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabarnou <gabarnou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 18:14:14 by gabarnou          #+#    #+#             */
/*   Updated: 2024/07/25 17:33:34 by gabarnou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/game_data.h"
#include "../include/player.h"
#include "../include/raycast.h"

void	draw_square(t_game_data *data, int x, int y, int colour)
{
	int	y_buf;
	int	x_buf;

	y_buf = y;
	x_buf = x;
	while (x < (data->map.scale_width + x_buf))
	{
		y = y_buf;
		while (y < (data->map.scale_height + y_buf))
		{
			if (x > 0 && y > 0 && x < WINDOW_WIDTH && y < WINDOW_HEIGHT)
				set_image_pixel_color(data->mlx_image, colour, x, y);
			y++;
		}
		x++;
	}
}

void	draw_minimap(t_game_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (data->map.map[i])
	{
		j = 0;
		while (data->map.map[i][j])
		{
			if (data->map.map[i][j] == '1')
				draw_square(data, (j * data->map.scale_width) + 20, (i
						* data->map.scale_height) + 20, pixel(0, 0, 0, 255));
			else if (data->map.map[i][j] == '0')
				draw_square(data, (j * data->map.scale_width) + 20, (i
						* data->map.scale_height) + 20, pixel(255, 255, 255,
						100));
			j++;
		}
		i++;
	}
	draw_square(data, (((data->player.coord.x - 1.0 / 2))
			* data->map.scale_width) + 20, (((data->player.coord.y - 1.0 / 2))
			* data->map.scale_height) + 20, pixel(255, 0, 0, 255));
}
