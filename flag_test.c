#include <stdio.h>
#include <stdarg.h>
char	*int_to_hexa(int n, char c)
{
	char	*number;
	char	temp[4000000];
	int		i;

	i = 0;
	while (n % 16)
	{
		if (n % 16 > 9)
		{
			x = n % 16;
			x += 87;
			temp[i] = x;
		}
		else
		{
			temp[i] = (n % 16) + 48;
		}
		n /= 16;
		i++;
	}
	temp[i] = '\0';
	number = malloc(sizeof(char) * i + 1);
	i = 0;
	while (temp[i])
	{
		number[i] = temp[i];
		i++;
	}
	number[i] = '\0';
	if (c == 'X')
	{
		toupper(number);
	}
	return(number);
}

int ft_printf_fa(char *fmt, ...)
{
	va_list ap;
	char c;
	char *s;
	int d;

	va_start(ap, *fmt);
	while(*fmt)
	{
		if (*fmt == '%')
		{
			*fmt++;
			if (*fmt == 'c')
			if (*fmt == 's')
			if (*fmt == 'p')
			if (*fmt == 'd')
			if (*fmt == 'i')
			if (*fmt == 'u')
			if (*fmt == 'x')
			if (*fmt == 'X')
			if (*fmt == '%')
		}
		else if
		{
			//join char to temp cha*
			fmt++;
		}
	}
	// print with write
}

int	main(void)
{
	int x; 
	x = printf("%u\n", 429496729);
	printf("%i\n", x);
	printf("%x\n", x);
}
