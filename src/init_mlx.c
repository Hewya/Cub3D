/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabarnou <gabarnou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 01:23:16 by amoutill          #+#    #+#             */
/*   Updated: 2024/07/25 20:33:59 by amoutill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/game_data.h"
#include "../include/init_mlx.h"
#include "../lib/minilibx/mlx.h"

int	init_mlx(t_game_data *game_data)
{
	game_data->mlx_connection = mlx_init();
	if (!game_data->mlx_connection)
		return (-1);
	game_data->mlx_window = mlx_new_window(game_data->mlx_connection,
			WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE);
	if (!game_data->mlx_window)
		return (-1);
	game_data->mlx_image.image = mlx_new_image(game_data->mlx_connection,
			WINDOW_WIDTH, WINDOW_HEIGHT);
	if (!game_data->mlx_image.image)
		return (-1);
	game_data->mlx_image.texture = mlx_get_data_addr(game_data->mlx_image.image,
			&(game_data->mlx_image.bits_per_pixel),
			&(game_data->mlx_image.size_line), &(game_data->mlx_image.endian));
	game_data->mlx_image.width = WINDOW_WIDTH;
	game_data->mlx_image.height = WINDOW_HEIGHT;
	return (0);
}
