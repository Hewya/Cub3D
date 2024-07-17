/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_data.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabarnou <gabarnou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 19:30:57 by amoutill          #+#    #+#             */
/*   Updated: 2024/07/17 20:18:15 by gabarnou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_DATA_H
# define GAME_DATA_H

# include "player.h"
# include "textures.h"
# include "cub_map.h"

typedef struct s_game_data
{
	t_player	player;
	t_textures	textures;
	t_map		map_data;
	char		**map;
	void		*mlx_connection;
	void		*mlx_window;
	void		*mlx_image;

}				t_game_data;

int	init_game_data(t_game_data *game_data, char *cub_map_path);

#endif
