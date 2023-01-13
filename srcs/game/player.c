/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmessmer <wmessmer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 11:56:16 by wmessmer          #+#    #+#             */
/*   Updated: 2023/01/12 11:01:49 by wmessmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"
void player_init(t_game *player)
{
    int i;
    int j;

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

void map_actualisation(t_game *game, int lx, int ly)
{
    if (game->collected == game->collectable)
        mlx_put_image_to_window(game->mlx, game->win, game->img_exit_open, game->exit_x * IMG_SIZE, game->exit_y * IMG_SIZE);
    mlx_put_image_to_window(game->mlx, game->win, game->img_player, game->player_x * IMG_SIZE, game->player_y * IMG_SIZE);
    mlx_put_image_to_window(game->mlx, game->win, game->img_ground1, lx * IMG_SIZE, ly * IMG_SIZE);
    

}