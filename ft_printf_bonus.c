/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoler <asoler@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 01:05:19 by asoler            #+#    #+#             */
/*   Updated: 2022/05/28 17:06:56 by asoler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	flags(char flag, int n)
{
	int	result;

	result = 0;
	if (flag == '#')
	{
		if ((char)n == 'X')
			write(1, "0X", 2);
		else
			write(1, "0x", 2);
		result += 2;
	}
	else if (flag == '+')
	{
		if ( n >= 0)
		{
			write(1, "+", 1);
			result += 1;
		}
	}
	else if (flag == ' ')
	{
		if ( n >= 0)
		{
			write(1, " ", 1);
			result += 1;
		}
	}
	return (result);
}

int	int_conversion(char c, char *conv)
{
	int		i;

	i = 0;
	while (conv[i])
	{
		if (c == conv[i])
			return (1);
		i++;
	}
	return (0);
}

int	manage_int_convs(const char *s, va_list ap)
{
	t_vars	vars;
	int		len;
	char	flag;

	len = 0;
	flag = 0;
	if (int_conversion(*s, "# +"))
	{
		flag = *s;
		s++;
	}
	if (*s == 'i' || *s == 'd')
	{
		vars.sn = va_arg(ap, int);
		if (flag)
			len += flags(flag, vars.sn);
		len += ft_printf_int(vars.sn);
	}
	else if (*s == 'u' || *s == 'x' || *s == 'X')
	{
		vars.un = va_arg(ap, unsigned int);
		if (*s == 'x' || *s == 'X')
		{
			if (flag)
				len += flags(flag, (int)*s);
			len += ft_printf_int_as_hex(vars.un, *s);
		}
		else
			len += ft_printf_usig_int(vars.un);
	}
	else if (*s == 'p')
	{
		vars.address = va_arg(ap, unsigned long);
		len += ft_printf_address(vars.address);
	}
	return (len);
}

int	manage_other_convs(const char *s, va_list ap)
{
	t_vars	vars;
	int		len;

	len = 0;
	if (*s == 'c')
	{
		vars.c = (char)va_arg(ap, int);
		len += ft_printf_char(vars.c);
	}
	else if (*s == 's')
	{
		vars.s = va_arg(ap, char *);
		len += ft_printf_str(vars.s);
	}
	else if (*s == '%')
		write(1, "%", 1);
	return (len);
}

int	ft_printf(const char *s, ...)
{
	va_list	ap;
	int		result;

	result = 0;
	va_start(ap, s);
	while (*s)
	{
		if (*s == '%')
		{
			s++;
			if (int_conversion(*s, "iudXxp #+"))
				result += manage_int_convs(s, ap);
			else
				result += manage_other_convs(s, ap);
			if (int_conversion(*s, "# +"))
				s++;
		}
		else
			write(1, s, 1);
		s++;
		result++;
	}
	va_end(ap);
	return (result);
}

#include <stdio.h>
int	main()
{
	int y;
	int x = 10;

	y = printf("%d\n", x);
	printf("%+d\n", y);
	y = ft_printf("%+s\n", "xx");
	printf("%+d\n", y);
}
