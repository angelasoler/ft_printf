#ifndef FT_PRINTF_H
# include <stdarg.h>
# include "./includes/libft.h"
# include <unistd.h>
# define FT_PRINTF_H

typedef struct s_vars
{
	char			*s;
	char			c;
	int				sn;
	unsigned int	un;
	unsigned long	address;
}	t_vars;

int	ft_printf(const char *s, ...);

int	ft_printf_int(int d);

int	unsig_long_to_hexa(unsigned long n);

int	unsig_putnbr(unsigned int n);

int	ft_printf_char(char c, char *s);

int	int_to_hexa(unsigned int n, char c);

#endif
