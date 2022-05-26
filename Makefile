NAME=libftprintf.a

MAKE_LIBFT=cd libft && make

LIBFT_INTO_LIBFTPRINTF=cp libft.a $(NAME)

FCLEAN_LIBFT=cd libft && make fclean

CC=gcc

CFLAGS=-Wall -Werror -Wextra

SRC=ft_printf.c ft_printf_other_convs.c ft_printf_int_convs.c

OBJ=$(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(MAKE_LIBFT)
	$(LIBFT_INTO_LIBFTPRINTF)
	$(FCLEAN_LIBFT)
	ar -r $(NAME) $(OBJ)

%.o: %.c ft_printf.h 
	$(CC) -g $(CFLAGS) -c $< -o $@

re: fclean all

fclean: clean
	@rm -rf $(NAME)

clean:
	@rm -rf *.o
