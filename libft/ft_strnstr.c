/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoler <asoler@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 21:05:30 by asoler            #+#    #+#             */
/*   Updated: 2022/05/24 14:28:48 by asoler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	size;
	size_t	i;

	i = 0;
	size = ft_strlen(little);
	if (size == 0)
		return ((char *)big);
	else if (len == 0)
		return ((char *)0);
	else
	{
		while (i <= len && *big)
		{
			if ((*big == little[0] && (len - i) >= size) && \
				!ft_strncmp(big, little, size))
				return ((char *)big);
			big++;
			i++;
		}
		return ((char *)0);
	}
}
