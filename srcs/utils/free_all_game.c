/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all_game.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmessmer <wmessmer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 08:55:20 by wmessmer          #+#    #+#             */
/*   Updated: 2023/01/23 13:56:00 by wmessmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	free_all_game(t_game *game)
{
	ft_map_destroyer(game);
	img_clear_base(game);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free (game->mlx);
}

void	ft_map_destroyer(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->mappy.row)
	{
		free (game->map[i]);
		i++;
	}
	free(game->map);
}

void	ft_map_destroyer_int(int **map, t_game *game)
{
	int	i;

	i = 0;
	while (i < game->mappy.row)
	{
		free (map[i]);
		i++;
	}
	free(map);
}
