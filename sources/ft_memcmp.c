/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoler <asoler@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 20:08:30 by asoler            #+#    #+#             */
/*   Updated: 2022/04/13 03:50:43 by asoler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*s_s1;
	unsigned char	*s_s2;

	s_s1 = (unsigned char *)s1;
	s_s2 = (unsigned char *)s2;
	while (n != 0)
	{
		if (*s_s1 != *s_s2)
			return (*s_s1 - *s_s2);
		s_s1++;
		s_s2++;
		n--;
	}
	return (0);
}
