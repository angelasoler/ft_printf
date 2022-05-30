NAME=../libft.a

CC=gcc

CFLAGS=-Wall -Werror -Wextra

SRC=ft_itoa.c ft_strlen.c ft_toupper.c

OBJ=$(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@ar -r $(NAME) $(OBJ)

%.o: %.c ../includes/libft.h 
	@$(CC) $(CFLAGS) -c $< -I../includes -o $@

re: fclean all

fclean: clean
	rm -rf $(NAME)

clean:
	rm -rf *.o
