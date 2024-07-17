/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabarnou <gabarnou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 01:23:16 by amoutill          #+#    #+#             */
/*   Updated: 2024/07/16 19:10:35 by gabarnou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/game_data.h"
#include "../minilibx/mlx.h"
#include "../include/init_mlx.h"

int	init_mlx(t_game_data *game_data)
{
	game_data->mlx_connection = mlx_init();
	if (!game_data->mlx_connection)
		return (-1);
	game_data->mlx_window = mlx_new_window(game_data->mlx_connection,
			WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE);
	if (!game_data->mlx_window)
	{
		//TODO: Free mlx
		return (-1);
	}
	game_data->mlx_image = mlx_new_image(game_data->mlx_connection,
			WINDOW_WIDTH, WINDOW_HEIGHT);
	return (0);
}
