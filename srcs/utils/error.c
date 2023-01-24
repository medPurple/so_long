/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmessmer <wmessmer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 17:33:23 by wmessmer          #+#    #+#             */
/*   Updated: 2023/01/24 10:20:19 by wmessmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

int	map_error(int i)
{	
	if (i == 0)
		send_error("Error\nWrong arg number, u can only put 1 map\n");
	if (i == 1)
		send_error("Error\nThe map as no .ber, try again with another file\n");
	if (i == 2)
		send_error("Error\nThe map walls are invalid, try another one\n");
	if (i == 3)
		send_error("Error\nThe player can't reach the exit, or he is dumb\n");
	if (i == 4)
		send_error("Error\nInvalid characters on the map, just use 0,1,P,C,E\n");
	if (i == 5)
		send_error("Error\nNot a rectangle... bro please, simple geometry\n");
	if (i == 6)
		send_error("Error\nThe map miss something in it...maybe his ex ???\n");
	if (i == 7)
		send_error("Error\nPlayer can't collect everything\n");
	if (i == 8)
		send_error("Error\nPlayer can't reach the exit\n");
	if (i == 9)
		send_error("Error\nMap doesn't not exist\n");
	ft_printf(GRN"\n======================== Exit completed ====");
	ft_printf("==================\n\n"COLOR_RESET);
	return (0);
}

int	mlx_error(int i)
{
	if (i == 1)
		send_error("Error\nBro mlx can't create the window... cringe\n");
	if (i == 2)
		send_error("Error\nThe window is too big to fill the screen\n");
	ft_printf(GRN"\n======================== Exit completed ====");
	ft_printf("==================\n\n"COLOR_RESET);
	exit(1);
}

void	error_image(t_game *game)
{
	send_error("Error\nError with image\n\n");
	free_all_game(game);
	ft_printf(GRN"\n======================== Exit completed ====");
	ft_printf("==================\n\n"COLOR_RESET);
	exit(1);
}
