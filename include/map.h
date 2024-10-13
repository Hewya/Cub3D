/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoutill <amoutill@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 15:39:40 by amoutill          #+#    #+#             */
/*   Updated: 2024/07/24 15:40:19 by amoutill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

typedef struct s_map
{
	char		**map;
	int			map_length;
	int			map_height;
	float		scale_width;
	float		scale_height;
}				t_map;

#endif
