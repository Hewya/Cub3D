/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game_data.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoutill <amoutill@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 03:25:55 by amoutill          #+#    #+#             */
/*   Updated: 2024/07/15 04:18:22 by amoutill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/game_data.h"
#include "../include/cub_map.h"
#include "../include/ft_perror.h"
#include "../include/init_mlx.h"
#include "../include/init_textures.h"
#include <fcntl.h>
#include <stdio.h>

int	init_game_data(t_game_data *game_data, char *cub_map_path)
{
	int			fd;
	t_cub_map	cub_map;

	if (!is_ok_path(cub_map_path))
		return (ft_perror("invalid map file extension"));
	fd = open(cub_map_path, O_RDONLY);
	if (fd < 0)
	{
		perror("Error\ncub3d: open");
		return (-1);
	}
	if (parse_cub_map(&cub_map, fd))
		return (ft_perror("invalid map file format"));
	game_data->map = sanitize_map(cub_map.map);
	if (!game_data->map)
	{
		free_cub_map(&cub_map);
		return (ft_perror("unenclosed or invalid map"));
	}
	game_data->player = init_player(cub_map.map);
	replace_player_tile(game_data->map);
	init_mlx(game_data);
	init_textures(&(game_data->textures), game_data->mlx_connection, &cub_map);
	free_cub_map(&cub_map);
	return (0);
}
