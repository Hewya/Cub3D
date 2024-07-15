/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabarnou <gabarnou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 12:11:38 by gabarnou          #+#    #+#             */
/*   Updated: 2024/07/15 00:49:17 by gabarnou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	move_forward(t_data *data)
{
	t_pos	new_pos;
	int		ret;

	ret = 0;
	new_pos = data->player_pos;
	new_pos.x += cos(deg_to_rad(data->player_dir)) * PLAYER_SPEED;
	if (is_wall(data, new_pos, true) == false)
		data->player_pos = new_pos;
	else
		ret++;
	new_pos.y += sin(deg_to_rad(data->player_dir)) * PLAYER_SPEED;
	if (is_wall(data, new_pos, true) == false)
		data->player_pos = new_pos;
	else
		ret++;
	return (ret);
}

int	move_backward(t_data *data)
{
	t_pos	new_pos;
	int		ret;

	ret = 0;
	new_pos = data->player_pos;
	new_pos.x -= cos(deg_to_rad(data->player_dir)) * PLAYER_SPEED;
	if (is_wall(data, new_pos, true) == false)
		data->player_pos = new_pos;
	else
		ret++;
	new_pos.y -= sin(deg_to_rad(data->player_dir)) * PLAYER_SPEED;
	if (is_wall(data, new_pos, true) == false)
		data->player_pos = new_pos;
	else
		ret++;
	return (ret);
}

int	move_left(t_data *data)
{
	t_pos	new_pos;
	int		ret;

	ret = 0;
	new_pos = data->player_pos;
	new_pos.x += cos(deg_to_rad(data->player_dir - 90)) * PLAYER_SPEED;
	if (is_wall(data, new_pos, true) == false)
		data->player_pos = new_pos;
	else
		ret++;
	new_pos.y += sin(deg_to_rad(data->player_dir - 90)) * PLAYER_SPEED;
	if (is_wall(data, new_pos, true) == false)
		data->player_pos = new_pos;
	else
		ret++;
	return (ret);
}

int	move_right(t_data *data)
{
	t_pos	new_pos;
	int		ret;

	ret = 0;
	new_pos = data->player_pos;
	new_pos.x -= cos(deg_to_rad(data->player_dir - 90)) * PLAYER_SPEED;
	if (is_wall(data, new_pos, true) == false)
		data->player_pos = new_pos;
	else
		ret++;
	new_pos.y -= sin(deg_to_rad(data->player_dir - 90)) * PLAYER_SPEED;
	if (is_wall(data, new_pos, true) == false)
		data->player_pos = new_pos;
	else
		ret++;
	return (ret);
}
