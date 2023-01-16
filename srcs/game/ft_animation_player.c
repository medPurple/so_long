/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_animation_player.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmessmer <wmessmer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 09:02:58 by wmessmer          #+#    #+#             */
/*   Updated: 2023/01/16 19:47:39 by wmessmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void animate_w(t_game *game)
{
    static int loop = 0;
    loop++;
    if (loop == 0)
        mlx_put_image_to_window(game->mlx, game->win, game->player.w_player_static, game->player_x * IMG_SIZE, game->player_y * IMG_SIZE);
    else if (loop == 1)    
        mlx_put_image_to_window(game->mlx, game->win, game->player.w_player_move1, game->player_x * IMG_SIZE, game->player_y * IMG_SIZE);
    else if (loop == 2)
        mlx_put_image_to_window(game->mlx, game->win, game->player.w_player_move2, game->player_x * IMG_SIZE, game->player_y * IMG_SIZE);
    else
    {
        loop = 0;
        mlx_put_image_to_window(game->mlx, game->win, game->player.w_player_static, game->player_x * IMG_SIZE, game->player_y * IMG_SIZE);
    }
}
void animate_s(t_game *game)
{
    static int loop = 0;
    loop++;
    if (loop == 0)
        mlx_put_image_to_window(game->mlx, game->win, game->player.s_player_static, game->player_x * IMG_SIZE, game->player_y * IMG_SIZE);
    else if (loop == 1)    
        mlx_put_image_to_window(game->mlx, game->win, game->player.s_player_move1, game->player_x * IMG_SIZE, game->player_y * IMG_SIZE);
    else if (loop == 2)
        mlx_put_image_to_window(game->mlx, game->win, game->player.s_player_move2, game->player_x * IMG_SIZE, game->player_y * IMG_SIZE);
    else
    {
        loop = 0;
        mlx_put_image_to_window(game->mlx, game->win, game->player.s_player_static, game->player_x * IMG_SIZE, game->player_y * IMG_SIZE);
    }   
}
void animate_a(t_game *game)
{
    static int loop = 0;
    loop++;
    if (loop == 0)
        mlx_put_image_to_window(game->mlx, game->win, game->player.a_player_static, game->player_x * IMG_SIZE, game->player_y * IMG_SIZE);
    else if (loop == 1)    
        mlx_put_image_to_window(game->mlx, game->win, game->player.a_player_move1, game->player_x * IMG_SIZE, game->player_y * IMG_SIZE);
    else if (loop == 2)
        mlx_put_image_to_window(game->mlx, game->win, game->player.a_player_move2, game->player_x * IMG_SIZE, game->player_y * IMG_SIZE);
    else
    {
        loop = 0;
        mlx_put_image_to_window(game->mlx, game->win, game->player.a_player_static, game->player_x * IMG_SIZE, game->player_y * IMG_SIZE);
    }   
}
void animate_d(t_game *game)
{
    static int loop = 0;
    loop++;
    if (loop == 0)
        mlx_put_image_to_window(game->mlx, game->win, game->player.d_player_static, game->player_x * IMG_SIZE, game->player_y * IMG_SIZE);
    else if (loop == 1)    
        mlx_put_image_to_window(game->mlx, game->win, game->player.d_player_move1, game->player_x * IMG_SIZE, game->player_y * IMG_SIZE);
    else if (loop == 2)
        mlx_put_image_to_window(game->mlx, game->win, game->player.d_player_move2, game->player_x * IMG_SIZE, game->player_y * IMG_SIZE);
    else
    {
        loop = 0;
        mlx_put_image_to_window(game->mlx, game->win, game->player.d_player_static, game->player_x * IMG_SIZE, game->player_y * IMG_SIZE);
    }  
}

