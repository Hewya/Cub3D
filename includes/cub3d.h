/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabarnou <gabarnou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 13:55:40 by gabarnou          #+#    #+#             */
/*   Updated: 2024/07/15 01:35:38 by gabarnou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include "../minilibx-linux/mlx_int.h"
# include <fcntl.h>
# include <limits.h>
# include <math.h>
# include <stdbool.h>
# include <stddef.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define SUCCESS 0
# define FAILURE 1
# define BLOCK_RES 1000 // in unit
# define PLAYER_SPEED 0.02f
# define DEFAULT_WIN_H 240
# define DEFAULT_WIN_W 320
//# define M_PI			3.14159265358979323846

// mettre les angles en double

typedef struct s_pos
{
	float			x;
	float			y;
}					t_pos;

typedef struct s_3RGB
{
	uint8_t			r;
	uint8_t			g;
	uint8_t			b;
}					t_3RGB;

typedef struct s_texture_path
{
	char			*north_texture;
	char			*south_texture;
	char			*west_texture;
	char			*east_texture;
	mlx_texture_t	*no_wall_texture;	// structure a changer
	mlx_texture_t	*so_wall_texture;
	mlx_texture_t	*we_wall_texture;
	mlx_texture_t	*ea_wall_texture;
}					t_texture_path;

typedef struct s_map
{
	char			**map;
	int				fd;
	char			*map_path;
	char			player_start;
	t_pos			map_size;
	t_pos			start_pos;
}					t_map;

typedef struct s_wall
{
	char			walldirection; // NSEW to select correct wall texture
	double			raylength; // closest hor/vert wall intercept length
	t_pos			intercept; // intercept coordinates for texture mapping
}					t_wall;

typedef struct s_data
{
	void			*mlx;
	mlx_image_t		*img; // structure a changer
	t_map			map;
	t_texture_path	texture_path;
	t_pos			player_pos;
	float			player_dir;
	t_3RGB			floor;
	t_3RGB			ceiling;
}					t_data;

// typedef struct s_cub_map
// {
// 	char	*no_text_path;
// 	char	*so_text_path;
// 	char	*we_text_path;
// 	char	*ea_text_path;
// 	int		floor_color[3];
// 	int		ceil_color[3];
// 	char	**map;
// }			t_cub_map;

// ERROR
int					usage(void);
int					error(char *str);

// FINDING_WALLS
void				find_first_hor(t_data *data, double angle, t_pos *hor_int,
						t_wall *hor_wall);
t_wall				find_hor_intercept(t_data *data, double angle);
void				find_first_vert(t_data *data, double angle, t_pos *vert_int,
						t_wall *vert_wall);
t_wall				find_vert_intercept(t_data *data, const double angle);

// MOVE
int					move_forward(t_data *data);
int					move_backward(t_data *data);
int					move_left(t_data *data);
int					move_right(t_data *data);

// RAY_STUFF
double				norm_angle(double angle);
bool				is_off_map(t_data *data, t_pos intercept);
bool				is_wall(t_data *data, t_pos intercept);
t_wall				ray_len(t_data *data, double ray_angle);
void				raycast(t_data *data);

// UTILS
double				deg_to_rad(double deg);

#endif