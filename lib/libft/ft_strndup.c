/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabarnou <gabarnou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 14:30:06 by gabarnou          #+#    #+#             */
/*   Updated: 2024/07/05 02:19:36 by amoutill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s1, size_t n)
{
	char	*copy;
	size_t	i;

	copy = (char *)malloc((n + 1) * sizeof(char));
	if (copy == NULL)
		return (NULL);
	i = 0;
	while (i < n && s1[i] != '\0')
	{
		copy[i] = s1[i];
		i++;
	}
	while (i < n)
	{
		copy[i] = '\0';
		i++;
	}
	copy[n] = '\0';
	return (copy);
}
