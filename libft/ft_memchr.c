/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoler <asoler@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 22:24:23 by asoler            #+#    #+#             */
/*   Updated: 2022/05/24 14:26:53 by asoler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*aux;
	unsigned char	a;

	a = (unsigned char)c;
	if (n == 0)
		return ((unsigned char *) 0);
	aux = (unsigned char *)s;
	while (*aux != a && n > 1)
	{
		aux++;
		n--;
	}
	if (*aux != a)
		return ((unsigned char *) 0);
	else
		return (aux);
}
