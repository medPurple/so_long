/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verification.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmessmer <wmessmer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 17:55:23 by wmessmer          #+#    #+#             */
/*   Updated: 2023/01/09 11:49:54 by wmessmer         ###   ########.fr       */
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

int wall_verification(char **map, t_map *map_info,char *path)
{
    int i,j;
    map_info->col = ft_strlen(map[0]);
    map_info->row = nb_ligne(path);


    i = 0;
    while(map[i])
    {
        j = 0;
        while (map[i][j])
        {
            if (map[0][j] != '1' || map[map_info->row - 1][j] != '1' 
                || map[i][0] != '1' || map[i][map_info->col -1] != '1')
                return (map_error(2));
                
            j++;
        }
        if (j != map_info->col)
            return (map_error(5));
        i++;
    }
    return (1);
}

int content_nb_verification(char **map, t_map *map_info)
{
    int i,j;
    i = 0;
    while(map[i])
    {
        j = 0;
        while (map[i][j])
        {
            if (map[i][j] == 'P')
                map_info->start_count++;
            if (map[i][j] == 'E')
                map_info->exit_count++;
            if (map[i][j] == 'C')
                map_info->collectible_count++;
            j++;
        }
        i++;
    }
    if (map_info->start_count != 1 || map_info->exit_count != 1 || map_info->collectible_count <= 0)
        return(map_error(6));
    return (1);
}