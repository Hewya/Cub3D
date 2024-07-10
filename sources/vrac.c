/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vrac.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabarnou <gabarnou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 15:47:10 by gabarnou          #+#    #+#             */
/*   Updated: 2024/07/10 12:23:14 by gabarnou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	find_player(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map.map[i])
	{
		j = 0;
		while (data->map.map[i][j])
		{
			if (data->map.map[i][j] == 'W'
				|| data->map.map[i][j] == 'N'
				|| data->map.map[i][j] == 'S'
				|| data->map.map[i][j] == 'E')
			{
				data->map.start_pos.x = i;
				data->map.start_pos.y = j;
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

double	deg_to_rad(double deg)
{
	return (deg * M_PI / 180.0);
}

