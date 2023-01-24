/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verification_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmessmer <wmessmer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 17:55:23 by wmessmer          #+#    #+#             */
/*   Updated: 2023/01/24 11:20:01 by wmessmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

int	ber_extension(char *file)
{
	int	i;

	i = ft_strlen(file);
	if (file == 0)
		return (map_error(1));
	if (i < 5)
		return (map_error(1));
	if (strcmp(file + i - 4, ".ber") != 0)
		return (map_error(1));
	ft_printf(YEL"\n======================== PROGRAM START ");
	ft_printf("=======================\n\n"COLOR_RESET);
	return (1);
}

int	content_verification(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] != '0' && game->map[i][j] != '1'
				&& game->map[i][j] != 'C'
				&& game->map[i][j] != 'E' && game->map[i][j] != 'P'
				&& game->map[i][j] != 'M')
				return (map_error(4));
			j++;
		}
		i++;
	}
	return (1);
}

int	wall_verification(t_game *game, char *path)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[0][j] != '1'
			|| game->map[game->mappy.row - 1][j] != '1'
			|| game->map[i][0] != '1'
			|| game->map[i][game->mappy.col - 1] != '1')
				return (map_error(2));
			j++;
		}
		if (j != game->mappy.col)
			return (map_error(5));
		i++;
	}
	return (1);
}

int	content_nb_verification(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'P')
				game->mappy.start_count++;
			if (game->map[i][j] == 'E')
				game->mappy.exit_count++;
			if (game->map[i][j] == 'C')
				game->mappy.collectible_count++;
			j++;
		}
		i++;
	}
	if (game->mappy.start_count != 1 || game->mappy.exit_count != 1
		|| game->mappy.collectible_count <= 0)
		return (map_error(6));
	return (1);
}
