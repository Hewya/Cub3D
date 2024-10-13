/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finding_wall.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabarnou <gabarnou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 11:26:28 by gabarnou          #+#    #+#             */
/*   Updated: 2024/07/25 22:56:26 by amoutill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/raycast.h"
#include <math.h>

void	find_first_hor(t_game_data *data, double angle, t_pos *hor_int,
		t_wall *hor_wall)
{
	if (angle < M_PI)
	{
		hor_int->y = floorf(data->player.coord.y) - 0.000001;
		hor_wall->walldirection = 'S';
	}
	else
	{
		hor_int->y = ceilf(data->player.coord.y);
		hor_wall->walldirection = 'N';
	}
	hor_int->x = data->player.coord.x + ((data->player.coord.y - hor_int->y)
			/ tan(angle));
}

t_wall	find_hor_intercept(t_game_data *data, double angle)
{
	t_pos	hor_int;
	t_wall	hor_wall;
	float	step_y;
	float	step_x;

	if (angle < M_PI)
		step_y = -1;
	else
		step_y = 1;
	step_x = -step_y / tan(angle);
	find_first_hor(data, angle, &hor_int, &hor_wall);
	while (!is_off_map(data, hor_int) && !is_wall(data, hor_int))
	{
		hor_int.y += step_y;
		hor_int.x += step_x;
	}
	if (is_off_map(data, hor_int))
		hor_wall.ray_len = INFINITY;
	else
		hor_wall.ray_len = sqrt(pow(fabs(data->player.coord.x - hor_int.x), 2)
				+ pow(fabs(data->player.coord.y - hor_int.y), 2));
	hor_wall.intercept.x = hor_int.x;
	hor_wall.intercept.y = hor_int.y;
	return (hor_wall);
}

void	find_first_vert(t_game_data *data, double angle, t_pos *vert_int,
		t_wall *vert_wall)
{
	if (angle > M_PI_2 && angle < 3 * M_PI_2)
	{
		vert_int->x = floorf(data->player.coord.x) - 0.000001;
		vert_wall->walldirection = 'E';
	}
	else
	{
		vert_int->x = ceilf(data->player.coord.x);
		vert_wall->walldirection = 'W';
	}
	vert_int->y = data->player.coord.y + ((data->player.coord.x - vert_int->x)
			* tan(angle));
}

t_wall	find_vert_intercept(t_game_data *data, const double angle)
{
	t_pos	vert_int;
	t_wall	vert_wall;
	float	step_x;
	float	step_y;

	if (angle > M_PI_2 && angle < 3 * M_PI_2)
		step_x = -1;
	else
		step_x = 1;
	step_y = -step_x * tan(angle);
	find_first_vert(data, angle, &vert_int, &vert_wall);
	while (!is_off_map(data, vert_int) && !is_wall(data, vert_int))
	{
		vert_int.x += step_x;
		vert_int.y += step_y;
	}
	if (is_off_map(data, vert_int))
		vert_wall.ray_len = INFINITY;
	else
		vert_wall.ray_len = sqrt(pow(fabs(data->player.coord.x - vert_int.x), 2)
				+ pow(fabs(data->player.coord.y - vert_int.y), 2));
	vert_wall.intercept.x = vert_int.x;
	vert_wall.intercept.y = vert_int.y;
	return (vert_wall);
}
