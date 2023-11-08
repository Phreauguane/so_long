CC = cc
NAME = libft.a

SRC = 	ft_atoi.c ft_isascii.c ft_memcmp.c	\
		ft_putendl_fd.c ft_strdup.c ft_strlen.c \
		ft_strtrim.c ft_bzero.c ft_isdigit.c 	\
		ft_memcpy.c ft_putnbr_fd.c 				\
		ft_striteri.c ft_strmapi.c ft_substr.c 	\
		ft_calloc.c ft_isprint.c ft_memmove.c 	\
		ft_putstr_fd.c ft_strjoin.c 			\
		ft_strncmp.c ft_tolower.c ft_isalnum.c 	\
		ft_itoa.c ft_memset.c ft_split.c 		\
		ft_strlcat.c ft_strnstr.c ft_toupper.c 	\
		ft_isalpha.c ft_memchr.c 				\
		ft_putchar_fd.c ft_strchr.c 			\
		ft_strlcpy.c ft_strrchr.c print_arg.c	\
		args_to_str.c ft_itoa_base.c 			\
		ft_printf.c	ft_straddchr.c 				\
		ft_strcat_malloc.c get_next_line.c		\
		get_next_line_utils.c

BONUS = ft_lstadd_back_bonus.c 	\
		ft_lstclear_bonus.c 	\
		ft_lstiter_bonus.c 		\
		ft_lstmap_bonus.c 		\
		ft_lstsize_bonus.c 		\
		ft_lstadd_front_bonus.c \
		ft_lstdelone_bonus.c 	\
		ft_lstlast_bonus.c 		\
		ft_lstnew_bonus.c

OBJ = $(SRC:.c=.o)
BONUS_OBJ = $(BONUS:.c=.o)
CFLAGS = -Wall -Werror -Wextra

all : $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -o $@ -c $<

$(NAME) : $(OBJ)
	ar rcs $(NAME) $(OBJ)

bonus : $(OBJ) $(BONUS_OBJ)
	ar rcs $(NAME) $(OBJ) $(BONUS_OBJ)

clean :
	rm -f $(OBJ) $(BONUS_OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all
