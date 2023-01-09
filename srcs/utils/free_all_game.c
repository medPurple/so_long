/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all_game.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmessmer <wmessmer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 08:55:20 by wmessmer          #+#    #+#             */
/*   Updated: 2023/01/09 11:45:52 by wmessmer         ###   ########.fr       */
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
    free (game);
}

void ft_img_destroyer(t_game *game)
{
    mlx_destroy_image(game->mlx, game->img_ground);
    mlx_destroy_image(game->mlx, game->img_wall);
    mlx_destroy_image(game->mlx, game->img_exit_close);
    mlx_destroy_image(game->mlx, game->img_exit_open);
    mlx_destroy_image(game->mlx, game->img_player);
    mlx_destroy_image(game->mlx, game->enemy_img1);
    mlx_destroy_image(game->mlx, game->img_collectable);
}

void ft_map_destroyer(t_game *game)
{
    int i;
    t_map *map;

    i = 0;
    while (i < map->row)
    {
        free (game->map[i]);
        i++;
    }
    free(game->map);
}