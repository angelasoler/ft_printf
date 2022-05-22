/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoler <asoler@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 21:17:45 by asoler            #+#    #+#             */
/*   Updated: 2022/04/15 00:00:13 by asoler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	dest_len;
	size_t	src_len;

	dest_len = ft_strlen(dest);
	src_len = ft_strlen(src);
	if (size == 0)
		return (src_len);
	else if (size < dest_len)
		return (src_len + size);
	while (*dest && size != 0)
	{
		dest++;
		size--;
	}
	while (size > 1 && *src)
	{
		*dest = *src;
		size--;
		src++;
		dest++;
	}
	*dest = '\0';
	return (src_len + dest_len);
}
