/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmessmer <wmessmer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 11:56:16 by wmessmer          #+#    #+#             */
/*   Updated: 2023/01/23 19:27:09 by wmessmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	player_init(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'P')
			{
				game->player_y = i;
				game->player_x = j;
			}
			j++;
		}
		i++;
	}
	game->moves = 0;
	game->play.key_a = 0;
	game->play.key_d = 0;
	game->play.key_s = 0;
	game->play.key_w = 0;
	img_init_base(game);
}

void	ft_move_player(t_game *game, int y, int x)
{
	int	lx;
	int	ly;

	lx = game->player_x;
	ly = game->player_y;
	if (game->map[y][x] == 'E' && game->collected == game->collectable)
		game_victory(game);
	if (game->map[y][x] == 'M')
		game_loose(game);
	else if (game->map[y][x] == 'C' || game->map[y][x] == '0')
	{
		game->map[ly][lx] = '0';
		if (game->map[y][x] == 'C')
			game->collected += 1;
		game->player_x = x;
		game->player_y = y;
		game->map[y][x] = 'P';
		game->moves += 1;
		map_actualisation(game, lx, ly);
	}
}

void	map_actualisation(t_game *game, int lx, int ly)
{
	if (game->play.key_w == 1)
	{
		game->play.key_w = 0;
		animate_w(game);
	}
	else if (game->play.key_s == 1)
	{
		game->play.key_s = 0;
		animate_s(game);
	}
	else if (game->play.key_a == 1)
	{
		game->play.key_a = 0;
		animate_a(game);
	}
	else if (game->play.key_d == 1)
	{
		game->play.key_d = 0;
		animate_d(game);
	}
	mlx_put_image_to_window(game->mlx, game->win \
	, game->img_ground1, lx * IMG_SIZE, ly * IMG_SIZE);
	move_actualisation(game);
}

int	ft_render(t_game *game)
{
	game->frame_ex++;
	game->enemy.frame_e++;
	if (game->frame_ex == 30000)
	{
		if (game->collected == game->collectable)
			exit_animation(game);
		game->frame_ex = 0;
	}
	if (game->enemy.frame_e == 10000 && game->enemy.exist == 1)
	{
		move_enemy(game);
		game->enemy.frame_e = 0;
	}
	return (1);
}
