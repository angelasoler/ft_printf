/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoler <asoler@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 15:20:13 by asoler            #+#    #+#             */
/*   Updated: 2022/05/24 14:25:56 by asoler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned int	i;
	char			*result;

	i = 0;
	result = (char *)s;
	while (i < n)
	{
		result[i] = 0;
		i++;
	}
}
