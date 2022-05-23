#include "x_printf.h"

int	ft_printf_int(int d)
{
	char	*n;
	int		n_len;

	n = ft_itoa(d);
	n_len = ft_strlen(n);
	write(1, n, n_len);
	return (n_len - 1);
}

int	ft_printf_char(char *s, ...)
{
	va_list	ap;
	int		d;
	int		result;

	result = 0;
	va_start(ap, s);
	while(*s)
	{
		if (*s == '%')
		{
			s++;
			d = va_arg(ap, int);
			result += ft_printf_int(d);
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
	int	d;
	int	x;

	d = -2147483648;
	printf("     ____ft_with_d_____\n");
	x = ft_printf_char("My int content is: %d\n", d);
	printf("%i\n     ____ORIGINAL_WITH_I_____\n", x);
	x = printf("My int content is: %d\n", d);
	printf("%i\n", x);

	printf("     ____ft_with_i_____\n");
	x = ft_printf_char("My int content is: %i\n", d);
	printf("%i\n     ____ORIGINAL_WITH_I_____\n", x);
	x = printf("My int content is: %i\n", d);
	printf("%i\n", x);
}

