// int x_printf(char *fmt, ...)
// {
// 	va_list ap;
// 	char c;
// 	char *s;
// 	int d;

// 	va_start(ap, *fmt);
// 	while(*fmt)
// 	{
// 		if (*fmt == '%')
// 		{
// 			*fmt++;
// 			if (*fmt == 'c')
// 			if (*fmt == 's')
// 			if (*fmt == 'p')
// 			if (*fmt == 'd')
// 			if (*fmt == 'i')
// 			if (*fmt == 'u')
// 			if (*fmt == 'x')
// 			if (*fmt == 'X')
// 			if (*fmt == '%')
// 		}
// 		else if
// 		{
// 			//join char to temp cha*
// 			fmt++;
// 		}
// 	}
// 	// print with write
// }
#include <stdio.h>
int	main(void)
{
	int x; 
	x = printf("%x\n", 429496729);
	printf("%i\n", x);
	printf("%x\n", x);
}
