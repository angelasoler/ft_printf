#include "ft_printf.h"
#include "./includes/libft.h"
#include <stdio.h>

int	main(void)
{
	char	s[] = "str";
	char	c = 'c';
	int		n = -4546521;
	unsigned int un= -45621;
	int		int_return;

	ft_printf("\n\n      -------Ft------\n\n");
	int_return = ft_printf("hello world %s\n", s);
	ft_printf("%d\n", int_return);
	int_return = ft_printf("char convention: %c\n", c);
	ft_printf("%d\n", int_return);
	int_return = ft_printf("int convention with d: %d\n", n);
	ft_printf("%d\n", int_return);
	int_return = ft_printf("int convention with i: %d\n", n);
	ft_printf("%d\n", int_return);
	int_return = ft_printf("unsigned int: %u\n", un);
	ft_printf("%d\n", int_return);
	int_return = ft_printf("hex lowercase: %x\n", un);
	ft_printf("%d\n", int_return);
	int_return = ft_printf("hex uppercase: %X\n", un);
	ft_printf("%d\n", int_return);
	int_return = ft_printf("address: %p\n", s);
	ft_printf("%d\n", int_return);
	int_return = ft_printf("many %% together: %%%% %% %%% somehing else\n");
	ft_printf("%d\n", int_return);
	ft_printf("\n\n      -------Original------\n\n");
	int_return = printf("hello world %s\n", s);
	printf("%d\n", int_return);
	int_return = printf("char convention: %c\n", c);
	ft_printf("%d\n", int_return);
	int_return = printf("int convention with d: %d\n", n);
	printf("%d\n", int_return);
	int_return = printf("int convention with i: %d\n", n);
	printf("%d\n", int_return);
	int_return = printf("unsigned int: %u\n", un);
	printf("%d\n", int_return);
	int_return = printf("hex lowercase: %x\n", un);
	printf("%d\n", int_return);
	int_return = printf("hex uppercase: %X\n", un);
	printf("%d\n", int_return);
	int_return = printf("address: %p\n", s);
	printf("%d\n", int_return);
	int_return = printf("many %% together: %%%% %% %% somehing else\n");
	printf("%d\n", int_return);
}

