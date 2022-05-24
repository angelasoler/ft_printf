#include "x_printf.h"

int	unsig_putnbr(unsigned int n)
{
	int		i;
	int		r;
	char	digits[10];

	i = 0;
	while (n > 9)
	{
		digits[i] = (n % 10) + 48;
		n /= 10;
		i++;
	}
	digits[i] = n + 48;
	r = i;
	while (i >= 0)
	{
		write(1, &digits[i] , 1);
		i--;
	}
	return (r);
}

int	printf_u(char *s, ...)
{
	va_list			ap;
	unsigned int	n;
	int				result;

	result = 0;
	va_start(ap, s);
	while (*s)
	{
		if (*s == '%')
		{
			s++;
			n = va_arg(ap, unsigned int);
			result += unsig_putnbr(n);
		}
		else
			write(1, s, 1);
		s++;
		result++;
	}
	return (result);
}

#include <stdio.h>
int	main()
{
	unsigned int	x = 4294967295;
	int y;

	printf("   ----Original----\n");
	y = printf("%u\n",x);
	printf("%i\n", y);
	printf("    ----FT----\n");
	y = printf_u("%u\n",x);
	printf("%i\n", y);
}

