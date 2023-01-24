/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_enemy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmessmer <wmessmer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 15:09:36 by wmessmer          #+#    #+#             */
/*   Updated: 2023/01/20 14:48:31 by wmessmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	generate_enemy(t_game *game)
{
	int	x;
	int	y;
	int	z;
	int	a;

	z = 0;
	srand(time(NULL));
	if (game->mappy.col > 5 && game->mappy.row > 5 && game->ground_case > 10)
	{
		while (game->enemy.exist != 1 && z < 10)
		{
			x = (rand() % ((game->mappy.col - 2) - 2 + 1)) + 2;
			y = (rand() % ((game->mappy.row - 2) - 2 + 1)) + 2;
			if (game->map[y][x] == '0')
				game->enemy.exist = 1;
			z++;
		}
		enemy_to_img(game);
		game->enemy.x_enemy = x;
		game->enemy.y_enemy = y;
		mlx_put_image_to_window(game->mlx, game->win, game->enemy.top_enemy_s, \
			game->enemy.x_enemy * IMG_SIZE, game->enemy.y_enemy * IMG_SIZE);
	}
}

void	move_enemy(t_game *game)
{
	int	x;
	int	y;
	int	pos;

	srand(time(NULL));
	pos = (rand() % 4) + 1;
	x = game->enemy.x_enemy;
	y = game->enemy.y_enemy;
	if (game->map[y][x] == 'P')
		game_loose(game);
	if (pos == 1)
		move_up(game, x, y);
	else if (pos == 2)
		move_down(game, x, y);
	else if (pos == 3)
		move_right(game, x, y);
	else if (pos == 4)
		move_left(game, x, y);
	if (game->enemy.move == 1)
	{
		mlx_put_image_to_window(game->mlx, game->win, \
			game->img_ground1, x * IMG_SIZE, y * IMG_SIZE);
		game->enemy.move = 0;
	}
}

void	enemy_to_img(t_game *game)
{
	game->enemy.left_enemy_s = mlx_xpm_file_to_image(game->mlx, \
		ILEFT_ENEMY_S, &game->img_width, &game->img_height);
	game->enemy.left_enemy_m1 = mlx_xpm_file_to_image(game->mlx, \
		ILEFT_ENEMY_M1, &game->img_width, &game->img_height);
	game->enemy.left_enemy_m2 = mlx_xpm_file_to_image(game->mlx, \
		ILEFT_ENEMY_M2, &game->img_width, &game->img_height);
	game->enemy.right_enemy_s = mlx_xpm_file_to_image(game->mlx, \
		IRIGHT_ENEMY_S, &game->img_width, &game->img_height);
	game->enemy.right_enemy_m1 = mlx_xpm_file_to_image(game->mlx, \
		IRIGHT_ENEMY_M1, &game->img_width, &game->img_height);
	game->enemy.right_enemy_m2 = mlx_xpm_file_to_image(game->mlx, \
		IRIGHT_ENEMY_M2, &game->img_width, &game->img_height);
	enemy_to_img_2(game);
}

void	enemy_to_img_2(t_game *game)
{
	game->enemy.top_enemy_s = mlx_xpm_file_to_image(game->mlx, \
		IFRONT_ENEMY_S, &game->img_width, &game->img_height);
	game->enemy.top_enemy_m1 = mlx_xpm_file_to_image(game->mlx, \
		IFRONT_ENEMY_M1, &game->img_width, &game->img_height);
	game->enemy.top_enemy_m2 = mlx_xpm_file_to_image(game->mlx, \
		IFRONT_ENEMY_M2, &game->img_width, &game->img_height);
	game->enemy.down_enemy_s = mlx_xpm_file_to_image(game->mlx, \
		IDOWN_ENEMY_S, &game->img_width, &game->img_height);
	game->enemy.down_enemy_m1 = mlx_xpm_file_to_image(game->mlx, \
		IDOWN_ENEMY_M1, &game->img_width, &game->img_height);
	game->enemy.down_enemy_m2 = mlx_xpm_file_to_image(game->mlx, \
		IDOWN_ENEMY_M2, &game->img_width, &game->img_height);
	game->enemy.exist = 1;
}
