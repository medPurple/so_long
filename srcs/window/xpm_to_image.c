/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xpm_to_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmessmer <wmessmer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 13:28:19 by wmessmer          #+#    #+#             */
/*   Updated: 2023/01/20 13:48:50 by wmessmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	ground_to_img(t_game *game)
{
	game->img_ground1 = mlx_xpm_file_to_image(game->mlx, \
		GROUND_IMG1, &game->img_width, &game->img_height);
	game->img_ground2 = mlx_xpm_file_to_image(game->mlx, \
		GROUND_IMG2, &game->img_width, &game->img_height);
	game->img_ground3 = mlx_xpm_file_to_image(game->mlx, \
		GROUND_IMG3, &game->img_width, &game->img_height);
	game->img_ground4 = mlx_xpm_file_to_image(game->mlx, \
		GROUND_IMG4, &game->img_width, &game->img_height);
}

void	obstacle_to_img(t_game *game)
{
	game->img_wall_side = mlx_xpm_file_to_image(game->mlx, \
		WALL_IMG_SIDE, &game->img_width, &game->img_height);
	game->img_wall_front = mlx_xpm_file_to_image(game->mlx, \
		WALL_IMG_TOP, &game->img_width, &game->img_height);
	game->img_obstacle = mlx_xpm_file_to_image(game->mlx, \
		OBSTACLE, &game->img_width, &game->img_height);
}

void	player_to_img(t_game *game)
{
	game->img_player = mlx_xpm_file_to_image(game->mlx, \
		D_PLAYER_S, &game->img_width, &game->img_height);
	game->play.w_player_static = mlx_xpm_file_to_image(game->mlx, \
		W_PLAYER_S, &game->img_width, &game->img_height);
	game->play.w_player_move1 = mlx_xpm_file_to_image(game->mlx, \
		W_PLAYER_M1, &game->img_width, &game->img_height);
	game->play.w_player_move2 = mlx_xpm_file_to_image(game->mlx, \
		W_PLAYER_M2, &game->img_width, &game->img_height);
	game->play.s_player_static = mlx_xpm_file_to_image(game->mlx, \
		S_PLAYER_S, &game->img_width, &game->img_height);
	game->play.s_player_move1 = mlx_xpm_file_to_image(game->mlx, \
		S_PLAYER_M1, &game->img_width, &game->img_height);
	player_to_img_2(game);
}

void	player_to_img_2(t_game *game)
{
	game->play.s_player_move2 = mlx_xpm_file_to_image(game->mlx, \
		S_PLAYER_M2, &game->img_width, &game->img_height);
	game->play.a_player_static = mlx_xpm_file_to_image(game->mlx, \
		A_PLAYER_S, &game->img_width, &game->img_height);
	game->play.a_player_move1 = mlx_xpm_file_to_image(game->mlx, \
		A_PLAYER_M1, &game->img_width, &game->img_height);
	game->play.a_player_move2 = mlx_xpm_file_to_image(game->mlx, \
		A_PLAYER_M2, &game->img_width, &game->img_height);
	game->play.d_player_static = mlx_xpm_file_to_image(game->mlx, \
		D_PLAYER_S, &game->img_width, &game->img_height);
	game->play.d_player_move1 = mlx_xpm_file_to_image(game->mlx, \
		D_PLAYER_M1, &game->img_width, &game->img_height);
	game->play.d_player_move2 = mlx_xpm_file_to_image(game->mlx, \
		D_PLAYER_M2, &game->img_width, &game->img_height);
}

void	other_to_img(t_game *game)
{
	game->img_collectable = mlx_xpm_file_to_image(game->mlx, \
		COLLECTABLE_IMG1, &game->img_width, &game->img_height);
	game->enemy_img1 = mlx_xpm_file_to_image(game->mlx, \
		ENEMY_IMG1, &game->img_width, &game->img_height);
	game->img_exit_close = mlx_xpm_file_to_image(game->mlx, \
		EXIT_IMG_C, &game->img_width, &game->img_height);
	game->img_exit_open = mlx_xpm_file_to_image(game->mlx, \
		EXIT_IMG_O, &game->img_width, &game->img_height);
	game->img_exit_open2 = mlx_xpm_file_to_image(game->mlx, \
		EXIT_IMG_O2, &game->img_width, &game->img_height);
}
