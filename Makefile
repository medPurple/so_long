NAME		=	so_long
CC			=	cc
FLAGS		=	-Wall -Wextra -Werror
LFT			=	lib/libft_perso/libft.a
INC			=	-I./include -I./lib/libft_perso -I./lib/minilibx-linux
LIB			=	-L./lib/libft_perso -lft -lXext -lX11 -lm -lbsd -L./lib/minilibx-linux -lmlx 
OBJ			=	$(SRC:.c=.o)
SRC			=  srcs/map/map.c \
		 	   srcs/map/verification.c \
		 	   srcs/player/player.c \
			   srcs/utils/error.c \
			   srcs/utils/verification_utils.c \
			   srcs/player/player.c \
			   srcs/window/ft_init.c \

all:		$(MLX) $(LFT) $(NAME)

$(NAME):	$(OBJ)
			$(CC) $(FLAGS) -o $@ $^ main.c $(LIB)


$(LFT):		
			@echo " [ .. ] | Compiling libft.."
			@make -s -C lib/libft_perso
			@echo " [ OK ] | Libft ready!"


%.o:		src/%.c
			$(CC) $(FLAGS) $(INC) -o $@ -c $<

clean:
			@make -s $@ -C lib/libft_perso
			@rm -rf $(OBJ)
			
fclean:		clean
			@make -s $@ -C lib/libft_perso
			@rm -rf $(NAME)
			
re:			fclean all

.PHONY:		all clean fclean re
