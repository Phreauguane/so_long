NAME		= so_long

MAKE_LFT	= make all -C libft

MAKE_MLX	= make all -C minilibx

CLEAN_LFT	= make clean -C libft

CLEAN_MLX	= make clean -C minilibx

FCLEAN_LFT	= make fclean -C libft

FCLEAN_MLX	= make fclean -C minilibx

CC			= cc

CFLAGS		= -Wall -Wextra -Werror 

CPARAMS		= -I include -L libft -L minilibx -l ft -l mlx

SRCS		= src/main.c

all			: $(NAME)

$(NAME)		:
	$(MAKE_LFT) && $(MAKE_MLX)
	$(CC) $(CFLAGS) $(CPARAMS) $(SRCS) -o $(NAME)

clean		:
	$(CLEAN_LFT) && $(CLEAN_MLX)

fclean		: clean
	$(FCLEAN_LFT) && $(FCLEAN_MLX)
	rm -f $(NAME)

re			: fclean all