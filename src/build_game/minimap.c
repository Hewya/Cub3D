/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabarnou <gabarnou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 18:14:14 by gabarnou          #+#    #+#             */
/*   Updated: 2024/07/17 20:12:45 by gabarnou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_data.h"
#include "player.h"
#include "raycast.h"

void	draw_square(t_game_data *data, int x, int y, int colour)
{
	int	y_buf;
	int	x_buf;

	y_buf = y;
	x_buf = x;
	while (x < (data->map_data.scale_width + x_buf))
	{
		y = y_buf;
		while (y < (data->map_data.scale_height + y_buf))
		{
			if (x > 0 && y > 0 && x < DEFAULT_WIN_W && y < DEFAULT_WIN_H)
				mlx_pixel_put(data->mlx_window, data->mlx_image, x, y, colour);
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
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == '1')
				draw_square(data, (j * data->map_data.scale_width) + 20,
					(i * data->map_data.scale_height) + 20, ft_pixel(0, 0, 0, 255));
			else if (data->map[i][j] == '0' || is_player_tile(data->map[i][j]))
				draw_square(data, (j * data->map_data.scale_width) + 20,
					(i * data->map_data.scale_height) + 20,
					ft_pixel(255, 255, 255, 100));
			j++;
		}
		i++;
	}
	draw_square(data,
		(((data->player.coord.x - BLOCK_RES / 2) / BLOCK_RES)
		* data->map_data.scale_width) + 20,
		(((data->player.coord.y - BLOCK_RES / 2) / BLOCK_RES)
		* data->map_data.scale_height) + 20,
		ft_pixel(255, 0, 0, 255));
}
