/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabarnou <gabarnou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 13:55:40 by gabarnou          #+#    #+#             */
/*   Updated: 2024/07/04 16:18:20 by gabarnou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include ".././libft/libft.h"
# include <fcntl.h>
# include <math.h>
# include <stddef.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define SUCCESS 0
# define FAILURE 1

// mettre les angles en double

typedef struct s_2float
{
	float			x;
	float			y;
}					t_2float;

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
}					t_texture_path;

typedef struct s_map
{
	char			**map;
	int				fd;
	char			*map_path;
	char			player_start;
	t_2float		map_size;
	t_2float		start_pos;
}					t_map;

typedef struct s_data
{
	t_map			map;
	t_texture_path	texture_path;
	t_2float		player_pos;
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


int					parse_input(char *str);
char				*translate_cub_file(int fd);
int					usage(void);
int					error(char *str);

#endif