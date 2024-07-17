/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoutill <amoutill@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 22:03:07 by amoutill          #+#    #+#             */
/*   Updated: 2024/07/15 05:03:19 by amoutill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include "../lib/libft/libft.h"
#include "../include/game_data.h"

void	print_game_data(t_game_data game_data)
{
	size_t	i;

	i = 0;
	while (game_data.map[i])
		printf("%s\n", game_data.map[i++]);
	printf("player: x: %f, y: %f, a: %f", game_data.player.coord.x, game_data.player.coord.y, game_data.player.coord.a);
}

void	free_game_data(t_game_data *game_data)
{
	ft_free_split(game_data->map);
}

int	main(int argc, char *argv[])
{
	t_game_data	game_data;

	if (argc < 2)
		init_game_data(&game_data, "test.cub");
	else
		init_game_data(&game_data, argv[1]);
	print_game_data(game_data);
//	mlx_loop(game_data.mlx_connection);
	free_game_data(&game_data);
}
