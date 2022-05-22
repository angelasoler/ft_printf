#include <stdarg.h>
#include <unistd.h>

int	ft_printf(char *s, ...)
{
	va_list	ap;
	char	c;
	int		result;

	result = 0;
	va_start(ap, s);
	while(*s)
	{
		if (*s == '%')
		{
			s++;
			c = (char) va_arg(ap, int);
			write(1, &c, 1);
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
	char c;
	c = 'c';

	ft_printf("hello world, that my char content: %c\n", c);
}

