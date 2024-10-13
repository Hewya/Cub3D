/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabarnou <gabarnou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 18:30:23 by gabarnou          #+#    #+#             */
/*   Updated: 2024/07/25 21:07:23 by amoutill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/raycast.h"
#include <X11/keysym.h>

void	move(t_game_data *data, double angle)
{
	t_pos	check_wall;
	t_wall	x;
	t_wall	y;
	double	len;

	len = MOVESPEED;
	x = find_hor_intercept(data, norm_angle(angle));
	y = find_vert_intercept(data, norm_angle(angle));
	if (x.ray_len < y.ray_len)
		len = x.ray_len;
	else
		len = y.ray_len;
	if (len < 0)
		len = -len;
	if (len > MOVESPEED)
		len = MOVESPEED;
	check_wall.x = data->player.coord.x + cos(angle) * len;
	check_wall.y = data->player.coord.y - sin(angle) * len;
	check_and_move(data, check_wall);
}

void	rotate(t_game_data *data, int dir)
{
	data->player.coord.a = norm_angle(data->player.coord.a - (ROTATIONSPEED
				* dir));
	put_pixel_to_background(data);
	raycast(data);
	draw_minimap(data);
}

int	key_hook(int keycode, void *param)
{
	t_game_data	*data;

	data = param;
	if (keycode == XK_Left)
		rotate(data, -1);
	if (keycode == XK_Right)
		rotate(data, 1);
	if (keycode == XK_w)
		move(data, data->player.coord.a);
	if (keycode == XK_s)
		move(data, data->player.coord.a - M_PI);
	if (keycode == XK_a)
		move(data, data->player.coord.a + M_PI_2);
	if (keycode == XK_d)
		move(data, data->player.coord.a - M_PI_2);
	if (keycode == XK_Escape)
	{
		free_game_data(data);
		exit(0);
	}
	put_pixel_to_background(data);
	raycast(data);
	draw_minimap(data);
	return (0);
}

void	check_and_move(t_game_data *data, t_pos check_wall)
{
	if (is_off_map(data, check_wall) || is_wall(data, check_wall))
		return ;
	data->player.coord.x = check_wall.x;
	data->player.coord.y = check_wall.y;
}
