/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmessmer <wmessmer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 18:04:43 by wmessmer          #+#    #+#             */
/*   Updated: 2023/01/24 10:14:38 by wmessmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../lib/minilibx-linux/mlx.h"
# include "../lib/minilibx-linux/mlx_int.h"
# include "../lib/libft_perso/include/libft.h"
# include <X11/keysym.h>
# include <X11/X.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <time.h>

# define IMG_SIZE 48
# define COLOR_RESET "\e[0m"
# define RED "\e[0;31m"
# define GRN "\e[0;32m"
# define YEL "\e[0;33m"
# define MAG "\e[0;35m"
# define BLU "\e[0;34m"
# define GROUND_IMG1 "img_xpm/ground_basic.xpm"
# define GROUND_IMG2 "img_xpm/ground_flower1.xpm"
# define GROUND_IMG3 "img_xpm/ground_flower2.xpm"
# define GROUND_IMG4 "img_xpm/ground_flower3.xpm"
# define WALL_IMG_SIDE "img_xpm/wall_side.xpm"
# define WALL_IMG_TOP "img_xpm/wall_top.xpm"
# define OBSTACLE "img_xpm/obstacle.xpm"
# define EXIT_IMG_C "img_xpm/exit_close.xpm"
# define EXIT_IMG_O "img_xpm/exit_open.xpm"
# define EXIT_IMG_O2 "img_xpm/exit_open_2.xpm"
# define PLAYER_IMG "img_xpm/player_right_static.xpm"
# define ENEMY_IMG1 "img_xpm/enemy_i.xpm"
# define COLLECTABLE_IMG1 "img_xpm/collectible.xpm"
# define W_PLAYER_S "img_xpm/player_back_static.xpm"
# define W_PLAYER_M1 "img_xpm/player_back_move1.xpm"
# define W_PLAYER_M2 "img_xpm/player_back_move2.xpm"
# define S_PLAYER_S "img_xpm/player_front_static.xpm"
# define S_PLAYER_M1 "img_xpm/player_front_move1.xpm"
# define S_PLAYER_M2 "img_xpm/player_front_move2.xpm"
# define A_PLAYER_S "img_xpm/player_left_static.xpm"
# define A_PLAYER_M1 "img_xpm/player_left_move1.xpm"
# define A_PLAYER_M2 "img_xpm/player_left_move2.xpm"
# define D_PLAYER_S "img_xpm/player_right_static.xpm"
# define D_PLAYER_M1 "img_xpm/player_right_move1.xpm"
# define D_PLAYER_M2 "img_xpm/player_right_move2.xpm"
# define IRIGHT_ENEMY_S "img_xpm/enemy_right_static.xpm"
# define IRIGHT_ENEMY_M1 "img_xpm/enemy_right_move1.xpm"
# define IRIGHT_ENEMY_M2 "img_xpm/enemy_right_move2.xpm"
# define ILEFT_ENEMY_S "img_xpm/enemy_left_static.xpm"
# define ILEFT_ENEMY_M1 "img_xpm/enemy_left_move1.xpm"
# define ILEFT_ENEMY_M2 "img_xpm/enemy_left_move2.xpm"
# define IFRONT_ENEMY_S "img_xpm/enemy_front_static.xpm"
# define IFRONT_ENEMY_M1 "img_xpm/enemy_front_move1.xpm"
# define IFRONT_ENEMY_M2 "img_xpm/enemy_front_move2.xpm"
# define IDOWN_ENEMY_S "img_xpm/enemy_back_static.xpm"
# define IDOWN_ENEMY_M1 "img_xpm/enemy_back_move1.xpm"
# define IDOWN_ENEMY_M2 "img_xpm/enemy_back_move2.xpm"

/*Structures*/

typedef struct s_map
{
	int		col;
	int		row;
	int		exit_count;
	int		start_count;
	int		collectible_count;
	int		end_game_ok;
}	t_map;

typedef struct s_player
{
	void	*w_player_static;
	void	*w_player_move1;
	void	*w_player_move2;
	void	*d_player_static;
	void	*d_player_move1;
	void	*d_player_move2;
	void	*a_player_static;
	void	*a_player_move1;
	void	*a_player_move2;
	void	*s_player_static;
	void	*s_player_move1;
	void	*s_player_move2;
	int		key_w;
	int		key_s;
	int		key_a;
	int		key_d;
}	t_play;

typedef struct s_enemy
{
	void	*left_enemy_s;
	void	*left_enemy_m1;
	void	*left_enemy_m2;
	void	*top_enemy_s;
	void	*top_enemy_m1;
	void	*top_enemy_m2;
	void	*right_enemy_s;
	void	*right_enemy_m1;
	void	*right_enemy_m2;
	void	*down_enemy_s;
	void	*down_enemy_m1;
	void	*down_enemy_m2;
	int		move;
	int		exist;
	int		x_enemy;
	int		y_enemy;
	int		frame_e;
}	t_enemy;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	void	*img_ground1;
	void	*img_ground2;
	void	*img_ground3;
	void	*img_ground4;
	void	*img_wall_side;
	void	*img_wall_front;
	void	*img_obstacle;
	void	*enemy_img1;
	void	*img_player;
	void	*img_collectable;
	void	*img_exit_close;
	void	*img_exit_open;
	void	*img_exit_open2;
	void	*img_start;
	int		frame_ex;
	char	**map;
	int		exit_loop;
	int		player_x;
	int		player_y;
	int		img_width;
	int		img_height;
	int		win_width;
	int		win_height;
	int		ground_case;
	int		moves;
	int		collected;
	int		collectable;
	int		end_game_ok;
	int		collectable_valid;
	int		exit_x;
	int		exit_y;
	t_map	mappy;
	t_enemy	enemy;
	t_play	play;
}	t_game;

/*map*/
int		map_check(t_game *game, char *file);
void	map_init(t_game *game, char *path);
char	**map_generation(char *file);
void	map_final_init(t_game *game);

/*verif*/
int		ber_extension(char *file);
int		content_verification(t_game *game);
int		wall_verification(t_game *game, char *path);
int		content_nb_verification(t_game *game);
void	verif_img_1(t_game *game);
void	verif_img_2(t_game *game);

/* backtracking*/
int		map_verification_path(t_game *game);
int		pathfinder(t_game *game, int i, int j, int **grid);
int		**blanktab(t_game *game);
int		exit_exist(t_game *game, int **grid);

/*utils*/
int		nb_ligne(char *path);
int		count_size_line(char *line);
int		map_error(int i);
int		mlx_error(int i);
void	error_image(t_game *game);
void	transfet_map_to_game(char **map, t_game *game, char *path);
void	exit_init(t_game *game);
void	printmap(int **map_copy, int r, int c);
void	img_init_base(t_game*game);
void	img_init_enemy(t_game *game);
void	img_init_player(t_game *game);

/*mlx*/
int		window_initialisation(t_game *window);
void	obstacle_to_img(t_game *game);
void	ground_to_img(t_game *game);
void	other_to_img(t_game *game);
void	move_actualisation(t_game *game);
void	player_to_img(t_game *game);
void	player_to_img_2(t_game *game);

/* animation*/
void	animate_w(t_game *game);
void	animate_s(t_game *game);
void	animate_a(t_game *game);
void	animate_d(t_game *game);
int		ft_render(t_game *game);
void	exit_animation(t_game *game);

/*player*/
void	player_init(t_game *player);
void	map_actualisation(t_game *game, int lx, int ly);

/*enemy*/
void	generate_enemy(t_game *game);
void	move_enemy(t_game *game);
void	move_left(t_game *game, int x, int y);
void	move_right(t_game *game, int x, int y);
void	move_up(t_game *game, int x, int y);
void	move_down(t_game *game, int x, int y);
void	enemy_to_img(t_game *game);
void	enemy_to_img_2(t_game *game);

/*img*/
void	image_initialisation(t_game *game);
int		render_maps(t_game *game);
void	img_parsing(t_game *game, int i, int j);
void	define_obstacle(t_game *game, int i, int j);
void	random_floor(t_game *game, int i, int j, int a);
void	verif_img_1(t_game *game);
void	verif_img_2(t_game *game);
void	img_verif_base(t_game*game);
void	img_verif_base_2(t_game *game);
void	img_verif_enemy(t_game *game);
void	img_verif_player(t_game *game);

/* action */
int		ft_action_keyboard(int key, t_game *game);
void	ft_move_player(t_game *game, int y, int x);
int		ft_mouse(t_game *game);

/* end */
int		game_victory(t_game *game);
int		game_close(t_game *game);
int		game_loose(t_game *game);

/* free */
void	free_all_game(t_game *game);
void	ft_img_destroyer(t_game *game);
void	img_clear_base(t_game*game);
void	img_clear_base_2(t_game *game);
void	img_clear_enemy(t_game *game);
void	img_clear_player(t_game *game);
void	ft_map_destroyer(t_game *game);
void	ft_map_destroyer_int(int **map, t_game *game);

#endif
