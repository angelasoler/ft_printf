/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoler <asoler@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 01:05:19 by asoler            #+#    #+#             */
/*   Updated: 2022/05/28 19:16:54 by asoler           ###   ########.fr       */
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
	else
	{
		if (n >= 0)
			write(1, &flag, 1);
		return (1);
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

	vars.len = 0;
	vars.flag = *s;
	if (int_conversion(*s, "# +"))
		s++;
	if (*s == 'i' || *s == 'd')
	{
		vars.sn = va_arg(ap, int);
		vars.len += ft_printf_int(vars.sn, vars.flag);
	}
	else if (*s == 'u' || *s == 'x' || *s == 'X')
	{
		vars.un = va_arg(ap, unsigned int);
		if (*s == 'x' || *s == 'X')
		{
			if (vars.flag == '#')
				vars.len += flags(vars.flag, (int)*s);
			vars.len += ft_printf_int_as_hex(vars.un, *s);
		}
		else
			vars.len += ft_printf_usig_int(vars.un);
	}
	return (vars.len);
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
	else if (*s == 'p')
	{
		vars.address = va_arg(ap, unsigned long);
		len += ft_printf_address(vars.address);
	}
	else if (*s == '%')
		write(1, "%", 1);
	return (len);
}

int	ft_printf_bonus(const char *s, ...)
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
			if (int_conversion(*s, "iudXx #+"))
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
