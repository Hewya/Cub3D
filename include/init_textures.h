/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoutill <amoutill@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 01:41:58 by amoutill          #+#    #+#             */
/*   Updated: 2024/07/15 04:16:55 by amoutill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_TEXTURES_H
# define INIT_TEXTURES_H

# include "game_data.h"
# include "cub_map.h"

int	init_textures(t_textures *textures, void *mlx_connection,
		t_cub_map *cub_map);

#endif
