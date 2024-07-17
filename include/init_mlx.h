/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabarnou <gabarnou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 01:38:15 by amoutill          #+#    #+#             */
/*   Updated: 2024/07/16 16:57:22 by gabarnou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_MLX_H
# define INIT_MLX_H

# include "game_data.h"

# define WINDOW_WIDTH 320
# define WINDOW_HEIGHT 240
# define WINDOW_TITLE "cub3d"

int	init_mlx(t_game_data *game_data);

#endif
