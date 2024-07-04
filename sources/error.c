/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabarnou <gabarnou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 14:01:33 by gabarnou          #+#    #+#             */
/*   Updated: 2024/07/04 16:21:00 by gabarnou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	usage(void)
{
	printf("USAGE: ./cub3d maps/NAME_OF_MAP.cub");
	return (EXIT_FAILURE);
}

int	error(char *str)
{
	printf("Error: %s\n", str);
	return (EXIT_FAILURE);
}