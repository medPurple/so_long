/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmessmer <wmessmer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 11:56:16 by wmessmer          #+#    #+#             */
/*   Updated: 2023/01/16 08:54:20 by wmessmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	player_init(t_game *player)
{
	int	i;
	int	j;

	i = 0;
	while (player->map[i])
	{
		j = 0;
		while (player->map[i][j])
		{
			if (player->map[i][j] == 'P')
			{
				player->player_y = i;
				player->player_x = j;
			}
			j++;
		}
		i++;
	}
	player->moves = 0;
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
	if (game->collected == game->collectable)
		mlx_put_image_to_window(game->mlx, game->win, game->img_exit_open \
		, game->exit_x * IMG_SIZE, game->exit_y * IMG_SIZE);
	mlx_put_image_to_window(game->mlx, game->win \
	, game->img_player, game->player_x * IMG_SIZE, game->player_y * IMG_SIZE);
	mlx_put_image_to_window(game->mlx, game->win \
	, game->img_ground1, lx * IMG_SIZE, ly * IMG_SIZE);
}