NAME			=	so_long
CC				=	gcc
CFLAGS			=	-Wall -Wextra -Werror
AR				=	ar
ARFLAGS 		=	rcs
RM				=	rm -rf

SRC				=		main.c \
						checks.c \
						map_checks.c \
						map_checks2.c \
						display_map.c \
						extras_map.c \
						exit.c 

LIBFT_PATH		=	./libft
LIBFT			=	$(LIBFT_PATH)/libft.a

MINILIBX_PATH	=	./minilibx
MINILIBX	    =   $(MINILIBX_PATH)/libmlx.a

all:				$(NAME)

$(NAME):			$(LIBFT) MLX
					$(CC) $(CFLAGS) $(SRC) $(LIBFT) $(MINILIBX) -framework OpenGL -framework AppKit -o $(NAME)

$(LIBFT):
					make -C $(LIBFT_PATH) all

MLX:
					make -C $(MINILIBX_PATH) all

clean:
					make -C $(LIBFT_PATH) clean
					make -C $(MINILIBX_PATH) clean

fclean:				clean
					make -C $(LIBFT_PATH) fclean
					$(RM) $(NAME)

re:					fclean all

.PHONY:				all clean fclean re libft
