/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabarnou <gabarnou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 18:30:23 by gabarnou          #+#    #+#             */
/*   Updated: 2024/07/17 19:52:46 by gabarnou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycast.h"

void	move(t_game_data *data, double angle)
{
	t_pos	check_wall;
	t_wall	x;
	t_wall	y;
	double		len;

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
	return (check_and_move(data, check_wall));
}

void	rotate(t_game_data *data, int dir)
{
	data->player.coord.a = norm_angle(data->player.coord.a -
			(ROTATIONSPEED * dir));
	ft_put_pixel_to_background(data);
	raycast(data);
	draw_minimap(data);
}

void	key_hook(void *param)
{
	t_game_data	*data;

	data = param;
	if (mlx_is_key_down(data->mlx_connection, XK_KP_Left))
		rotate(data, -1);
	if (mlx_is_key_down(data->mlx_connection, XK_KP_Right))
		rotate(data, 1);
	if (mlx_is_key_down(data->mlx_connection, XK_w))
		move(data, data->player.coord.a);
	if (mlx_is_key_down(data->mlx_connection,XK_s))
		move(data, data->player.coord.a - M_PI);
	if (mlx_is_key_down(data->mlx_connection, XK_a))
		move(data, data->player.coord.a + M_PI_2);
	if (mlx_is_key_down(data->mlx_connection, XK_d))
		move(data, data->player.coord.a - M_PI_2);
	if (mlx_is_key_down(data->mlx_connection, XK_Escape))
		mlx_destroy_window(data->mlx_connection, data->mlx_window);
	ft_put_pixel_to_background(data);
	raycast(data);
	draw_minimap(data);
}

void	check_and_move(t_game_data *data, t_pos check_wall)
{
	if (is_off_map(data, check_wall) || is_wall(data, check_wall))
		return ;
	data->player.coord.x = check_wall.x;
	data->player.coord.y = check_wall.y;
}
