#include "x_printf.h"

int	unsigned_long_to_hexa(unsigned long n)
{
	char	temp[20];
	int		i;

	i = 0;
	while (n)
	{
		if (n % 16 > 9)
			temp[i] = (n % 16) + 87;
		else
			temp[i] = (n % 16) + 48;
		n /= 16;
		i++;
	}
	while (i)
	{
		i--;
		write(1, &temp[i], 1);
	}
	return (ft_strlen(temp) - 1);
}

int	ft_printf_p(unsigned long a)
{
	write(1, "0x", 2);
	return (unsigned_long_to_hexa(a) + 2);
}

#include <stdio.h>
int	ft_printf_address(char *s, ...)
{
	va_list	ap;
	unsigned long	a;
	int		result;

	result = 0;
	va_start(ap, s);
	while(*s)
	{
		if (*s == '%')
		{
			s++;
			a = va_arg(ap, unsigned long);
			result += ft_printf_p(a);
			printf("\n%ld\n", a);
			printf("%lx\n", a);
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
	int	d;
	int	x;
	// unsigned long	address;

	d = -2147483648;
	// address = (unsigned long)&d;
	// printf("%lx\n", address);
	printf("     ____ft_____\n");
	x = ft_printf_address("My int address is: %p\n", &d);
	printf("%i\n     ____ORIGINAL______\n", x);
	x = printf("My int address is: %p\n", &d);
	printf("%i\n", x);

	printf("     ____ft_____\n");
	x = ft_printf_address("My return address is: %p\n", &x);
	printf("%i\n     ____ORIGINAL_____\n", x);
	x = printf("My return address is: %p\n", &x);
	printf("%i\n", x);
	unsigned_long_to_hexa(140727044389688);
}
// int	main()
// {
// 	int	d;
// 	unsigned long x;

// 	x = (unsigned long)&d;
// 	printf("%p\n", &d);
// 	printf("%lx\n", x);
// }
