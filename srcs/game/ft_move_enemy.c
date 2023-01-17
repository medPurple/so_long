/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_enemy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmessmer <wmessmer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 18:30:44 by wmessmer          #+#    #+#             */
/*   Updated: 2023/01/17 19:21:44 by wmessmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void move_left(t_game *game,int x, int y)
{
    if (game->map[y][x - 1] == '0'|| game->map[y][x - 1] == 'P')
        {
            game->enemy.x_enemy -= 1;
            mlx_put_image_to_window(game->mlx, game->win, game->enemy_img2, (x - 1) * IMG_SIZE, y * IMG_SIZE);
            mlx_put_image_to_window(game->mlx, game->win, game->img_ground1, x * IMG_SIZE, y * IMG_SIZE);      
            if (game->map[y][x - 1] == 'P')
                game_loose(game);
        }
}

void move_right(t_game *game,int x, int y)
{
    if (game->map[y][x + 1] == '0'|| game->map[y][x + 1] == 'P')
        {
            game->enemy.x_enemy += 1;
            mlx_put_image_to_window(game->mlx, game->win, game->enemy_img2, (x + 1) * IMG_SIZE, y * IMG_SIZE);
            mlx_put_image_to_window(game->mlx, game->win, game->img_ground1, x * IMG_SIZE, y * IMG_SIZE);       
            if (game->map[y][x + 1] == 'P')
                game_loose(game);
        }
}

void move_down(t_game *game,int x, int y)
{
    if (game->map[y - 1][x] == '0' || game->map[y - 1][x] == 'P')
        {
            game->enemy.y_enemy -= 1;
            mlx_put_image_to_window(game->mlx, game->win, game->enemy_img2, x * IMG_SIZE, (y - 1) * IMG_SIZE);
            mlx_put_image_to_window(game->mlx, game->win, game->img_ground1, x * IMG_SIZE, y * IMG_SIZE);       
            if (game->map[y-1][x] == 'P')
                game_loose(game);
        }
}

void move_up(t_game *game,int x, int y)
{
    if (game->map[y + 1][x] == '0'|| game->map[y + 1][x] == 'P')
        {
            game->enemy.y_enemy += 1;
            mlx_put_image_to_window(game->mlx, game->win, game->enemy_img2, x * IMG_SIZE, (y + 1) * IMG_SIZE);
            mlx_put_image_to_window(game->mlx, game->win, game->img_ground1, x * IMG_SIZE, y * IMG_SIZE);
            if (game->map[y+1][x] == 'P')
                game_loose(game);
        }  
}