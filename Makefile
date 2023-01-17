NAME		=	so_long
CC			=	@cc
FLAGS		=	-Wall -Wextra -Werror -g3
LFT			=	lib/libft_perso/libft.a
LIB			=	-L./lib/libft_perso -lft -lXext -lX11 -lm -lbsd
PATH_MLX	= 	lib/minilibx-linux/
MLX			=	$(PATH_MLX)libmlx.a
INC			=	-I./include -I./lib/libft_perso -I $(PATH_MLX)

OBJ			=	$(SRC:.c=.o)
OBJB		=	$(SRCB:.c=.o)

SRC			=  srcs/map/map.c \
		 	   srcs/map/verification.c \
			   srcs/map/backtracking.c \
			   srcs/utils/error.c \
			   srcs/utils/verification_utils.c \
			   srcs/utils/free_all_game.c \
			   srcs/window/ft_init.c \
			   srcs/window/xpm_to_image.c \
			   srcs/window/key.c			\
			   srcs/window/math_on_image.c \
			   srcs/game/ft_game.c \
			   srcs/game/player.c \
   			   srcs/game/ft_animation_player.c \


SRCB		=  srcs/map/map.c \
		 	   srcs/map/verification_bonus.c \
			   srcs/map/backtracking.c \
			   srcs/utils/error.c \
			   srcs/utils/verification_utils.c \
			   srcs/utils/free_all_game_bonus.c \
			   srcs/window/ft_init_bonus.c \
			   srcs/window/xpm_to_image.c \
			   srcs/window/key.c			\
			   srcs/window/math_on_image.c \
			   srcs/game/ft_game.c \
			   srcs/game/player_bonus.c \
			   srcs/game/ft_animation_player_bonus.c \
			   srcs/game/ft_enemy.c \
			   srcs/game/ft_move_enemy.c \

all:		$(MLX) $(LFT) $(NAME)

$(NAME):	$(OBJ)
			$(CC) $(FLAGS) -o $@ $^ so_long.c $(LIB) $(MLX)
			@echo "\nCompilation so_long [OK]\n"

$(LFT):		
			@make -s -C lib/libft_perso
$(MLX):
			@${MAKE} -s -C $(PATH_MLX)
			@echo "\nCompilation mlx [OK]"

%.o:		$(CC) $(FLAGS) $(INC) -o $@ -c $< -I $(PATH_MLX) 

bonus:		$(MLX) $(LFT) $(OBJB)
			$(CC) $(FLAGS) -o $@ $^ so_long_bonus.c $(LIB) $(MLX)
			@echo "\nCompilation so_long_bonus [OK]\n"

clean:
			@make -s $@ -C lib/libft_perso
			@${MAKE} -C $(PATH_MLX) clean
			@rm -rf $(OBJ) $(OBJB)
			
fclean:		clean
			@make -s $@ -C lib/libft_perso
			@rm -rf $(NAME) bonus
			
re:			fclean all

.PHONY:		all clean fclean re
