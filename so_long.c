/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmessmer <wmessmer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 13:15:05 by wmessmer          #+#    #+#             */
/*   Updated: 2023/01/24 11:32:00 by wmessmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long.h"

int	main(int ac, char **av)
{
	t_game	game;

	if (ac != 2 || (ber_extension(av[1]) != 1))
		return (map_error(0));
	game.map = map_generation(av[1]);
	if (!game.map)
	{
		free (game.map);
		return (map_error(9));
	}		
	if (map_check(&game, av[1]) != 1)
		return (ft_map_destroyer(&game), 0);
	map_final_init(&game);
	player_init(&game);
	img_init_base(&game);
	if (!(map_verification_path(&game)))
		return (ft_map_destroyer(&game), 0);
	window_initialisation(&game);
	mlx_hook(game.win, KeyPress, KeyPressMask, &ft_action_keyboard, &game);
	mlx_hook(game.win, ClientMessage, LeaveWindowMask, ft_mouse, &game);
	mlx_loop(game.mlx);
	return (0);
}
