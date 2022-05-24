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

#endif
