#include "ft_printf.h"

void	write_negative_hex(int count, int i, char *s, char c)
{
	if (s[0] == '9')
		s[0] = 'a';
	else
		s[0] += 1;
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
		if (c == 'X')
			s[i] = ft_toupper(s[i]);
		write(1, &s[i], 1);
	}
}

int	signed_int_to_hexa(int n, char c)
{
	char	temp[8];
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
		n /= 16;
		i++;
	}
	count -= i;
	write_negative_hex(count, i, temp, c);
	return (7);
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

