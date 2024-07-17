/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabarnou <gabarnou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 12:18:52 by gabarnou          #+#    #+#             */
/*   Updated: 2024/07/03 16:27:51 by gabarnou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buf[BS + 1];
	char		*l;
	char		*nl;
	int			rc;
	int			tc;

	l = ft_strdup(buf);
	while (!(nl = ft_strchr(l, '\n')) && (rc = read(fd, buf, BS)))
	{
		buf[rc] = '\0';
		l = ft_strjoin_free(l, buf, 1);
	}
	if (ft_strlen(l) == 0)
		return (free(l), NULL);
	if (nl != NULL)
	{
		tc = nl - l + 1;
		ft_strcpy(buf, nl + 1);
	}
	else
	{
		tc = ft_strlen(l);
		buf[0] = '\0';
	}
	return (l[tc] = '\0', l);
}
