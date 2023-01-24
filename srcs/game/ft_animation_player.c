/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_animation_player.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmessmer <wmessmer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 09:02:58 by wmessmer          #+#    #+#             */
/*   Updated: 2023/01/23 19:36:20 by wmessmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	animate_w(t_game *game)
{
	static int	loopw = 1;

	if (loopw == 1)
	{
		mlx_put_image_to_window(game->mlx, game->win, \
			game->play.w_player_move1, game->player_x \
				* IMG_SIZE, game->player_y * IMG_SIZE);
		loopw++;
	}
	else
	{
		mlx_put_image_to_window(game->mlx, game->win, \
			game->play.w_player_move2, game->player_x \
				* IMG_SIZE, game->player_y * IMG_SIZE);
		loopw--;
	}
}

void	animate_s(t_game *game)
{
	static int	loops = 1;

	if (loops == 1)
	{
		mlx_put_image_to_window(game->mlx, game->win, \
			game->play.s_player_move1, game->player_x \
				* IMG_SIZE, game->player_y * IMG_SIZE);
		loops++;
	}
	else
	{
		mlx_put_image_to_window(game->mlx, game->win, \
			game->play.s_player_move2, game->player_x \
				* IMG_SIZE, game->player_y * IMG_SIZE);
		loops--;
	}
}

void	animate_a(t_game *game)
{
	static int	loopa = 1;

	if (loopa == 1)
	{
		mlx_put_image_to_window(game->mlx, game->win, \
			game->play.a_player_move1, game->player_x \
				* IMG_SIZE, game->player_y * IMG_SIZE);
		loopa++;
	}
	else
	{
		mlx_put_image_to_window(game->mlx, game->win, \
			game->play.a_player_move2, game->player_x \
				* IMG_SIZE, game->player_y * IMG_SIZE);
		loopa--;
	}
}

void	animate_d(t_game *game)
{
	static int	loopd = 1;

	if (loopd == 1)
	{
		mlx_put_image_to_window(game->mlx, game->win, \
			game->play.d_player_move1, game->player_x \
				* IMG_SIZE, game->player_y * IMG_SIZE);
		loopd++;
	}
	else
	{
		mlx_put_image_to_window(game->mlx, game->win, \
			game->play.d_player_move2, game->player_x \
				* IMG_SIZE, game->player_y * IMG_SIZE);
		loopd--;
	}
}
