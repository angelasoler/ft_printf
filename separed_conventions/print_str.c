#include <stdarg.h>
#include <unistd.h>
#include "./sources/libft.h"

int	ft_printf_str(char *s, ...)
{
	va_list	ap;
	char	*s1;
	int		result;

	result = 0;
	va_start(ap, s);
	while(*s)
	{
		if (*s == '%')
		{
			s++;
			s1 = va_arg(ap, char *);
			write(1, s1, ft_strlen(s1));
		}
		else
		{
			write(1, s, 1);
		}
		s++;
		result++;
	}
	result += ft_strlen(s1) - 1;
	return(result);
}

#include <stdio.h>

int	main()
{
	char	*s;
	int		x;

	s = "Hello world ft_printf";
	printf("     ____ft_____\n");
	x = ft_printf_str("Thats my str content: %s\n", s);
	printf("%i\n     ____ORIGINAL_____\n", x);
	x = printf("Thats my str content: %s\n", s);
	printf("%i\n", x);
}

