/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabarnou <gabarnou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 19:34:46 by amoutill          #+#    #+#             */
/*   Updated: 2024/07/17 18:40:25 by gabarnou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEXTURES_H
# define TEXTURES_H

#include <stdint.h>
# include "../minilibx-linux/mlx.h"

typedef struct s_texture
{
	void	*image;
	char	*texture;
	int		height;
	int		width;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
	uint8_t	*pixels;
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

#endif
