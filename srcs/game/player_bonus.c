/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmessmer <wmessmer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 11:56:16 by wmessmer          #+#    #+#             */
/*   Updated: 2023/01/17 19:25:35 by wmessmer         ###   ########.fr       */
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
	game->player.key_a = 0;
	game->player.key_d = 0;
	game->player.key_s = 0;
	game->player.key_w = 0;
}

void	ft_move_player(t_game *game, int y, int x)
{
	int lx = game->player_x;
	int ly = game->player_y;
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
	static int a = 0;
	if (game->player.key_w == 1)
	{
		game->player.key_w = 0;
		animate_w(game);
	}
	else if  (game->player.key_s == 1)
	{
		game->player.key_s = 0;
		animate_s(game);
	}
	else if  (game->player.key_a == 1)
	{
		game->player.key_a = 0;
		animate_a(game);
	}
	else if  (game->player.key_d == 1)
	{
		game->player.key_d = 0;
		animate_d(game,lx,ly);

	}	
	mlx_put_image_to_window(game->mlx, game->win \
	, game->img_ground1, lx * IMG_SIZE, ly * IMG_SIZE);
	move_actualisation(game);
}
//	mlx_string_put(game->mlx, window->win, (game->win_width / 2) - 48, game->win_height + 12   , 0xFF99FF, "Deplacememt : " + game->moves);
//
int ft_render(t_game *game)
{
	static int loop = 0;
	game->frame_ex++;
	game->enemy.frame_e++;
	if (game->frame_ex == 30000)
    {
		if (game->collected == game->collectable)
		{
			if (loop == 0)
			{
        		mlx_put_image_to_window(game->mlx, game->win, game->img_exit_open2, game->exit_x * IMG_SIZE, game->exit_y * IMG_SIZE);
				loop++;
			}
			else if (loop == 1)
    		{
        		loop = 0;
        		mlx_put_image_to_window(game->mlx, game->win, game->img_exit_open, game->exit_x * IMG_SIZE, game->exit_y * IMG_SIZE);
    		}
		}
		game->frame_ex = 0;
	}
	if (game->enemy.frame_e == 25000)
	{
		move_enemy(game);
		game->enemy.frame_e = 0;
	}
    return(1);
}