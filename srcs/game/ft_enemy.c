/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_enemy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmessmer <wmessmer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 15:09:36 by wmessmer          #+#    #+#             */
/*   Updated: 2023/01/17 19:22:03 by wmessmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void generate_enemy(t_game *game)
{
    int x,y;
    int z = 0;
    int a = 0;
    if (game->mappy.col > 5 && game->mappy.row > 5 && game->ground_case > 5)
    {
        srand(time(NULL));
        while (a != 1 && z < 10)
        {
            x = (rand() % ((game->mappy.col - 2) - 2 + 1)) + 2;
            y = (rand() % ((game->mappy.row - 2) - 2 + 1)) + 2;
            if (game->map[y][x] == '0')
                a = 1;
            z++;
        }
        if (a == 1)
            mlx_put_image_to_window(game->mlx, game->win, game->enemy_img2, x * IMG_SIZE, y * IMG_SIZE);
    }
    game->enemy.x_enemy = x;
    game->enemy.y_enemy = y;
}

void move_enemy(t_game *game)
{
    srand(time(NULL));
    int x;
    int y;
    x = game->enemy.x_enemy;
    y = game->enemy.y_enemy;
    int pos = (rand() % 4) + 1;
    if (game->map[y][x] == 'P')
        game_loose(game);
    if (pos == 1)
        move_up(game,x,y);
    else if (pos == 2)
        move_down(game,x,y);
    else if (pos == 3)
        move_right(game,x,y);
    else if (pos == 4)
        move_left(game,x,y);
}