/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all_game.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmessmer <wmessmer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 08:55:20 by wmessmer          #+#    #+#             */
/*   Updated: 2023/01/17 11:56:30 by wmessmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void free_all_game(t_game *game)
{
    ft_img_destroyer(game);
    ft_map_destroyer(game);
    mlx_destroy_window(game->mlx,game->win);
    mlx_destroy_display(game->mlx);
    free (game->mlx);
}

void ft_img_destroyer(t_game *game)
{
    mlx_destroy_image(game->mlx, game->img_ground1);
    mlx_destroy_image(game->mlx, game->img_wall_front);
    mlx_destroy_image(game->mlx, game->img_wall_side);
    mlx_destroy_image(game->mlx, game->img_obstacle);
    mlx_destroy_image(game->mlx, game->img_exit_close);
    mlx_destroy_image(game->mlx, game->img_exit_open);
    mlx_destroy_image(game->mlx, game->img_player);
    mlx_destroy_image(game->mlx, game->img_collectable);
    mlx_destroy_image(game->mlx, game->player.w_player_static);
    mlx_destroy_image(game->mlx, game->player.w_player_move1);
    mlx_destroy_image(game->mlx, game->player.w_player_move2);
    mlx_destroy_image(game->mlx, game->player.s_player_static);
    mlx_destroy_image(game->mlx, game->player.s_player_move1);
    mlx_destroy_image(game->mlx, game->player.s_player_move2);
    mlx_destroy_image(game->mlx, game->player.a_player_static);
    mlx_destroy_image(game->mlx, game->player.a_player_move1);
    mlx_destroy_image(game->mlx, game->player.a_player_move2);
    mlx_destroy_image(game->mlx, game->player.d_player_static);
    mlx_destroy_image(game->mlx, game->player.d_player_move1);
    mlx_destroy_image(game->mlx, game->player.d_player_move2);

}

void ft_map_destroyer(t_game *game)
{
    int i;

    i = 0;
    while (i < game->mappy.row)
    {
        free (game->map[i]);
        i++;
    }
    free(game->map);
}

void ft_map_destroyer_int(int **map,t_game *game)
{
    int i;

    i = 0;
    while (i < game->mappy.row)
    {
        free (map[i]);
        i++;
    }
    free(map);
}