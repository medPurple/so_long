/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_img_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmessmer <wmessmer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 17:25:05 by wmessmer          #+#    #+#             */
/*   Updated: 2023/01/23 13:31:49 by wmessmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	img_init_base(t_game*game)
{
	game->img_ground1 = NULL;
	game->img_ground2 = NULL;
	game->img_ground3 = NULL;
	game->img_ground4 = NULL;
	game->img_wall_side = NULL;
	game->img_wall_front = NULL;
	game->img_obstacle = NULL;
	game->enemy_img1 = NULL;
	game->img_player = NULL;
	game->img_collectable = NULL;
	game->img_exit_close = NULL;
	game->img_exit_open = NULL;
	game->img_exit_open2 = NULL;
	game->img_start = NULL;
	img_init_enemy(game);
}

void	img_init_enemy(t_game *game)
{
	game->enemy.left_enemy_s = NULL;
	game->enemy.left_enemy_m1 = NULL;
	game->enemy.left_enemy_m2 = NULL;
	game->enemy.top_enemy_s = NULL;
	game->enemy.top_enemy_m1 = NULL;
	game->enemy.top_enemy_m2 = NULL;
	game->enemy.right_enemy_s = NULL;
	game->enemy.right_enemy_m1 = NULL;
	game->enemy.right_enemy_m2 = NULL;
	game->enemy.down_enemy_s = NULL;
	game->enemy.down_enemy_m1 = NULL;
	game->enemy.down_enemy_m2 = NULL;
	img_init_player(game);
}

void	img_init_player(t_game *game)
{
	game->play.w_player_static = NULL;
	game->play.w_player_move1 = NULL;
	game->play.w_player_move2 = NULL;
	game->play.d_player_static = NULL;
	game->play.d_player_move1 = NULL;
	game->play.d_player_move2 = NULL;
	game->play.a_player_static = NULL;
	game->play.a_player_move1 = NULL;
	game->play.a_player_move2 = NULL;
	game->play.s_player_static = NULL;
	game->play.s_player_move1 = NULL;
	game->play.s_player_move2 = NULL;
}
