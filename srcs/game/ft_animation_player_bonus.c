/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_animation_player_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmessmer <wmessmer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 09:02:58 by wmessmer          #+#    #+#             */
/*   Updated: 2023/01/17 14:35:37 by wmessmer         ###   ########.fr       */
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
void animate_d(t_game *game,int lx, int ly)
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
    /*int loop = 0;
    int i = 0;
    int x = lx;
    int y = ly;
    int k = 0;
    while ( i < 8)
    {
        loop++;
        if (loop == 1)
        {
            ft_printf("ok1\n");
            mlx_put_image_to_window(game->mlx, game->win, game->player.d_player_move1, x * IMG_SIZE + k, y * IMG_SIZE);
        }
        else if (loop == 2)
        {
            ft_printf("ok2\n");
            loop = 0;
            mlx_put_image_to_window(game->mlx, game->win, game->player.d_player_move2, x * IMG_SIZE + k, y * IMG_SIZE);
        }
        ft_printf("%d\n",x * IMG_SIZE + k);
        //sleep(1);
        i++;
        k += 6;
        ft_printf("x %d y %d\n",x,y);

    }
    mlx_put_image_to_window(game->mlx, game->win, game->img_ground1, x * IMG_SIZE + k, y * IMG_SIZE);
    mlx_put_image_to_window(game->mlx, game->win, game->player.d_player_static, game->player_x * IMG_SIZE + k, game->player_y * IMG_SIZE);*/
}