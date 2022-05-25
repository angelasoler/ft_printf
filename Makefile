NAME=libftprintf.a

CC=gcc

CFLAGS=-Wall -Werror -Wextra

SRC=ft_printf.c ft_printf_utils.c

OBJ=$(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@cd libft && make
	@cp libft.a $(NAME)
	@cd libft && make fclean
	@ar -r libftprintf.a $(NAME) $(OBJ)

%.o: %.c ft_printf.h 
	@$(CC) $(CFLAGS) -c $< -o $@

re: fclean all

fclean: clean
	@rm -rf $(NAME)

clean:
	@rm -rf *.o
