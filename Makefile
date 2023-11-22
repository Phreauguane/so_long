NAME		=	so_long

FLAG		=	-Wall -Wextra -Werror

LIBFT_PATH	=	./libft/

LIBFT_FILE	=	libft.a

MLX_FILE	=	libmlx.a

LIBFT_LIB	=	$(addprefix $(LIBFT_PATH), $(LIBFT_FILE))

MLX_FLAG	=	-lX11 -lXext

MLX_PATH	=	./minilibx/

MLX_LIB		=	$(addprefix $(MLX_PATH), $(MLX_FILE))

MLX_EX		=	$(MLX_LIB) $(MLX_FLAG)

C_FILE		=	main.c		\
				game.c		\
				map.c		\
				verif_map.c	\
				draw.c		\
				draw2.c		\
				textures.c	\
				utils.c

SRC_DIR		=	./src/

INC_DIR		=	./includes/

SRC			=	$(addprefix $(SRC_DIR),$(C_FILE))

OBJ			=	$(SRC:.c=.o)

.c.o:
	@$(CC) $(FLAG) -c $< -o $@

all: $(NAME)

lib:
	@echo "\033[0;33m\nCOMPILING $(LIBFT_PATH)"
	@make -C $(LIBFT_PATH)
	@echo "\033[1;32m$(LIBFT_FILE) created"

valgrind: lib mlx $(OBJ)
	@echo "\033[0;33m\nCOMPILING SO_LONG..."
	@cc -g3 $(OBJ) $(LIBFT_LIB) $(MLX_EX) -o $(NAME)
	@echo "\033[1;32m$(NAME) executable created"

mlx:
	@echo "\033[0;33m\nCOMPILING $(MLX_PATH)..."
	@make -sC $(MLX_PATH)
	@echo "\033[1;32m$(MLX_FILE) created"

$(NAME): lib mlx $(OBJ)
	@echo "\033[0;33m\nCOMPILING SO_LONG..."
	@cc $(OBJ) $(LIBFT_LIB) $(MLX_EX) -o $(NAME)
	@echo "\033[1;32m$(NAME) executable created"

clean:
	@echo "\033[0;31mDeleting Obj file in $(MLX_PATH)..."
	@make clean -sC $(MLX_PATH)
	@echo "\033[0;31mDeleting Obj file in $(LIBFT_PATH)..."
	@make clean -sC $(LIBFT_PATH)
	@echo "\033[1;32mDone"
	@echo "\033[0;31mDeleting Obj file in ./src/..."
	@rm -f $(OBJ)
	@echo "\033[1;32mDone"

fclean: clean
	@echo "\033[0;31mDeleting so_long executable..."
	@rm -f $(NAME)
	@make fclean -C $(LIBFT_PATH)
	@echo "\033[1;32mDone"

re: fclean all

.PHONY: all clean fclean re
