/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoutill <amoutill@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 19:23:46 by amoutill          #+#    #+#             */
/*   Updated: 2024/07/13 02:28:04 by amoutill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H

typedef struct s_coord
{
	float	x;
	float	y;
	float	a;
}				t_coord;

typedef struct s_player
{
	t_coord	coord;
}				t_player;

t_player	init_player(char **map);
void		replace_player_tile(char **map);

#endif
