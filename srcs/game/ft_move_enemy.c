/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_enemy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmessmer <wmessmer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 18:30:44 by wmessmer          #+#    #+#             */
/*   Updated: 2023/01/20 14:37:33 by wmessmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	move_left(t_game *game, int x, int y)
{
	static int	loop = 0;

	if (game->map[y][x - 1] == '0' || game->map[y][x - 1] == 'P')
	{
		game->enemy.x_enemy -= 1;
		loop++;
		if (loop == 0)
			mlx_put_image_to_window(game->mlx, game->win, \
				game->enemy.left_enemy_s, game->enemy.x_enemy \
					* IMG_SIZE, game->enemy.y_enemy * IMG_SIZE);
		else if (loop == 1)
			mlx_put_image_to_window(game->mlx, game->win, \
				game->enemy.left_enemy_m1, game->enemy.x_enemy \
					* IMG_SIZE, game->enemy.y_enemy * IMG_SIZE);
		else if (loop == 2)
		{
			loop = 0;
			mlx_put_image_to_window(game->mlx, game->win, \
				game->enemy.left_enemy_m2, game->enemy.x_enemy \
					* IMG_SIZE, game->enemy.y_enemy * IMG_SIZE);
		}
		if (game->map[y][x - 1] == 'P')
			game_loose(game);
		game->enemy.move = 1;
	}
}

void	move_right(t_game *game, int x, int y)
{
	static int	loop = 0;

	if (game->map[y][x + 1] == '0' || game->map[y][x + 1] == 'P')
	{
		game->enemy.x_enemy += 1;
		loop++;
		if (loop == 0)
			mlx_put_image_to_window(game->mlx, game->win, \
				game->enemy.right_enemy_s, game->enemy.x_enemy \
					* IMG_SIZE, game->enemy.y_enemy * IMG_SIZE);
		else if (loop == 1)
			mlx_put_image_to_window(game->mlx, game->win, \
				game->enemy.right_enemy_m1, game->enemy.x_enemy \
					* IMG_SIZE, game->enemy.y_enemy * IMG_SIZE);
		else if (loop == 2)
		{
			loop = 0;
			mlx_put_image_to_window(game->mlx, game->win, \
				game->enemy.right_enemy_m2, game->enemy.x_enemy \
					* IMG_SIZE, game->enemy.y_enemy * IMG_SIZE);
		}
		if (game->map[y][x + 1] == 'P')
			game_loose(game);
		game->enemy.move = 1;
	}
}

void	move_down(t_game *game, int x, int y)
{
	static int	loop = 0;

	if (game->map[y - 1][x] == '0' || game->map[y - 1][x] == 'P')
	{
		game->enemy.y_enemy -= 1;
		loop++;
		if (loop == 0)
			mlx_put_image_to_window(game->mlx, game->win, \
				game->enemy.down_enemy_s, game->enemy.x_enemy \
					* IMG_SIZE, game->enemy.y_enemy * IMG_SIZE);
		else if (loop == 1)
			mlx_put_image_to_window(game->mlx, game->win, \
				game->enemy.down_enemy_m1, game->enemy.x_enemy \
					* IMG_SIZE, game->enemy.y_enemy * IMG_SIZE);
		else if (loop == 2)
		{
			loop = 0;
			mlx_put_image_to_window(game->mlx, game->win, \
				game->enemy.down_enemy_m2, game->enemy.x_enemy \
					* IMG_SIZE, game->enemy.y_enemy * IMG_SIZE);
		}
		if (game->map[y - 1][x] == 'P')
			game_loose(game);
		game->enemy.move = 1;
	}
}

void	move_up(t_game *game, int x, int y)
{
	static int	loop = 0;

	if (game->map[y + 1][x] == '0' || game->map[y + 1][x] == 'P')
	{
		game->enemy.y_enemy += 1;
		loop++;
		if (loop == 0)
			mlx_put_image_to_window(game->mlx, game->win, \
				game->enemy.top_enemy_s, game->enemy.x_enemy \
					* IMG_SIZE, game->enemy.y_enemy * IMG_SIZE);
		else if (loop == 1)
			mlx_put_image_to_window(game->mlx, game->win, \
				game->enemy.top_enemy_m1, game->enemy.x_enemy \
					* IMG_SIZE, game->enemy.y_enemy * IMG_SIZE);
		else if (loop == 2)
		{
			loop = 0;
			mlx_put_image_to_window(game->mlx, game->win, \
				game->enemy.top_enemy_m2, game->enemy.x_enemy \
					* IMG_SIZE, game->enemy.y_enemy * IMG_SIZE);
		}
		if (game->map[y + 1][x] == 'P')
			game_loose(game);
		game->enemy.move = 1;
	}
}
