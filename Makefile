NAME = push_swap

LIBFT = libft

LIBFTM = libft/libft.a

CC = cc

CFLAGS = -Wall -Wextra -Werror

CFILES_1 =	push_swap.c \
			operations_a.c \
            operations_b.c \
			operations_ab.c \
			ps_seperations.c \
			ps_utils.c \
			ps_is_utils.c \
			ps_free.c \
			ps_sorts.c

OBJS_1 = $(CFILES_1:.c=.o)

$(NAME): $(OBJS_1)
	@make -C $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJS_1) $(LIBFTM) -o $(NAME)

all: $(NAME)

clean:
		@rm -f $(OBJS_1)
		@make clean -C $(LIBFT)

fclean: clean
		@make fclean -C $(LIBFT)
		@rm -rf $(NAME)

re: fclean all