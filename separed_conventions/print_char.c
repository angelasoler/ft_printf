#include <stdarg.h>
#include <unistd.h>

int	ft_printf_char(char *s, ...)
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

#include <stdio.h>

int	main()
{
	char	c;
	int		x;

	c = 'c';
	printf("     ____ft_____\n");
	x = ft_printf_char("hello world, thats my char content: %c\n", c);
	printf("%i\n     ____ORIGINAL_____\n", x);
	x = printf("hello world, thats my char content: %c\n", c);
	printf("%i\n", x);
}

