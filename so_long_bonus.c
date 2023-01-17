/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmessmer <wmessmer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 13:15:05 by wmessmer          #+#    #+#             */
/*   Updated: 2023/01/17 14:26:46 by wmessmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long.h"

int main(int ac, char **av)
{
    t_game game;

    if (ac != 2 || (ber_extension(av[1]) != 1))
        return (0);
    game.map = map_generation(av[1]);
    if (game.map == NULL)
        free(game.map);
    if (map_check(&game, av[1]) != 1)
        return (0);
    map_final_init(&game);
    player_init(&game);
    if (!(map_verification_path(&game)))
    {
        ft_map_destroyer(&game);
        return (0);
    }
    ft_printf(BLU"\n======================== GAME STARTED ========================\n\n"COLOR_RESET);
    window_initialisation(&game);
    mlx_hook(game.win, KeyPress, KeyPressMask, &ft_action_keyboard, &game);
    mlx_hook(game.win, ClientMessage, LeaveWindowMask, ft_mouse, &game);
    mlx_loop_hook(game.mlx, ft_render,&game);
    mlx_loop(game.mlx);
    return (0);
}
