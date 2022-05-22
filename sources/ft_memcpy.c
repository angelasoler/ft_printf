/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoler <asoler@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 16:51:30 by asoler            #+#    #+#             */
/*   Updated: 2022/04/22 17:36:00 by asoler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*sdest;
	unsigned char	*ssrc;
	unsigned int	i;

	if (!dest && !src)
		return (0);
	i = 0;
	sdest = (unsigned char *)dest;
	ssrc = (unsigned char *)src;
	while (i < n)
	{
		sdest[i] = ssrc[i];
		i++;
	}
	return ((void *)sdest);
}
