/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmessmer <wmessmer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 19:22:48 by wmessmer          #+#    #+#             */
/*   Updated: 2023/01/23 15:57:58 by wmessmer         ###   ########.fr       */
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
		window->win_width, window->win_height, "LE GAMING BITCH");
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
	obstacle_to_img(game);
	player_to_img(game);
	game->img_ground1 = mlx_xpm_file_to_image(game->mlx, \
		GROUND_IMG1, &game->img_width, &game->img_height);
	game->img_collectable = mlx_xpm_file_to_image(game->mlx, \
		COLLECTABLE_IMG1, &game->img_width, &game->img_height);
	game->img_exit_close = mlx_xpm_file_to_image(game->mlx, \
		EXIT_IMG_C, &game->img_width, &game->img_height);
	game->img_exit_open = mlx_xpm_file_to_image(game->mlx, \
		EXIT_IMG_O, &game->img_width, &game->img_height);
	verif_img_1(game);
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
	return (1);
}

void	img_parsing(t_game *game, int i, int j)
{
	if (game->map[i][j] == '1')
		define_obstacle(game, j, i);
	else if (game->map[i][j] == '0')
		mlx_put_image_to_window(game->mlx, \
			game->win, game->img_ground1, j * IMG_SIZE, i * IMG_SIZE);
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
}
