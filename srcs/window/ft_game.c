/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmessmer <wmessmer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 14:18:40 by wmessmer          #+#    #+#             */
/*   Updated: 2022/12/22 14:40:09 by wmessmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	loop_images(t_game game)
{
	mlx_loop_hook(game.mlx, &render_maps, &game);
	mlx_hook(game.win, KeyPress, KeyPressMask, &handle_keypress, &game);
	mlx_hook(game.win, ClientMessage, LeaveWindowMask,
		&handle_btnrealease, &game);
	mlx_loop(game.mlx);
}

int	handle_resize(t_game *data)
{
	render_maps(data);
	return (0);
}

int	handle_keypress(int keysym, t_game *data)
{
	if (keysym == XK_Escape)
	{
		mlx_destroy_window(data->mlx, data->win);
		data->win = NULL;
	}
	/*else if (ft_strchr("wasd", keysym))
		move_player(data, keysym);*/
	return (0);
}

int	handle_btnrealease(t_game *data)
{
	mlx_destroy_window(data->mlx, data->win);
	data->win = NULL;
	return (0);
}