/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmessmer <wmessmer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 18:04:43 by wmessmer          #+#    #+#             */
/*   Updated: 2023/01/10 11:37:40 by wmessmer         ###   ########.fr       */
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

# define IMG_SIZE 48
# define COLOR_RESET "\e[0m"
# define RED "\e[0;31m"
# define GRN "\e[0;32m"
# define YEL "\e[0;33m"
# define MAG "\e[0;35m"
# define BLU "\e[0;34m"
# define GROUND_IMG "img_xpm/ML_game/ground.xpm"
# define WALL_IMG "img_xpm/ML_game/wall.xpm"
# define EXIT_IMG_C "img_xpm/ML_game/exit_c.xpm"
# define EXIT_IMG_O "img_xpm/ML_game/exit_o.xpm"
# define PLAYER_IMG "img_xpm/ML_game/plqyer.xpm"
# define ENEMY_IMG1 "img_xpm/ML_game/enemy1.xpm"
# define COLLECTABLE_IMG1 "img_xpm/ML_game/collectable1.xpm"




/*Structures*/
typedef struct s_game
{
	void	*mlx;
	void	*win;
	void	*img_ground;
	void	*img_wall;
	void	*enemy_img1;
	void	*img_player;
	void	*img_collectable;
	void	*img_collectable2;
	void	*img_collectable3;
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
}	t_game;

typedef struct s_map
{
	int	col;
	int	row;
	int	exit_count;
	int	start_count;
	int	collectible_count;
	int end_game_ok;
}	t_map;

/*map*/
int map_check(char **map, char *file);
void map_init(t_map *map);
char **map_generation(char *file);
t_game map_final_init(t_game *map,t_map info);


/*verif*/
int ber_extension(char *file);
int content_verification(char **map);
int wall_verification(char **map, t_map *map_info, char *path);
int content_nb_verification(char **map, t_map *map_info);

/* backtracking*/
int map_verification_path(t_game *game,t_map *map);
int pathfinder(t_game *game,int i, int j,int **grid,t_map *map);
int **blanktab(t_map *map);

/*utils*/
int nb_ligne(char *path);
int count_size_line(char *line);
int map_error(int i);
int mlx_error(int i);
t_map transfet_map_to_game(char **map,t_map *map_info,char *path);
/*mlx*/
int window_initialisation(t_game *window);

/*player*/
void player_init(t_game *player);

/*img*/
void image_initialisation(t_game *game);
int render_maps(t_game *game);
void img_parsing(t_game *game, int i, int j);

void	loop_images(t_game game);
int	handle_resize(t_game *data);
int	handle_keypress(int keysym, t_game *data);
int	handle_btnrealease(t_game *data);

/* action */

int  ft_action_keyboard(int key, t_game *game);
void ft_move_player(t_game *game, int y, int x);

/* end */
int game_victory(t_game *game);
int game_close(t_game *game);

/* free */
void free_all_game(t_game *game);
void ft_img_destroyer(t_game *game);
void ft_map_destroyer(t_game *game);

#endif
