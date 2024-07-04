/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabarnou <gabarnou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 13:55:13 by gabarnou          #+#    #+#             */
/*   Updated: 2024/07/04 15:40:53 by gabarnou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int ac, char **av)
{
	if (ac != 2)
		usage();
	else if (parse_input(av[1]) == SUCCESS)
	{
		int fd;
		char *file_content;

		fd = open(av[1], O_RDONLY);
		if (fd == -1)
			return (error("cannot open file"));
		file_content = translate_cub_file(fd);
		if (!file_content)
		{
			close(fd);
			return (EXIT_FAILURE);
		}

		printf("%s\n", file_content);
		free(file_content);
		close(fd);
		return (EXIT_SUCCESS);
		// translate_cub_file();
			//traduit le fichier pour pouvoir travailler avec
		// init_game(); //initialisation des structures
		// parse_map_file(); //verification des syntaxes + stock dans struct
		// cub_to_tab(); // traduction de la map .cub dans un char**
		// map_is_close(); //verification dsi la map est fermee
		// get_player_pos(); //recupere la position et l'orientation du player
		// clean_map(); // preparation de la map a l'exploitation

	}
}