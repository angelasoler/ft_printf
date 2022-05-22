/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoler <asoler@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 01:50:46 by asoler            #+#    #+#             */
/*   Updated: 2022/04/19 20:14:24 by asoler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*x;

	if (nmemb > __SIZE_MAX__ / size)
		return (NULL);
	x = malloc(size * nmemb);
	if (!x)
		return (NULL);
	ft_bzero(x, (size * nmemb));
	return (x);
}
