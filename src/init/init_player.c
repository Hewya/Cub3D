/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabarnou <gabarnou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 01:19:30 by amoutill          #+#    #+#             */
/*   Updated: 2024/07/17 18:18:48 by gabarnou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/player.h"
#include <stddef.h>

int	is_player_tile(char c)
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
		return (0.5f);
	if (c == 'S')
		return (1.5f);
	if (c == 'E')
		return (0.0f);
	if (c == 'W')
		return (1.0f);
	else
		return (42);
}

t_player	init_player(char **map)
{
	size_t		i;
	size_t		j;
	t_player	player;

	get_player_tile_index(map, &i, &j);
	player.coord.x = i + 0.5f;
	player.coord.y = j + 0.5f;
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
