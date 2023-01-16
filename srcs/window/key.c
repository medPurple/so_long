/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmessmer <wmessmer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 15:39:38 by wmessmer          #+#    #+#             */
/*   Updated: 2023/01/16 08:52:56 by wmessmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

int	ft_mouse(t_game *game)
{
	game_close(game);
	exit(0);
}

int ft_action_keyboard(int key, t_game *game)
{
    if (key == XK_Up || key == XK_w)
    {
        game->player.key_w = 1;
        ft_move_player(game, game->player_y - 1 , game->player_x);
    }
    else if (key == XK_Down || key == XK_s)
    {
        game->player.key_s = 1;
        ft_move_player(game, game->player_y + 1 , game->player_x);
    }
    else if (key == XK_Right || key == XK_d)
    {
        game->player.key_d = 1;
        ft_move_player(game, game->player_y , game->player_x + 1);
    }
    else if (key == XK_Left || key == XK_a)
    {
        game->player.key_a = 1;
        ft_move_player(game, game->player_y , game->player_x - 1);
    }
    if (key == XK_Escape)
        game_close(game);
    ft_printf("Move count : %d\n", game->moves);
    return (0);  
}