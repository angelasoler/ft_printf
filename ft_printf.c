#include "ft_printf.h"

int	manage_conventions(const char *s, va_list ap)
{
	t_vars vars;
	int len;

	len = 0;
	if (*s == 'i' || *s == 'd')
	{
		vars.sn = va_arg(ap, int);
		len += ft_printf_int(vars.sn);
	}
	else if (*s == 'u' || *s == 'x' || *s == 'X')
	{
		vars.un = va_arg(ap, unsigned int);
		if (*s == 'x' || *s == 'X')
			len += int_to_hexa(vars.un, *s);
		else
			len += unsig_putnbr(vars.un);
	}
	else if (*s == 'c')
	{
		vars.c = (char)va_arg(ap, int);
		len += ft_printf_char(vars.c , 0);
	}
	else if (*s == 's')
	{
		vars.s = va_arg(ap, char *);
		len += ft_printf_char(0, vars.s);
	}
	else if (*s == 'p')
	{
		vars.address = va_arg(ap, unsigned long);
		len += unsig_long_to_hexa(vars.address);
	}
	else if (*s == '%')
		write(1, "%", 1);
	else
		write(1, s, 1);
	return (len);
}

int	ft_printf(const char *s, ...)
{
	va_list	ap;
	int		result;

	result = 0;
	va_start(ap, s);
	while(*s)
	{
		if (*s == '%')
		{
			s++;
			result += manage_conventions(s, ap);
		}
		else
		{
			write(1, s, 1);
		}
		s++;
		result++;
	}
	va_end(ap);
	return(result);
}
