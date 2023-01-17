/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xpm_to_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmessmer <wmessmer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 13:28:19 by wmessmer          #+#    #+#             */
/*   Updated: 2023/01/17 19:40:34 by wmessmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void ground_to_img(t_game *game)
{
    game->img_ground1 = mlx_xpm_file_to_image(game->mlx,GROUND_IMG1,&game->img_width,&game->img_height);
    if (game->img_width == 0 || game->img_height == 0)
    {
        ft_printf("stop");
        mlx_error(1);
    }
    game->img_ground2 = mlx_xpm_file_to_image(game->mlx,GROUND_IMG2,&game->img_width,&game->img_height);
    if (game->img_width == 0 || game->img_height == 0)
    {
        ft_printf("stop");
        mlx_error(1);
    }
    game->img_ground3 = mlx_xpm_file_to_image(game->mlx,GROUND_IMG3,&game->img_width,&game->img_height);
    if (game->img_width == 0 || game->img_height == 0)
    {
        ft_printf("stop");
        mlx_error(1);
    }
    game->img_ground4 = mlx_xpm_file_to_image(game->mlx,GROUND_IMG4,&game->img_width,&game->img_height);
    if (game->img_width == 0 || game->img_height == 0)
    {
        ft_printf("stop");
        mlx_error(1);
    }
}

void obstacle_to_img(t_game *game)
{
    game->img_wall_side = mlx_xpm_file_to_image(game->mlx,WALL_IMG_SIDE,&game->img_width,&game->img_height);
    if (game->img_width == 0 || game->img_height == 0)
    {
        ft_printf("stop");
        mlx_error(1);
    }
    game->img_wall_front = mlx_xpm_file_to_image(game->mlx,WALL_IMG_TOP,&game->img_width,&game->img_height);
    if (game->img_width == 0 || game->img_height == 0)
    {
        ft_printf("stop");
        mlx_error(1);
    }
    game->img_obstacle = mlx_xpm_file_to_image(game->mlx,OBSTACLE,&game->img_width,&game->img_height);
    if (game->img_width == 0 || game->img_height == 0)
    {
        ft_printf("stop");
        mlx_error(1);
    }
}

void player_to_img(t_game *game)
{
    game->img_player = mlx_xpm_file_to_image(game->mlx,d_player_s,&game->img_width,&game->img_height);

    game->player.w_player_static = mlx_xpm_file_to_image(game->mlx,w_player_s,&game->img_width,&game->img_height);
    game->player.w_player_move1 = mlx_xpm_file_to_image(game->mlx,w_player_m1,&game->img_width,&game->img_height);
    game->player.w_player_move2 = mlx_xpm_file_to_image(game->mlx,w_player_m2,&game->img_width,&game->img_height);

    game->player.s_player_static = mlx_xpm_file_to_image(game->mlx,s_player_s,&game->img_width,&game->img_height);
    game->player.s_player_move1 = mlx_xpm_file_to_image(game->mlx,s_player_m1,&game->img_width,&game->img_height);
    game->player.s_player_move2 = mlx_xpm_file_to_image(game->mlx,s_player_m2,&game->img_width,&game->img_height);

    game->player.a_player_static = mlx_xpm_file_to_image(game->mlx,a_player_s,&game->img_width,&game->img_height);
    game->player.a_player_move1 = mlx_xpm_file_to_image(game->mlx,a_player_m1,&game->img_width,&game->img_height);
    game->player.a_player_move2 = mlx_xpm_file_to_image(game->mlx,a_player_m2,&game->img_width,&game->img_height);

    game->player.d_player_static = mlx_xpm_file_to_image(game->mlx,d_player_s,&game->img_width,&game->img_height);
    game->player.d_player_move1 = mlx_xpm_file_to_image(game->mlx,d_player_m1,&game->img_width,&game->img_height);
    game->player.d_player_move2 = mlx_xpm_file_to_image(game->mlx,d_player_m2,&game->img_width,&game->img_height);

}

void other_to_img(t_game *game)
{
    game->img_collectable = mlx_xpm_file_to_image(game->mlx,COLLECTABLE_IMG1,&game->img_width,&game->img_height);
    if (game->img_width == 0 || game->img_height == 0)
    {
        ft_printf("stop");
        mlx_error(1);
    }
    game->enemy_img1 = mlx_xpm_file_to_image(game->mlx,ENEMY_IMG1,&game->img_width,&game->img_height); 
    if (game->img_width == 0 || game->img_height == 0)
    {
        ft_printf("stop");
        mlx_error(1);
    }
    game->enemy_img2 = mlx_xpm_file_to_image(game->mlx,ENEMY_IMG2,&game->img_width,&game->img_height); 
    if (game->img_width == 0 || game->img_height == 0)
    {
        ft_printf("stop");
        mlx_error(1);
    }
    game->img_exit_close = mlx_xpm_file_to_image(game->mlx,EXIT_IMG_C,&game->img_width,&game->img_height);
    if (game->img_width == 0 || game->img_height == 0)
    {
        ft_printf("stop");
        mlx_error(1);
    }
    game->img_exit_open = mlx_xpm_file_to_image(game->mlx,EXIT_IMG_O,&game->img_width,&game->img_height);
    if (game->img_width == 0 || game->img_height == 0)
    {
        ft_printf("stop");
        mlx_error(1);
    }
    game->img_exit_open2 = mlx_xpm_file_to_image(game->mlx,EXIT_IMG_O2,&game->img_width,&game->img_height);
    if (game->img_exit_open2 == NULL)
    {
        ft_printf("stop");
        mlx_error(1);
    }
}