/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game_data.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabarnou <gabarnou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 03:25:55 by amoutill          #+#    #+#             */
/*   Updated: 2024/07/25 22:44:51 by amoutill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub_map.h"
#include "../include/ft_perror.h"
#include "../include/game_data.h"
#include "../include/init_mlx.h"
#include "../include/init_textures.h"
#include <fcntl.h>
#include <stdio.h>

static int	init_map(t_game_data *game_data, t_cub_map *cub_map)
{
	game_data->map.map = sanitize_map(cub_map->map);
	if (!game_data->map.map)
		return (-1);
	game_data->map.map_length = ft_strlen(game_data->map.map[0]);
	game_data->map.map_height = ft_splitlen(game_data->map.map);
	game_data->map.scale_width = WINDOW_WIDTH / (game_data->map.map_length
			* (WINDOW_WIDTH / 125));
	game_data->map.scale_height = WINDOW_HEIGHT / (game_data->map.map_height
			* (WINDOW_HEIGHT / 125));
	game_data->player = init_player(cub_map->map);
	replace_player_tile(game_data->map.map);
	return (0);
}

void	free_map(t_map *map)
{
	ft_free_split(map->map);
}

void	cleanup_mlx(t_game_data *game_data)
{
	if (game_data->mlx_image.image)
		mlx_destroy_image(game_data->mlx_connection,
			game_data->mlx_image.image);
	if (game_data->mlx_window)
		mlx_destroy_window(game_data->mlx_connection, game_data->mlx_window);
	if (game_data->mlx_connection)
	{
		mlx_destroy_display(game_data->mlx_connection);
		free(game_data->mlx_connection);
	}
}

void	free_game_data(t_game_data *game_data)
{
	free_textures(game_data);
	cleanup_mlx(game_data);
	free_map(&game_data->map);
}

int	init_game_data(t_game_data *game_data, char *cub_map_path)
{
	int			fd;
	t_cub_map	cub_map;

	ft_bzero(game_data, sizeof(t_game_data));
	if (!is_ok_path(cub_map_path))
		return (ft_perror("invalid map file extension"));
	fd = open(cub_map_path, O_RDONLY);
	if (fd < 0)
	{
		perror("Error\ncub3d: open");
		return (-1);
	}
	if (parse_cub_map(&cub_map, fd))
		return (free_cub_map(&cub_map), ft_perror("invalid map file format"));
	if (init_map(game_data, &cub_map))
		return (free_cub_map(&cub_map), ft_perror("unenclosed or invalid map"));
	if (init_mlx(game_data))
		return (free_cub_map(&cub_map), ft_perror("mlx initialization error"));
	if (init_textures(&(game_data->textures), game_data->mlx_connection,
			&cub_map))
		return (free_cub_map(&cub_map),
			ft_perror("texture not found or invalid"));
	free_cub_map(&cub_map);
	return (0);
}
