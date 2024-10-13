/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_data.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoutill <amoutill@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 19:30:57 by amoutill          #+#    #+#             */
/*   Updated: 2024/07/25 20:49:47 by amoutill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_DATA_H
# define GAME_DATA_H

# include "map.h"
# include "player.h"
# include "textures.h"

typedef struct s_game_data
{
	t_player	player;
	t_textures	textures;
	t_map		map;
	void		*mlx_connection;
	void		*mlx_window;
	t_texture	mlx_image;
}				t_game_data;

int		init_game_data(t_game_data *game_data, char *cub_map_path);
void	free_game_data(t_game_data *game_data);

#endif
