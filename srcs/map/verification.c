/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verification.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmessmer <wmessmer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 17:55:23 by wmessmer          #+#    #+#             */
/*   Updated: 2023/01/13 17:47:56 by wmessmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

int ber_extension(char *file)
{
    int i;
    
    i = ft_strlen(file);
    if (file == 0)
        return (map_error(1));
    if (i < 5)
        return (map_error(1));
    if (strcmp(file + i - 4, ".ber") != 0)
        return (map_error(1));
    return (1);
}

int content_verification(char **map)
{
    int i,j;
    i = 0;

    while(map[i])
    {
        j = 0;
        while(map[i][j])
        {
            if (map[i][j] != '0' && map[i][j] != '1' && map[i][j] != 'C'
				&& map[i][j] != 'E' && map[i][j] != 'P')
                    return (map_error(4));
            j++;
        }
        i++;
    }
    return (1);
}

int wall_verification(t_game *game, char *path)
{
    int i;
    int j;
    game->mappy.col = ft_strlen(game->map[0]);
    game->mappy.row = nb_ligne(path);
    i = 0;
    while(game->map[i])
    {
        j = 0;
        while (game->map[i][j])
        {
            if (game->map[0][j] != '1' || game->map[game->mappy.row - 1][j] != '1' 
                || game->map[i][0] != '1' || game->map[i][game->mappy.col - 1] != '1')
                return (map_error(2));
                
            j++;
        }
        if (j != game->mappy.col)
            return (map_error(5));
        i++;
    }
    return (1);
}

int content_nb_verification(t_game *game)
{
    int i;
    int j;
    i = 0;
    while(game->map[i])
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
    if (game->mappy.start_count != 1 || game->mappy.exit_count != 1 || game->mappy.collectible_count <= 0)
        return(map_error(6));
    return (1);
}