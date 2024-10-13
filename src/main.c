/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabarnou <gabarnou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 22:03:07 by amoutill          #+#    #+#             */
/*   Updated: 2024/07/25 21:42:42 by amoutill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_perror.h"
#include "../include/game_data.h"
#include "../include/raycast.h"
#include "../lib/libft/libft.h"
#include <X11/X.h>
#include <fcntl.h>
#include <stdio.h>

int	exit_hook(t_game_data *game_data)
{
	free_game_data(game_data);
	exit(0);
}

int	main(int argc, char *argv[])
{
	t_game_data	game_data;

	if (argc != 2)
	{
		ft_perror("Usage : ./cub3d maps/<maps_file>.cub");
		return (1);
	}
	else
	{
		if (init_game_data(&game_data, argv[1]))
		{
			free_game_data(&game_data);
			return (2);
		}
	}
	put_pixel_to_background(&game_data);
	raycast(&game_data);
	mlx_key_hook(game_data.mlx_window, key_hook, &game_data);
	mlx_hook(game_data.mlx_window, DestroyNotify, NoEventMask, exit_hook,
		&game_data);
	mlx_loop(game_data.mlx_connection);
	free_game_data(&game_data);
}
