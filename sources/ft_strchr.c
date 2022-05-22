/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoler <asoler@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 22:03:00 by asoler            #+#    #+#             */
/*   Updated: 2022/04/13 03:22:20 by asoler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char	a;

	if (c == 0)
	{
		return ((char *)&s[ft_strlen(s)]);
	}
	a = (unsigned char)c;
	while (*s != '\0' && *s != a)
	{
		s++;
	}
	if (*s == '\0')
		return ((char *)0);
	else
		return ((char *)s);
}
