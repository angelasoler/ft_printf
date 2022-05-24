/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoler <asoler@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 19:16:47 by asoler            #+#    #+#             */
/*   Updated: 2022/05/24 14:27:02 by asoler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*sdest;
	unsigned char	*ssrc;

	if (!dest && !src)
		return (0);
	sdest = (unsigned char *)dest;
	ssrc = (unsigned char *)src;
	if (sdest < ssrc)
	{
		ft_memcpy(dest, src, n);
		return (dest);
	}
	while (n != 0)
	{
		sdest[n - 1] = ssrc[n - 1];
		n--;
	}
	return ((void *)sdest);
}
