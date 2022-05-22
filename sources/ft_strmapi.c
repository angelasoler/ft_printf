/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoler <asoler@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 02:50:16 by asoler            #+#    #+#             */
/*   Updated: 2022/04/12 22:22:39 by asoler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*result;
	int		len;
	int		i;

	i = 0;
	len = ft_strlen(s) + 1;
	result = malloc(sizeof(char) * len);
	if (!result)
		return (0);
	while (*s)
	{
		result[i] = f(i, *s);
		i++;
		s++;
	}
	result[i] = *s;
	return (result);
}
