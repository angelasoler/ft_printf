#include "./x_printf.h"

int	signed_int_to_hexa(int n, char c)
{
	char	temp[8] = "ffffffff";
	int		i;
	int		count;

	i = 0;
	n *= -1;
	count = 8;
	while (n)
	{
		if (n % 16 > 5)
			temp[i] = (15 - (n % 16)) + 48;
		else
			temp[i] = 102 - (n % 16);
		if (i == 0)
		{
			if (temp[i] == '9')
				temp[i] = 'a';
			else
				temp[i] += 1;
		}
		n /= 16;
		if (c == 'X')
			temp[i] = ft_toupper(temp[i]);
		i++;
	}
	count -= i;
	while (count)
	{
		count--;
		if (c == 'x')
			write(1, "f", 1);
		else
			write(1, "F", 1);
	}
	while (i)
	{
		i--;
		write(1, &temp[i], 1);
	}
	return(ft_strlen(temp) - 1);
}

int	int_to_hexa(int n, char c)
{
	char	temp[8];
	int		i;
	if (n < 0)
		return (signed_int_to_hexa(n, c));

	i = 0;
	while (n)
	{
		if (n % 16 > 9)
			temp[i] = (n % 16) + 87;
		else
			temp[i] = (n % 16) + 48;
		n /= 16;
		if (c == 'X')
			temp[i] = ft_toupper(temp[i]);
		i++;
	}
	temp[i] = '\0';
	while (i)
	{
		i--;
		write(1, &temp[i], 1);
	}
	return(ft_strlen(temp) - 1);
}

int	ft_printf_char(char *s, ...)
{
	va_list	ap;
	unsigned int	n;
	int		result;

	result = 0;
	va_start(ap, s);
	while(*s)
	{
		if (*s == '%')
		{
			s++;
			n = va_arg(ap, unsigned int);
			result += int_to_hexa(n, *s);
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
	int		x;
	int		y;

	x = -948622822;
	printf("     ____ft_____\n");
	y = ft_printf_char("Thats my int content returned into x0: %X\n", x);
	printf("%i\n     ____ORIGINAL_____\n", y);
	y = printf("Thats my int content returned into x0: %X\n", x);
	printf("%i\n", y);
}
