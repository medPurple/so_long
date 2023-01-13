/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmessmer <wmessmer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 19:22:48 by wmessmer          #+#    #+#             */
/*   Updated: 2023/01/12 15:40:57 by wmessmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

int window_initialisation(t_game *window)
{
    window->mlx = mlx_init();
    if (window->mlx == NULL)
        return (mlx_error(1));
    window->win = mlx_new_window(window->mlx, window->win_width, window->win_height, "LE GAMING BITCH");
    if (window->win == NULL)
    {
        free(window->win);
        return(mlx_error(1));
    }
    image_initialisation(window);
    return (1);
}

void image_initialisation(t_game *game)
{
    ground_to_img(game);
    obstacle_to_img(game);
    other_to_img(game);
    
    game->img_player = mlx_xpm_file_to_image(game->mlx,PLAYER_IMG,&game->img_width,&game->img_height);
    if (game->img_width == 0 || game->img_height == 0)
    {
        ft_printf("stop");
        mlx_error(1);
    }


    render_maps(game);
   
}

int render_maps(t_game *game)
{
    int i = 0;
    size_t j = 0;
    int width = 0;
    if (game->win == NULL)
        return (mlx_error(1));

    while (game->map[i])
    {
        while (game->map[i][j] && game->map[i][j] != '\n')
        {
            img_parsing(game, i, j);
            j++;
        }
        j = 0;
        width = 0;
        i++;
    }
    return (1);
}
void img_parsing(t_game *game, int i, int j)
{
    char    **carte;

    carte = game->map;
    if (carte[i][j] == '1')
    {
       define_obstacle(game,j,i);
    }
    else if (carte[i][j] == '0')
    {
        random_floor(game, i, j);
    }
    else if (carte[i][j] == 'P')
        mlx_put_image_to_window(game->mlx, game->win, game->img_player, j * IMG_SIZE, i * IMG_SIZE);
    else if (carte[i][j] == 'E' && game->collected == game->collectable)
        mlx_put_image_to_window(game->mlx, game->win, game->img_exit_open, j * IMG_SIZE, i * IMG_SIZE);
    else if (carte[i][j] == 'E')
        mlx_put_image_to_window(game->mlx, game->win, game->img_exit_close, j * IMG_SIZE, i * IMG_SIZE);
    else if (carte[i][j] == 'C')
        mlx_put_image_to_window(game->mlx, game->win, game->img_collectable, j * IMG_SIZE, i * IMG_SIZE);
    else if (carte[i][j] == 'M')
        mlx_put_image_to_window(game->mlx, game->win, game->enemy_img1, j * IMG_SIZE, i * IMG_SIZE);
}

