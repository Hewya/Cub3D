/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoutill <amoutill@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 01:19:30 by amoutill          #+#    #+#             */
/*   Updated: 2024/07/25 19:44:51 by amoutill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/player.h"
#include <math.h>
#include <stddef.h>

static int	is_player_tile(char c)
{
	return (c == 'N' || c == 'S' || c == 'E' || c == 'W');
}

static void	get_player_tile_index(char **map, size_t *row, size_t *col)
{
	*row = 0;
	while (map[*row])
	{
		*col = 0;
		while (map[*row][*col])
		{
			if (is_player_tile(map[*row][*col]))
				return ;
			++*col;
		}
		++*row;
	}
}

static float	angle_from_letter(char c)
{
	if (c == 'N')
		return (0.5f * M_PI);
	if (c == 'S')
		return (1.5f * M_PI);
	if (c == 'E')
		return (0.0f * M_PI);
	if (c == 'W')
		return (1.0f * M_PI);
	else
		return (42);
}

t_player	init_player(char **map)
{
	size_t		i;
	size_t		j;
	t_player	player;

	get_player_tile_index(map, &i, &j);
	player.coord.x = j + 0.5f;
	player.coord.y = i + 0.5f;
	player.coord.a = angle_from_letter(map[i][j]);
	return (player);
}

void	replace_player_tile(char **map)
{
	size_t	i;
	size_t	j;

	get_player_tile_index(map, &i, &j);
	map[i][j] = '0';
}
