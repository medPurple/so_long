/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_image.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmessmer <wmessmer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 11:31:56 by wmessmer          #+#    #+#             */
/*   Updated: 2023/01/23 13:28:35 by wmessmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	img_clear_base(t_game*game)
{
	if (game->img_ground1)
		mlx_destroy_image(game->mlx, game->img_ground1);
	if (game->img_ground2)
		mlx_destroy_image(game->mlx, game->img_ground2);
	if (game->img_ground3)
		mlx_destroy_image(game->mlx, game->img_ground3);
	if (game->img_ground4)
		mlx_destroy_image(game->mlx, game->img_ground4);
	if (game->img_wall_side)
		mlx_destroy_image(game->mlx, game->img_wall_side);
	if (game->img_wall_front)
		mlx_destroy_image(game->mlx, game->img_wall_front);
	if (game->img_obstacle)
		mlx_destroy_image(game->mlx, game->img_obstacle);
	img_clear_base_2(game);
}

void	img_clear_base_2(t_game *game)
{
	if (game->enemy_img1)
		mlx_destroy_image(game->mlx, game->enemy_img1);
	if (game->img_player)
		mlx_destroy_image(game->mlx, game->img_player);
	if (game->img_collectable)
		mlx_destroy_image(game->mlx, game->img_collectable);
	if (game->img_exit_close)
		mlx_destroy_image(game->mlx, game->img_exit_close);
	if (game->img_exit_open)
		mlx_destroy_image(game->mlx, game->img_exit_open);
	if (game->img_exit_open2)
		mlx_destroy_image(game->mlx, game->img_exit_open2);
	if (game->img_start)
		mlx_destroy_image(game->mlx, game->img_start);
	img_clear_enemy(game);
}

void	img_clear_enemy(t_game *game)
{
	if (game->enemy.left_enemy_s)
		mlx_destroy_image(game->mlx, game->enemy.left_enemy_s);
	if (game->enemy.left_enemy_m1)
		mlx_destroy_image(game->mlx, game->enemy.left_enemy_m1);
	if (game->enemy.left_enemy_m2)
		mlx_destroy_image(game->mlx, game->enemy.left_enemy_m2);
	if (game->enemy.top_enemy_s)
		mlx_destroy_image(game->mlx, game->enemy.top_enemy_s);
	if (game->enemy.top_enemy_m1)
		mlx_destroy_image(game->mlx, game->enemy.top_enemy_m1);
	if (game->enemy.top_enemy_m2)
		mlx_destroy_image(game->mlx, game->enemy.top_enemy_m2);
	if (game->enemy.right_enemy_s)
		mlx_destroy_image(game->mlx, game->enemy.right_enemy_s);
	if (game->enemy.right_enemy_m1)
		mlx_destroy_image(game->mlx, game->enemy.right_enemy_m1);
	if (game->enemy.right_enemy_m2)
		mlx_destroy_image(game->mlx, game->enemy.right_enemy_m2);
	if (game->enemy.down_enemy_s)
		mlx_destroy_image(game->mlx, game->enemy.down_enemy_s);
	if (game->enemy.down_enemy_m1)
		mlx_destroy_image(game->mlx, game->enemy.down_enemy_m1);
	if (game->enemy.down_enemy_m2)
		mlx_destroy_image(game->mlx, game->enemy.down_enemy_m2);
	img_clear_player(game);
}

void	img_clear_player(t_game *game)
{
	if (game->play.w_player_static)
		mlx_destroy_image(game->mlx, game->play.w_player_static);
	if (game->play.w_player_move1)
		mlx_destroy_image(game->mlx, game->play.w_player_move1);
	if (game->play.w_player_move2)
		mlx_destroy_image(game->mlx, game->play.w_player_move2);
	if (game->play.d_player_static)
		mlx_destroy_image(game->mlx, game->play.d_player_static);
	if (game->play.d_player_move1)
		mlx_destroy_image(game->mlx, game->play.d_player_move1);
	if (game->play.d_player_move2)
		mlx_destroy_image(game->mlx, game->play.d_player_move2);
	if (game->play.a_player_static)
		mlx_destroy_image(game->mlx, game->play.a_player_static);
	if (game->play.a_player_move1)
		mlx_destroy_image(game->mlx, game->play.a_player_move1);
	if (game->play.a_player_move2)
		mlx_destroy_image(game->mlx, game->play.a_player_move2);
	if (game->play.s_player_static)
		mlx_destroy_image(game->mlx, game->play.s_player_static);
	if (game->play.s_player_move1)
		mlx_destroy_image(game->mlx, game->play.s_player_move1);
	if (game->play.s_player_move2)
		mlx_destroy_image(game->mlx, game->play.s_player_move2);
}
