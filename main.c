/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmessmer <wmessmer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 13:15:05 by wmessmer          #+#    #+#             */
/*   Updated: 2023/01/09 18:23:37 by wmessmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long.h"

int main(int ac, char **av)
{
    t_game game;
    t_map map;

    if (ac != 2)
        return (map_error(0));
    game.map = map_generation(av[1]);
    if (game.map == NULL)
        return (map_error(1));
    if (map_check(game.map, av[1]) != 1)
    {
        //free map
        return (0);
    }
    game = map_final_init(&game,transfet_map_to_game(game.map,&map,av[1]));
    player_init(&game);
    map_verification_path(&game);
    ft_printf(BLU"\n======================== GAME STARTED ========================\n\n"COLOR_RESET);
    window_initialisation(&game);
    mlx_hook(game.win, KeyPress, KeyPressMask, ft_action_keyboard, &game);
    mlx_loop(game.mlx);
    free_all_game(&game);
    return (0);
}
