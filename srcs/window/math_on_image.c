/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_on_image.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmessmer <wmessmer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 13:58:38 by wmessmer          #+#    #+#             */
/*   Updated: 2023/01/14 15:48:19 by wmessmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	define_obstacle(t_game *game, int j, int i)
{
	if (j == (game->win_width / 48 - 1))
		mlx_put_image_to_window(game->mlx, \
			game->win, game->img_wall_side, j * IMG_SIZE, i * IMG_SIZE);
	else if (j == 0)
		mlx_put_image_to_window(game->mlx, \
			game->win, game->img_wall_side, j * IMG_SIZE, i * IMG_SIZE);
	else if (i == 0)
		mlx_put_image_to_window(game->mlx, \
			game->win, game->img_wall_front, j * IMG_SIZE, i * IMG_SIZE);
	else if (i == (game->win_height / 48 - 1))
		mlx_put_image_to_window(game->mlx, \
			game->win, game->img_wall_front, j * IMG_SIZE, i * IMG_SIZE);
	else
		mlx_put_image_to_window(game->mlx, \
			game->win, game->img_obstacle, j * IMG_SIZE, i * IMG_SIZE);
}

void	random_floor(t_game *game, int i, int j, int a)
{
	if (a == 100)
		mlx_put_image_to_window(game->mlx, \
			game->win, game->img_ground4, j * IMG_SIZE, i * IMG_SIZE);
	else if (a <= 20)
		mlx_put_image_to_window(game->mlx, \
			game->win, game->img_ground2, j * IMG_SIZE, i * IMG_SIZE);
	else if (a >= 21 && a <= 40)
		mlx_put_image_to_window(game->mlx, \
			game->win, game->img_ground3, j * IMG_SIZE, i * IMG_SIZE);
	else
		mlx_put_image_to_window(game->mlx, \
			game->win, game->img_ground1, j * IMG_SIZE, i * IMG_SIZE);
}
