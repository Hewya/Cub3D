/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabarnou <gabarnou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 12:30:27 by gabarnou          #+#    #+#             */
/*   Updated: 2024/07/10 12:35:46 by gabarnou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	is_wall(t_data *data, t_2float pos, bool is_player)
{
	if (pos.x <= 0 || pos.y <= 0 || pos.x >= data->map.map_size.x
		|| pos.y >= data->map.map_size.y)
		return (true);
	if (!is_player)
	{
		if (data->map.map[(int)pos.y][(int)pos.x] == '1')
			return (true);
		return (false);
	}
	if (data->map.map[(int)(pos.y - 0.2f)][(int)(pos.x - 0.2f)] == '1'
		|| data->map.map[(int)(pos.y - 0.2f)][(int)(pos.x + 0.2f)] == '1'
		|| data->map.map[(int)(pos.y + 0.2f)][(int)(pos.x - 0.2f)] == '1'
		|| data->map.map[(int)(pos.y + 0.2f)][(int)(pos.x + 0.2f)] == '1')
		return (true);
	return (false);
}
