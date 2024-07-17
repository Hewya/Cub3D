/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_stuff.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabarnou <gabarnou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 12:30:27 by gabarnou          #+#    #+#             */
/*   Updated: 2024/07/16 19:07:46 by gabarnou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycast.h"

double	norm_angle(double angle)
{
	if (angle == 0)
		angle = 0.000001;
	while (angle > (M_PI * 2))
		angle -= M_PI * 2;
	while (angle < 0)
		angle += (M_PI * 2);
	return (angle);
}

bool	is_off_map(t_game_data *data, t_pos intercept)
{
	if (intercept.x > (data->map_length * BLOCK_RES)
		|| intercept.x < 0 || intercept.y < 0
		|| intercept.y >= (data->map_height * BLOCK_RES)
		|| isnan(intercept.x) || isnan(intercept.y))
		return (true);
	return (false);
}

bool	is_wall(t_game_data *data, t_pos intercept)
{
	char	*row;
	char	value;

	row = data->map[(int)(intercept.y / BLOCK_RES)];
	value = row[(int)(intercept.x / BLOCK_RES)];
	return (value == '1');
}

t_wall	ray_len(t_game_data *data, double ray_angle)
{
	t_wall	hor;
	t_wall	vert;

	hor = find_hor_intercept(data, ray_angle);
	vert = find_vert_intercept(data, ray_angle);
	if (hor.ray_len <= vert.ray_len)
	{
		hor.ray_len *= cos(fabs(data->player.coord.a - ray_angle));
		return (hor);
	}
	else
	{
		vert.ray_len *= cos(fabs(data->player.coord.a - ray_angle));
		return (vert);
	}
}

void	raycast(t_game_data *data)
{
	int			i;
	double		ray_angle;
	t_wall	ray_data;

	i = 0;
	ray_angle = data->player.coord.a + (FOV_RAD / 2);
	while (i < WINDOW_WIDTH)
	{
		ray_angle = norm_angle(ray_angle);
		ray_data = ray_len(data, ray_angle);
		ft_draw_wall(data, ray_data, i);
		//ray_angle -= FOV_RAD / WINDOW_WIDTH;
		i++;
	}
	return ;
}
