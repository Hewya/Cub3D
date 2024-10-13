/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_enclosed.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoutill <amoutill@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 23:33:00 by amoutill          #+#    #+#             */
/*   Updated: 2024/07/12 23:34:23 by amoutill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

static int	is_valid_border(char c)
{
	return (c == '0' || c == '1' || c == 'N' || c == 'S' || c == 'E'
		|| c == 'W');
}

static int	is_enclosed_tile(char **map, size_t row, size_t col)
{
	if (map[row][col] == '0' || map[row][col] == 'N' || map[row][col] == 'S'
		|| map[row][col] == 'E' || map[row][col] == 'W')
	{
		if (row == 0 || !is_valid_border(map[row - 1][col]))
			return (0);
		if (!map[row + 1] || !is_valid_border(map[row + 1][col]))
			return (0);
		if (col == 0 || !is_valid_border(map[row][col - 1]))
			return (0);
		if (!map[row][col + 1] || !is_valid_border(map[row][col + 1]))
			return (0);
	}
	return (1);
}

int	is_enclosed(char **map)
{
	size_t	row;
	size_t	col;

	row = 0;
	while (map[row])
	{
		col = 0;
		while (map[row][col])
		{
			if (!is_enclosed_tile(map, row, col))
				return (0);
			++col;
		}
		++row;
	}
	return (1);
}
