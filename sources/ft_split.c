/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoler <asoler@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 17:44:10 by asoler            #+#    #+#             */
/*   Updated: 2022/04/21 04:53:32 by asoler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *s, char c)
{
	int	wc;

	s++;
	wc = 1;
	while (*s == c)
		s++;
	while (*s)
	{
		while (*s == c)
		{
			s++;
			if (*s != c && *s != '\0')
				wc++;
		}
		if (*s != '\0')
			s++;
	}
	return (wc);
}

static char	**result_array(char	**dest, char *s1, char c)
{
	char	*beg;
	int		i;

	i = 0;
	while (*s1)
	{
		beg = s1;
		while (*s1 != c && *s1 != '\0')
			s1++;
		if (*s1 != '\0')
		{
			*s1 = '\0';
			s1++;
		}
		dest[i] = ft_strdup(beg);
		while (*s1 == c && *s1 != '\0')
			s1++;
		i++;
	}
	dest[i] = 0;
	return (dest);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	char	*s1;
	int		size;
	int		i;

	i = 0;
	if (*s == 0)
	{
		result = malloc(sizeof(char *) * 1);
		result[0] = (char *)0;
		return (result);
	}
	s1 = ft_strdup(s);
	size = count_words(s, c);
	result = (char **)malloc(sizeof(char *) * (size + 1));
	if (!result)
		return (0);
	while (s1[i] == c)
		i++;
	result = result_array(result, &s1[i], c);
	free(s1);
	return (result);
}
