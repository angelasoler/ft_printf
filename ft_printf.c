#include "ft_printf.h"

int	manage_conventions(char *s, va_list ap)
{
	t_vars vars;
	int len;

	len = 0;
	if (*s == 'i' || *s == 'd')
	{
		vars.sn = va_arg(ap, int);
		len += ft_printf_int(vars.sn);
	}
	else if (*s == 'u')
	{
		vars.un = va_arg(ap, unsigned int);
		len += unsig_putnbr(vars.un);
	}
	else if (*s == 'x' || *s == 'X')
	{
		vars.un = va_arg(ap, unsigned int);
		len += int_to_hexa(vars.un);
	}
	else if (*s == 'c')
	{
		vars.c = va_arg(ap, char);
		len += ft_printf_char(c , NULL);
	}
	else if (*s == 's')
	{
		vars.s = va_arg(ap, char);
		len += ft_printf_char(NULL, s);
	}
	else if (*s == 'p')
	{
		vars.s = va_arg(ap, char *);
		len += ft_printf_char(NULL, s);
	}
	else if (*s == '%')
	{
		write(1, '%', 1);
		len++;
	}
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
			result += manage_conventions(s++, ap);
		}
		else
		{
			write(1, s, 1);
		}
		s++;
		result++;
	}
	return(result);
}

int	main()
{
	ft_putnbr_fd(156216, 1);
}
