/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmessmer <wmessmer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 18:04:43 by wmessmer          #+#    #+#             */
/*   Updated: 2023/01/13 17:29:18 by wmessmer         ###   ########.fr       */
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
# include <math.h>

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

# define PLAYER_IMG "img_xpm/player_right_static.xpm"
# define ENEMY_IMG1 "img_xpm/enemy_i.xpm"
# define COLLECTABLE_IMG1 "img_xpm/collectible.xpm"




/*Structures*/


typedef struct s_map
{
	int	col;
	int	row;
	int	exit_count;
	int	start_count;
	int	collectible_count;
	int end_game_ok;
}	t_map;

typedef struct s_player
{
	void	*w_player_static;
	void	*w_player_mover1;
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
}	t_player;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	
	void	*ground;
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
	void	*img_start;
	

	char	**map; //ok
	int		player_x;
	int		player_y;
	int		img_width;//
	int		img_height;//
	int		win_width;//
	int		win_height;//
	int		moves;//
	int		collected;//
	int		collectable;//
	int		end_game_ok;//
	int		collectable_valid;//
	int 	exit_x;
	int		exit_y;
	t_map	mappy;
}	t_game;

/*map*/
int map_check(t_game *game, char *file);
void map_init(t_game *game);
char **map_generation(char *file);
void map_final_init(t_game *game);


/*verif*/
int ber_extension(char *file);
int content_verification(char **map);
int wall_verification(t_game *game, char *path);
int content_nb_verification(t_game *game);

/* backtracking*/
int map_verification_path(t_game *game);
int pathfinder(t_game *game,int i, int j,int **grid);
int **blanktab(t_game *game);
int exit_exist(t_game *game, int **grid);

/*utils*/
int nb_ligne(char *path);
int count_size_line(char *line);
int map_error(int i);
int mlx_error(int i);
void transfet_map_to_game(char **map,t_game *game,char *path);
void exit_init(t_game *game);
void printmap(int **map_copy, int r, int c);

/*mlx*/
int window_initialisation(t_game *window);
void obstacle_to_img(t_game *game);
void ground_to_img(t_game *game);
void other_to_img(t_game *game);



/*player*/
void player_init(t_game *player);
void map_actualisation(t_game *game, int lx, int ly);

/*img*/
void image_initialisation(t_game *game);
int render_maps(t_game *game);
void img_parsing(t_game *game, int i, int j);
void define_obstacle(t_game *game, int i, int j);
void random_floor(t_game *game, int i, int j);

void	loop_images(t_game game);
int	handle_resize(t_game *data);
int	handle_keypress(int keysym, t_game *data);
int	handle_btnrealease(t_game *data);

/* action */

int  ft_action_keyboard(int key, t_game *game);
void ft_move_player(t_game *game, int y, int x);
int	ft_mouse(t_game *game);

/* end */
int game_victory(t_game *game);
int game_close(t_game *game);

/* free */
void free_all_game(t_game *game);
void ft_img_destroyer(t_game *game);
void ft_map_destroyer(t_game *game);
void ft_map_destroyer_int(int **map,t_game *game);

#endif
