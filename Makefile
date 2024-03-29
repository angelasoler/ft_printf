NAME=libftprintf.a

MAKE_LIBFT=cd libft && make

LIBFT_INTO_LIBFTPRINTF=cp libft.a $(NAME)

FCLEAN_LIBFT=cd libft && make fclean

CC=gcc

CFLAGS=-Wall -Werror -Wextra

SRC=ft_printf.c ft_printf_other_convs.c ft_printf_int_convs.c

FTPRINTF_OBJ=$(SRC:.c=.o)

BONUS_SRC=ft_printf_bonus.c ft_printf_other_convs_bonus.c \
		  ft_printf_int_convs_bonus.c

BONUS_OBJ=$(BONUS_SRC:.c=.o)

all: $(NAME)

$(NAME): $(FTPRINTF_OBJ)
	@$(MAKE_LIBFT)
	@$(LIBFT_INTO_LIBFTPRINTF)
	@$(FCLEAN_LIBFT)
	@ar -r $(NAME) $(FTPRINTF_OBJ)

bonus: $(BONUS_OBJ)
	@make FTPRINTF_OBJ="$(BONUS_OBJ)"

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

re: fclean all

fclean: clean
	@rm -rf $(NAME)

clean:
	@rm -rf *.o
