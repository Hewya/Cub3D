/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabarnou <gabarnou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 01:06:58 by gabarnou          #+#    #+#             */
/*   Updated: 2024/07/15 01:28:17 by gabarnou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// void	init_mlx(t_fractal *fractal)
// {
// 	fractal->mlx = mlx_init();
// 	fractal->window = mlx_new_window(fractal->mlx, SIZE, SIZE, "Fractol !");
// 	fractal->img = mlx_new_image(fractal->mlx, SIZE, SIZE);
// 	fractal->addr_img = mlx_get_data_addr(fractal->img,
// 			&fractal->bits_per_pixel,
// 			&fractal->lenght_line,
// 			&fractal->endian);
// }

void	quit_game(t_data *data)
{
	mlx_delete_texture(data->texture_path.ea_wall_texture);
	mlx_delete_texture(data->texture_path.no_wall_texture);
	mlx_delete_texture(data->texture_path.so_wall_texture);
	mlx_delete_texture(data->texture_path.we_wall_texture);
	mlx_delete_image(data->mlx, data->img);
	mlx_close_window(data->mlx);
	mlx_terminate(data->mlx);
	ft_free(data);
}

int	data_init(t_data *data)
{
	data->map.fd = -1;
	data->texture_path.north_texture = NULL;
	data->texture_path.south_texture = NULL;
	data->texture_path.west_texture = NULL;
	data->texture_path.east_texture = NULL;
	data->map.map = NULL;
	data->ceiling = NULL;
	data->floor = NULL;
	data->player_pos.x = -1;
	data->player_pos.y = -1;
	return (0);
}

void	open_dislay(t_data data)
{
	data.mlx = mlx_init(DEFAULT_WIN_W, DEFAULT_WIN_H, "Cub3D", true);
	if (!data.mlx)
	{
		mlx_delete_texture(data.texture_path.ea_wall_texture);
		mlx_delete_texture(data.texture_path.no_wall_texture);
		mlx_delete_texture(data.texture_path.so_wall_texture);
		mlx_delete_texture(data.texture_path.we_wall_texture);
		ft_errorfree("Display", "unable to initialise display\n", &data);
	}
}