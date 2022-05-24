#include "ft_printf.h"
int	manage_conventions(char *s, va_list ap)
{
	if (*s == 'i' || *s == 'd')
	else if (*s == 'u')
	else if (*s == 'x' || *s == 'X')
	else if (*s == 'c')
	else if (*s == 's')
	else if (*s == 'p')
	else if (*s == '%')
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