#include "ft_printf.h"


int	ft_printf_int(int d)
{
	char	*n;
	int		n_len;

	n = ft_itoa(d);
	n_len = ft_strlen(n);
	write(1, n, n_len);
	return (n_len - 1);
}

int	unsigned_long_to_hexa(unsigned long n)
{
	char	temp[20];
	int		i;

	write(1, "0x", 2);
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
	return (ft_strlen(temp) + 1);
}

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

int	ft_printf_char(char c, char *s)
{
	if (s)
	{
		write(1, s1, ft_strlen(s1));
		return (ft_strlen(s1) - 1)
	}
	else
	{
		c = va_arg(ap, char);
		write(1, &c, 1);
		return (1);
	}
	return (0);
}

int	int_to_hexa(unsigned int n, char c)
{
	char	temp[8];
	int		i;
	
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
	while (i)
	{
		i--;
		write(1, &temp[i], 1);
	}
	return (ft_strlen(temp) - 1);
}
