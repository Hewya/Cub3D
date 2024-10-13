/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabarnou <gabarnou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 01:41:58 by amoutill          #+#    #+#             */
/*   Updated: 2024/07/25 21:22:38 by gabarnou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_TEXTURES_H
# define INIT_TEXTURES_H

# include "cub_map.h"
# include "game_data.h"

void	free_textures(t_game_data *game_data);
int		init_textures(t_textures *textures, void *mlx_connection,
			t_cub_map *cub_map);

#endif
