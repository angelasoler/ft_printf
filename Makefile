NAME=libftprinf.a

CC=gcc

CFLAGS=-Wall -Werror -Wextra

SRC=ft_printf.c

OBJ=$(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	cd libft && make
	@ar -r $(NAME) $(OBJ)

%.o: %.c ft_printf.h 
	@$(CC) $(CFLAGS) -c $< -o $@

re: fclean all

fclean: clean
	rm -rf $(NAME)

clean:
	rm -rf *.o
