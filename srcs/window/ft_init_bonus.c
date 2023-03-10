/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmessmer <wmessmer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 19:22:48 by wmessmer          #+#    #+#             */
/*   Updated: 2023/01/23 15:58:01 by wmessmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

int	window_initialisation(t_game *window)
{
	ft_printf(BLU"\n======================== GAME STARTED ");
	ft_printf("========================\n\n"COLOR_RESET);
	if (window->mappy.row * 48 > 1440 || window->mappy.col * 48 > 2560)
	{
		ft_map_destroyer(window);
		return (mlx_error(2));
	}
	window->mlx = mlx_init();
	if (window->mlx == NULL)
		return (mlx_error(1));
	window->win = mlx_new_window(window->mlx, \
		window->win_width, window->win_height + 24, "LE GAMING BITCH");
	if (window->win == NULL)
	{
		free(window->win);
		return (mlx_error(1));
	}
	image_initialisation(window);
	return (1);
}

void	image_initialisation(t_game *game)
{
	ground_to_img(game);
	obstacle_to_img(game);
	other_to_img(game);
	player_to_img(game);
	render_maps(game);
}

int	render_maps(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	if (game->win == NULL)
		return (mlx_error(1));
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			img_parsing(game, i, j);
			j++;
		}
		i++;
	}
	mlx_string_put(game->mlx, game->win, (game->win_width / 2) - 48, \
		game->win_height + 12, 0xFF99FF, "Deplacement : 0");
	generate_enemy(game);
	return (1);
}

void	img_parsing(t_game *game, int i, int j)
{
	char	**carte;

	carte = game->map;
	if (carte[i][j] == '1')
		define_obstacle(game, j, i);
	else if (carte[i][j] == '0')
		random_floor(game, i, j, clock() % 100 + 1);
	else if (game->map[i][j] == 'P')
		mlx_put_image_to_window(game->mlx, \
			game->win, game->img_player, j * IMG_SIZE, i * IMG_SIZE);
	else if (game->map[i][j] == 'E' && game->collected == game->collectable)
		mlx_put_image_to_window(game->mlx, \
			game->win, game->img_exit_open, j * IMG_SIZE, i * IMG_SIZE);
	else if (game->map[i][j] == 'E')
		mlx_put_image_to_window(game->mlx, \
			game->win, game->img_exit_close, j * IMG_SIZE, i * IMG_SIZE);
	else if (game->map[i][j] == 'C')
		mlx_put_image_to_window(game->mlx, \
			game->win, game->img_collectable, j * IMG_SIZE, i * IMG_SIZE);
	else if (carte[i][j] == 'M')
		mlx_put_image_to_window(game->mlx, \
			game->win, game->enemy_img1, j * IMG_SIZE, i * IMG_SIZE);
}
