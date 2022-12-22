/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmessmer <wmessmer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 19:22:48 by wmessmer          #+#    #+#             */
/*   Updated: 2022/12/22 15:56:53 by wmessmer         ###   ########.fr       */
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
    game->img_ground = mlx_xpm_file_to_image(game->mlx,GROUND_IMG,&game->img_width,&game->img_height);
    if (game->img_width == 0 || game->img_height == 0)
    {
        ft_printf("stop");
        mlx_error(1);
    }
    game->img_wall = mlx_xpm_file_to_image(game->mlx,WALL_IMG,&game->img_width,&game->img_height);
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
    game->img_player = mlx_xpm_file_to_image(game->mlx,PLAYER_IMG,&game->img_width,&game->img_height);
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
    game->img_collectable = mlx_xpm_file_to_image(game->mlx,COLLECTABLE_IMG1,&game->img_width,&game->img_height);
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
            ft_printf("parsing\n");
            ft_printf(" i = %i\n",i);
            ft_printf(" j = %i\n",j);
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
    ft_printf(" map = %c\n",carte[i][j]);
    if (carte[i][j] == '1')
        mlx_put_image_to_window(game->mlx, game->win, game->img_wall, i * IMG_SIZE, j * IMG_SIZE);
    else if (carte[i][j] == '0')
        mlx_put_image_to_window(game->mlx, game->win, game->img_ground, i * IMG_SIZE, j * IMG_SIZE);
    else if (carte[i][j] == 'P')
        mlx_put_image_to_window(game->mlx, game->win, game->img_player, i * IMG_SIZE, j * IMG_SIZE);
    else if (carte[i][j] == 'E')
        mlx_put_image_to_window(game->mlx, game->win, game->img_exit_close, i * IMG_SIZE, j * IMG_SIZE);
    else if (carte[i][j] == 'C')
        mlx_put_image_to_window(game->mlx, game->win, game->img_collectable, i * IMG_SIZE, j * IMG_SIZE);
}