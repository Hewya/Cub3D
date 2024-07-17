/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabarnou <gabarnou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 12:39:31 by gabarnou          #+#    #+#             */
/*   Updated: 2024/07/05 02:18:25 by amoutill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	malloc_usable_size(void *ptr)
{
	void	*start;

	start = ptr;
	while (*(char *)ptr == 0)
		ptr++;
	return ((size_t)(ptr - start));
}

void	*ft_realloc(void *ptr, size_t new_size)
{
	void	*new_ptr;
	size_t	old_size;
	size_t	new_usable_size;

	if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}
	if (ptr == NULL)
		return (malloc(new_size));
	new_ptr = malloc(new_size);
	if (!new_ptr)
		return (NULL);
	old_size = malloc_usable_size(ptr);
	if (old_size < new_size)
		new_usable_size = old_size;
	else
		new_usable_size = new_size;
	memcpy(new_ptr, ptr, new_usable_size);
	free(ptr);
	return (new_ptr);
}
