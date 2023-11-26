NAME=push_swap
NAME_BONUS=checker
CC= gcc
#CFLAGS=-Wall -Werror -Wextra -fsanitize=address -g3
CFLAGS=-Wall -Werror -Wextra -g3
FUNCTION=	main.c \
			ft_strict_atoi.c \
			ft_errors.c \
			ft_swap.c \
			ft_push.c \
			ft_rotate.c \
			ft_reverse_rotate.c \
			push_swap_utils.c \
			ft_count_movs.c \
			ft_order.c

FUNCTION_BONUS=	checker.c

LIB= libft/libft.a

OBJ=$(FUNCTION:%.c=%.o)

OBJ_BONUS=$(FUNCTION_BONUS:%.c=%.o)

all: $(NAME)

debug: CFLAGS+=-fsanitize=address -g3
debug: CFLAGS+=-g3
debug: all

$(NAME): $(OBJ)
	$(MAKE) bonus -sC ./libft
	@echo 
	$(CC) $(OBJ) $(LIB) -o $(NAME) -g3
#	$(CC) $(OBJ) $(LIB) -o $(NAME) -fsanitize=address -g3

$(NAME_BONUS): $(OBJ_BONUS)
	$(MAKE) bonus -sC ./libft
	$(CC) $(OBJ_BONUS) $(LIB) -o $(NAME_BONUS)

bonus: $(NAME_BONUS)

%.o: %.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm -rf $(OBJ)
	rm -rf $(OBJ_BONUS)
	$(MAKE) clean -sC ./libft

fclean: clean
	rm -rf $(NAME)
	rm -rf $(NAME_BONUS)
	$(MAKE) fclean -sC ./libft

re: fclean all
.PHONY: clean fclean re all