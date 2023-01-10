NAME		=	so_long
CC			=	@cc
FLAGS		=	-Wall -Wextra -Werror -g3
LFT			=	lib/libft_perso/libft.a
INC			=	-I./include -I./lib/libft_perso -I./lib/minilibx-linux
LIB			=	-L./lib/libft_perso -lft -lXext -lX11 -lm -lbsd -L./lib/minilibx-linux -lmlx 
OBJ			=	$(SRC:.c=.o)
SRC			=  srcs/map/map.c \
		 	   srcs/map/verification.c \
			   srcs/map/backtracking.c \
			   srcs/utils/error.c \
			   srcs/utils/verification_utils.c \
			   srcs/utils/free_all_game.c \
			   srcs/window/ft_init.c \
			   srcs/game/ft_game.c \
			   srcs/game/player.c \

all:		$(MLX) $(LFT) $(NAME)

$(NAME):	$(OBJ)
			$(CC) $(FLAGS) -o $@ $^ main.c $(LIB)
			@echo "\nCompilation so_long [OK]\n"


$(LFT):		
			@make -s -C lib/libft_perso

%.o:		$(CC) $(FLAGS) $(INC) -o $@ -c $<

clean:
			@make -s $@ -C lib/libft_perso
			@rm -rf $(OBJ)
			
fclean:		clean
			@make -s $@ -C lib/libft_perso
			@rm -rf $(NAME)
			
re:			fclean all

.PHONY:		all clean fclean re
