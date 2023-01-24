/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_img_verif_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmessmer <wmessmer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 11:11:34 by wmessmer          #+#    #+#             */
/*   Updated: 2023/01/23 11:31:18 by wmessmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	img_verif_base(t_game*game)
{
	if (game->img_ground1 == NULL)
		error_image(game);
	if (game->img_ground2 == NULL)
		error_image(game);
	if (game->img_ground3 == NULL)
		error_image(game);
	if (game->img_ground4 == NULL)
		error_image(game);
	if (game->img_wall_side == NULL)
		error_image(game);
	if (game->img_wall_front == NULL)
		error_image(game);
	if (game->img_obstacle == NULL)
		error_image(game);
}

void	img_verif_base_2(t_game *game)
{
	if (game->enemy_img1 == NULL)
		error_image(game);
	if (game->img_player == NULL)
		error_image(game);
	if (game->img_collectable == NULL)
		error_image(game);
	if (game->img_exit_close == NULL)
		error_image(game);
	if (game->img_exit_open == NULL)
		error_image(game);
	if (game->img_exit_open2 == NULL)
		error_image(game);
	if (game->img_start == NULL)
		error_image(game);
}

void	img_verif_enemy(t_game *game)
{
	if (game->enemy.left_enemy_s == NULL)
		error_image(game);
	if (game->enemy.left_enemy_m1 == NULL)
		error_image(game);
	if (game->enemy.left_enemy_m2 == NULL)
		error_image(game);
	if (game->enemy.top_enemy_s == NULL)
		error_image(game);
	if (game->enemy.top_enemy_m1 == NULL)
		error_image(game);
	if (game->enemy.top_enemy_m2 == NULL)
		error_image(game);
	if (game->enemy.right_enemy_s == NULL)
		error_image(game);
	if (game->enemy.right_enemy_m1 == NULL)
		error_image(game);
	if (game->enemy.right_enemy_m2 == NULL)
		error_image(game);
	if (game->enemy.down_enemy_s == NULL)
		error_image(game);
	if (game->enemy.down_enemy_m1 == NULL)
		error_image(game);
	if (game->enemy.down_enemy_m2 == NULL)
		error_image(game);
}

void	img_verif_player(t_game *game)
{
	if (game->play.w_player_static == NULL)
		error_image(game);
	if (game->play.w_player_move1 == NULL)
		error_image(game);
	if (game->play.w_player_move2 == NULL)
		error_image(game);
	if (game->play.d_player_static == NULL)
		error_image(game);
	if (game->play.d_player_move1 == NULL)
		error_image(game);
	if (game->play.d_player_move2 == NULL)
		error_image(game);
	if (game->play.a_player_static == NULL)
		error_image(game);
	if (game->play.a_player_move1 == NULL)
		error_image(game);
	if (game->play.a_player_move2 == NULL)
		error_image(game);
	if (game->play.s_player_static == NULL)
		error_image(game);
	if (game->play.s_player_move1 == NULL)
		error_image(game);
	if (game->play.s_player_move2 == NULL)
		error_image(game);
}
