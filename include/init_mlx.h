/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoutill <amoutill@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 01:38:15 by amoutill          #+#    #+#             */
/*   Updated: 2024/07/25 16:42:40 by amoutill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_MLX_H
# define INIT_MLX_H

# include "game_data.h"

# define WINDOW_WIDTH 1280
# define WINDOW_HEIGHT 720
# define WINDOW_TITLE "cub3d"

int	init_mlx(t_game_data *game_data);

#endif
