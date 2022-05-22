/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoler <asoler@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 20:20:09 by asoler            #+#    #+#             */
/*   Updated: 2022/04/13 20:25:17 by asoler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	unsigned int	i;

	if (size <= 0)
		return (ft_strlen(src));
	i = 0;
	while (i < size)
	{
		if (src[i] == '\0')
		{
			dest[i] = src[i];
			return (ft_strlen(src));
		}
		dest[i] = src[i];
		i++;
	}
	dest[i - 1] = '\0';
	return (ft_strlen(src));
}
