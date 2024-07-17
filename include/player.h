/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabarnou <gabarnou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 19:23:46 by amoutill          #+#    #+#             */
/*   Updated: 2024/07/17 18:19:24 by gabarnou         ###   ########.fr       */
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

int	is_player_tile(char c);
t_player	init_player(char **map);
void		replace_player_tile(char **map);

#endif
