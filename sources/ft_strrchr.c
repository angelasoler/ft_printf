/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoler <asoler@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 20:40:36 by asoler            #+#    #+#             */
/*   Updated: 2022/04/13 03:37:53 by asoler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int				i;
	int				result;
	unsigned char	a;

	if (c == 0)
		return ((char *)&s[ft_strlen(s)]);
	a = (unsigned char)c;
	i = 0;
	result = -1;
	while (*s)
	{
		if (*s == a)
			result = i;
		s++;
		i++;
	}
	if (result == -1)
		return ((char *)0);
	else
	{
		i -= result;
		return ((char *)s - i);
	}
}
