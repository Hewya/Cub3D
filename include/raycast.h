/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabarnou <gabarnou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 17:02:30 by gabarnou          #+#    #+#             */
/*   Updated: 2024/07/17 19:58:49 by gabarnou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCAST_H
# define RAYCAST_H

# include "player.h"
# include "game_data.h"
# include "init_mlx.h"
# include "cub_map.h"
# include "../minilibx-linux/mlx_int.h"

# include <limits.h>
# include <math.h>
# include <stdbool.h>
# include <stdint.h>

# define BLOCK_RES 1000 // in unit
# define PLAYER_SPEED 0.02f
# define DEFAULT_WIN_H 240
# define DEFAULT_WIN_W 320
# define FOV_RAD 1.0472 // 60 deg in radian
# define MOVESPEED 20.0f
# define ROTATIONSPEED 0.1f

typedef struct s_pos
{
	float			x;
	float			y;
}					t_pos;

typedef struct s_wall
{
	char			walldirection; // NSEW to select correct wall texture
	double			ray_len; // closest hor/vert wall intercept length
	t_pos			intercept; // intercept coordinates for texture mapping
}					t_wall;

#endif
