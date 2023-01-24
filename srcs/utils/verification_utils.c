/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verification_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmessmer <wmessmer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 13:04:58 by wmessmer          #+#    #+#             */
/*   Updated: 2023/01/13 17:50:48 by wmessmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

int	nb_ligne(char *path)
{
	int		fd;
	char	*line;
	int		line_count;

	line_count = 0;
	fd = open(path, O_RDONLY);
	line = get_next_line(fd);
	while (line != NULL)
	{
		line_count++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (line_count);
}

void	exit_init(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->mappy.row)
	{
		j = 0;
		while (j < game->mappy.col)
		{
			if (game->map[i][j] == 'E')
			{
				game->exit_y = i;
				game->exit_x = j;
			}
			j++;
		}
		i++;
	}
}

void	printmap(int **map_copy, int r, int c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < r)
	{
		while (j < c)
		{
			ft_printf("%d", map_copy[i][j]);
			j++;
		}
		j = 0;
		i++;
		printf("\n");
	}
	printf("\n");
}
