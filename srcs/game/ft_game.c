/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmessmer <wmessmer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 14:18:40 by wmessmer          #+#    #+#             */
/*   Updated: 2023/01/13 08:30:14 by wmessmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

int ft_action_keyboard(int key, t_game *game)
{
    if (key == XK_Up || key == XK_w)      //move up
        ft_move_player(game, game->player_y - 1 , game->player_x);
    else if (key == XK_Down || key == XK_s) //move down
        ft_move_player(game, game->player_y + 1 , game->player_x);
    else if (key == XK_Right || key == XK_d) //move right
        ft_move_player(game, game->player_y , game->player_x + 1);
    else if (key == XK_Left || key == XK_a) //move left
        ft_move_player(game, game->player_y , game->player_x - 1);
    if (key == XK_Escape) // esc
        game_close(game);
    ft_printf("Move count : %d\n", game->moves);
    return (0);  
}

void ft_move_player(t_game *game, int y, int x)
{
    int lx;
    int ly;

    lx = game->player_x;
    ly = game->player_y;
    if (game->map[y][x] == 'E' && game->collected == game->collectable)
        game_victory(game);
    else if (game->map[y][x] == 'C' || game->map[y][x] == '0')
    {
        game->map[ly][lx] = '0';
        if (game->map[y][x] == 'C')
            game->collected += 1;        
        game->player_x = x;
        game->player_y = y;
        game->map[y][x] = 'P';
        game->moves += 1;
        map_actualisation(game,lx,ly);
    }
}
    
int game_victory(t_game *game)
{
    ft_printf(YEL"===============================================================\n");
    ft_printf("========================  [Victory !]  ========================\n");
    ft_printf("===============================================================\n"COLOR_RESET);

    ft_printf("\nNombre de deplacements totaux : %d\n", game->moves +1);
    free_all_game(game);
    ft_printf(GRN"\n======================== Exit completed =======================\n\n"COLOR_RESET);
    exit (0);
}

int game_close(t_game *game)
{
    ft_printf(RED"======================== Game closed =========================\n"COLOR_RESET);
    ft_printf("Deplacement effectue : %d\n", game->moves);
    free_all_game(game);
    ft_printf(GRN"======================== Exit completed ======================\n\n"COLOR_RESET);
    exit(0);
}

int	ft_mouse(t_game *game)
{
	game_close(game);
	exit(0);
}