/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmessmer <wmessmer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 13:15:05 by wmessmer          #+#    #+#             */
/*   Updated: 2022/12/22 16:01:47 by wmessmer         ###   ########.fr       */
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
    ft_printf("map ok\n");
    game = map_final_init(&game,transfet_map_to_game(game.map,&map,av[1]));
    player_init(&game);
    window_initialisation(&game);
    loop_images(game);

    return (0);
}
