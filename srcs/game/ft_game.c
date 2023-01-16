/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmessmer <wmessmer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 14:18:40 by wmessmer          #+#    #+#             */
/*   Updated: 2023/01/16 19:45:38 by wmessmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

int	game_victory(t_game *game)
{
	ft_printf(YEL"================================");
	ft_printf("===============================\n");
	ft_printf("========================  [Victory !]  ====");
	ft_printf("====================\n");
	ft_printf("=======================================");
	ft_printf("========================\n"COLOR_RESET);
	ft_printf("\nNombre de deplacements totaux : %d\n", game->moves +1);
	free_all_game(game);
	ft_printf(GRN"\n======================== Exit completed ======");
	ft_printf("=================\n\n"COLOR_RESET);
	exit (0);
}

int	game_loose(t_game *game)
{
	ft_printf(RED"======================================");
	ft_printf("=========================\n");
	ft_printf("========================  [Game over]  ====");
	ft_printf("====================\n");
	ft_printf("============================================");
	ft_printf("===================\n"COLOR_RESET);
	ft_printf("\nNombre de deplacements totaux : %d\n", game->moves +1);
	free_all_game(game);
	ft_printf(GRN"\n======================== Exit completed ====");
	ft_printf("===================\n\n"COLOR_RESET);
	exit (0);
}

int	game_close(t_game *game)
{
	ft_printf(RED"======================== Game closed ====");
	ft_printf("=====================\n"COLOR_RESET);
	ft_printf("\n                  Deplacement effectue : %d\n", game->moves);
	free_all_game(game);
	ft_printf(GRN"\n======================== Exit completed ====");
	ft_printf("==================\n\n"COLOR_RESET);
	exit(0);
}

void move_actualisation(t_game *game)
{
	char *mov ;
	char *st;
	char *str;
	int i;
	int j;
	
	j =  game->win_height - 24;
	i = 0;
	mov = ft_itoa(game->moves);
	st = ft_strdup("Deplacement : ");
	str = ft_strjoin(st , mov);
	while (j++ < game->win_height)
	{
		while (i++ < game->win_width)
			mlx_pixel_put(game->mlx,game->win,i,j, 0x000000);
		i = 0;
	}
	mlx_string_put(game->mlx, game->win, (game->win_width / 2) - 48, game->win_height - 12   , 0xFF99FF, str);
	free(str);
	free(mov);
}