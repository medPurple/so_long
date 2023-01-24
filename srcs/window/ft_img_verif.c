/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_img_verif.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmessmer <wmessmer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 17:23:45 by wmessmer          #+#    #+#             */
/*   Updated: 2023/01/23 13:26:44 by wmessmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	verif_img_1(t_game *game)
{
	if (!game->img_ground1)
		error_image(game);
	if (!game->img_collectable)
		error_image(game);
	if (!game->img_exit_close)
		error_image(game);
	if (!game->img_exit_open)
		error_image(game);
	if (!game->img_player)
		error_image(game);
	if (!game->play.w_player_static)
		error_image(game);
	if (!game->play.w_player_move1)
		error_image(game);
	if (!game->play.w_player_move2)
		error_image(game);
	verif_img_2(game);
}

void	verif_img_2(t_game *game)
{
	if (!game->play.s_player_static)
		error_image(game);
	if (!game->play.s_player_move1)
		error_image(game);
	if (!game->play.s_player_move2)
		error_image(game);
	if (!game->play.a_player_static)
		error_image(game);
	if (!game->play.a_player_move1)
		error_image(game);
	if (!game->play.a_player_move2)
		error_image(game);
	if (!game->play.d_player_static)
		error_image(game);
	if (!game->play.d_player_move1)
		error_image(game);
	if (!game->play.d_player_move2)
		error_image(game);
	if (!game->img_wall_side)
		error_image(game);
	if (!game->img_wall_front)
		error_image(game);
	if (!game->img_obstacle)
		error_image(game);
}
