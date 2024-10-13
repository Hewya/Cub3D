/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoutill <amoutill@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 23:30:22 by amoutill          #+#    #+#             */
/*   Updated: 2024/07/14 04:27:04 by amoutill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	is_valid_map_char(char c)
{
	if (c == '0' || c == '1' || c == ' ')
		return (1);
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (2);
	return (0);
}

static int	is_valid_map_line(const char *s)
{
	int		valid;
	int		player_found;

	player_found = 0;
	while (*s)
	{
		valid = is_valid_map_char(*(s++));
		if (!valid)
			return (0);
		if (valid == 2)
		{
			if (player_found)
				return (0);
			player_found = 1;
		}
	}
	if (player_found)
		return (2);
	return (1);
}

int	is_valid_map(char **map)
{
	int	valid;
	int	player_found;

	player_found = 0;
	while (*map)
	{
		valid = is_valid_map_line(*(map++));
		if (!valid)
			return (0);
		if (valid == 2)
		{
			if (player_found)
				return (0);
			player_found = 1;
		}
	}
	if (player_found)
		return (1);
	return (0);
}
