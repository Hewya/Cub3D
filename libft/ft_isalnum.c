/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaelle <gaelle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 18:15:53 by gaelle            #+#    #+#             */
/*   Updated: 2023/10/24 18:00:17 by gaelle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalnum(int i)
{
	return ((i >= 'A' && i <= 'Z')
		|| (i >= 'a' && i <= 'z')
		|| (i >= '0' && i <= '9'));
}
