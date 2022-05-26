#include "../ft_printf.h"
#include "../includes/libft.h"
#include <stdio.h>

int	main(void)
{
	// unsigned int	un = -9223372036854775808;
	int		int_return;

	// ft_printf("\n\n      -------Ft------\n\n");
	// int_return = ft_printf("hex lowercase: %x\n", 9223372036854775807);
	// ft_printf("%d\n", int_return);
	// int_return = ft_printf("hex uppercase: %X\n", 9223372036854775807);
	// ft_printf("%d\n", int_return);
	// int_return = printf("hex lowercase: %x\n", 9223372036854775807);
	// ft_printf("%d\n", int_return);
	// int_return = printf("hex uppercase: %X\n", 9223372036854775807);
	// ft_printf("%d\n", int_return);
	ft_printf("\n\n      -------Ft------\n\n");
	int_return = ft_printf("hex lowercase: %x\n", 0);
	ft_printf("%d\n", int_return);
	int_return = ft_printf("hex uppercase: %X\n", 0);
	ft_printf("%d\n", int_return);
	int_return = printf("hex lowercase: %x\n", 0);
	ft_printf("%d\n", int_return);
	int_return = printf("hex uppercase: %X\n", 0);
	ft_printf("%d\n", int_return);
}

