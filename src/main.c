/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabarnou <gabarnou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 22:03:07 by amoutill          #+#    #+#             */
/*   Updated: 2024/07/18 20:13:50 by gabarnou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include "../lib/libft/libft.h"
#include "../include/game_data.h"
#include "../include/raycast.h"
#include "../include/ft_perror.h"

void	print_game_data(t_game_data game_data)
{
	size_t	i;

	i = 0;
	while (game_data.map[i])
		printf("%s\n", game_data.map[i++]);
	printf("player: x: %f, y: %f, a: %f", game_data.player.coord.x,
			game_data.player.coord.y, game_data.player.coord.a);
}

void	free_game_data(t_game_data *game_data)
{
	ft_free_split(game_data->map);
}

int	main(int argc, char *argv[])
{
	t_game_data	game_data;

	if (argc != 2)
		ft_perror("Usage : ./cub3d maps/<maps_file>.cub");
	else
	init_game_data(&game_data, argv[1]);
	//print_game_data(game_data);
	init_img(&game_data.map_data);
	put_pixel_to_background(&game_data);
	raycast(&game_data);
	mlx_key_hook(game_data.mlx_connection, key_hook, &game_data);
	mlx_loop(game_data.mlx_connection);
	free_game_data(&game_data);
}
