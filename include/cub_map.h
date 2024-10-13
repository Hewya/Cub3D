/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_map.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoutill <amoutill@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 18:06:06 by amoutill          #+#    #+#             */
/*   Updated: 2024/07/15 00:41:26 by amoutill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_MAP_H
# define CUB_MAP_H

# include <stdlib.h>
# include "../lib/libft/libft.h"

# define TEXT_PATH_PREFIX_LEN 3
# define COLOR_PREFIX_LEN 2

typedef enum e_setting_type
{
	ERR,
	NO,
	SO,
	WE,
	EA,
	F,
	C
}				t_setting_type;

typedef struct s_rgb
{
	int	r;
	int	g;
	int	b;
}				t_rgb;

typedef struct s_cub_map
{
	char	*no_text_path;
	char	*so_text_path;
	char	*we_text_path;
	char	*ea_text_path;
	t_rgb	floor_color;
	t_rgb	ceil_color;
	char	**map;
}				t_cub_map;

char			*get_next_useful_line(const int fd);
t_setting_type	get_setting_type(const char *line);
char			*get_text_path(const char *line);
int				str_to_color(const char *str);
t_rgb			get_color(const char *line);
int				set_setting(t_cub_map *map, const char *line);
int				set_map(t_cub_map *cub_map, int fd);
int				is_settings_complete(const t_cub_map *cub_map);
int				parse_cub_map(t_cub_map *cub_map, int fd);
void			free_cub_map(t_cub_map *cub_map);
size_t			ft_splitlen(char **split);
int				is_valid_map(char **map);
int				is_enclosed(char **map);
char			**sanitize_map(char **map);
int				is_ok_path(char *cub_map_path);

#endif
