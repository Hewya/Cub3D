/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabarnou <gabarnou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 17:02:30 by gabarnou          #+#    #+#             */
/*   Updated: 2024/07/25 17:54:26 by gabarnou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCAST_H
# define RAYCAST_H

# include "cub_map.h"
# include "game_data.h"
# include "init_mlx.h"
# include "player.h"
# include <limits.h>
# include <math.h>
# include <stdbool.h>
# include <stdint.h>

# define FOV_RAD 1.0472
# define MOVESPEED 0.1f
# define ROTATIONSPEED 0.1f

typedef struct s_pos
{
	float	x;
	float	y;
}			t_pos;

typedef struct s_wall
{
	char	walldirection;
	double	ray_len;
	t_pos	intercept;
}			t_wall;

// DRAWING_WALL //
uint32_t	get_texture_color(t_texture texture, int tex_x, int tex_y);
void		draw_wall(t_game_data *data, t_wall wall, int i);

// FINDING_WALL //
void		find_first_hor(t_game_data *data, double angle, t_pos *hor_int,
				t_wall *hor_wall);
t_wall		find_hor_intercept(t_game_data *data, double angle);
void		find_first_vert(t_game_data *data, double angle, t_pos *vert_int,
				t_wall *vert_wall);
t_wall		find_vert_intercept(t_game_data *data, const double angle);

// MINIMAP //
void		draw_square(t_game_data *data, int x, int y, int colour);
void		draw_minimap(t_game_data *data);

// TEXTURE //
uint32_t	pixel(int32_t r, int32_t g, int32_t b, int32_t a);
int			length_map(t_map *map);
int			ft_tablen(char **tab);
void		init_img(t_map *map);
void		put_pixel_to_background(t_game_data *data);

// RAY_STUFF //
double		norm_angle(double angle);
bool		is_off_map(t_game_data *data, t_pos intercept);
bool		is_wall(t_game_data *data, t_pos intercept);
t_wall		ray_len(t_game_data *data, double ray_angle);
void		raycast(t_game_data *data);

// MOVES //
void		move(t_game_data *data, double angle);
void		rotate(t_game_data *data, int dir);
int			key_hook(int keycode, void *param);
void		check_and_move(t_game_data *data, t_pos check_wall);

void		draw_column(t_game_data game_data, int col, t_wall ray);

#endif
