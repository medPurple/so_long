/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_on_image.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmessmer <wmessmer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 13:58:38 by wmessmer          #+#    #+#             */
/*   Updated: 2023/01/13 10:13:20 by wmessmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void define_obstacle(t_game *game, int j, int i)
{
    if (j == (game->win_width/48 - 1))
      mlx_put_image_to_window(game->mlx, game->win, game->img_wall_side, j * IMG_SIZE, i * IMG_SIZE);
    else if (j == 0 ) 
        mlx_put_image_to_window(game->mlx, game->win, game->img_wall_side, j * IMG_SIZE, i * IMG_SIZE);
    else if (i == 0)
        mlx_put_image_to_window(game->mlx, game->win, game->img_wall_front, j * IMG_SIZE, i * IMG_SIZE);
    else if (i == (game->win_height/48 - 1))
        mlx_put_image_to_window(game->mlx, game->win, game->img_wall_front, j * IMG_SIZE, i * IMG_SIZE);
    else
        mlx_put_image_to_window(game->mlx, game->win, game->img_obstacle, j * IMG_SIZE, i * IMG_SIZE);

}
    


void random_floor(t_game *game, int i, int j)
{
    int a;
    int k;
    a = rand() % 10;
    if (a == 1)
    {
        a = 0;
        mlx_put_image_to_window(game->mlx, game->win, game->img_ground4, j * IMG_SIZE, i * IMG_SIZE);
    }
    else if (a == 2 || a == 5)
    {
        a = 0;        
        mlx_put_image_to_window(game->mlx, game->win, game->img_ground2, j * IMG_SIZE, i * IMG_SIZE);
    }
    else if (a == 3 || a == 6)
    {
        a = 0;
        mlx_put_image_to_window(game->mlx, game->win, game->img_ground3, j * IMG_SIZE, i * IMG_SIZE);
    }
    else 
    {
        a = 0;        
        mlx_put_image_to_window(game->mlx, game->win, game->img_ground1, j * IMG_SIZE, i * IMG_SIZE);
    } 
}