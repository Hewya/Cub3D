/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoutill <amoutill@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 19:34:46 by amoutill          #+#    #+#             */
/*   Updated: 2024/07/24 20:28:36 by amoutill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEXTURES_H
# define TEXTURES_H

# include "../lib/minilibx/mlx.h"
# include <stdint.h>
# include <stddef.h>

typedef struct s_texture
{
	void	*image;
	char	*texture;
	int		height;
	int		width;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
}				t_texture;

typedef struct s_textures
{
	t_texture		north;
	t_texture		south;
	t_texture		east;
	t_texture		west;
	unsigned int	floor;
	unsigned int	ceil;
}				t_textures;

void	set_image_pixel_color(t_texture image, int color, size_t x, size_t y);

#endif
