/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmessmer <wmessmer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 18:15:10 by wmessmer          #+#    #+#             */
/*   Updated: 2023/01/12 16:01:19 by wmessmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

int map_check(char **map, char *file)
{
    t_map   map_info;

    map_init(&map_info);
    if (!map)
        return (0);
    if (ber_extension(file) == 1)
    {
        if(content_verification(map) == 1)
        {
            if ((wall_verification(map,&map_info,file)) == 1)
            {
                if (content_nb_verification(map,&map_info) == 1)
                {
                        return(1);
                }
            }
        }
    }
   return (0); 
}

void map_init(t_map *map)
{
    map->col = 0;
    map->row = 0;
    map->start_count = 0;
    map->collectible_count = 0;
    map->exit_count = 0;
}

char **map_generation(char *file)
{
    char **map_final;
    char *fichier;
    char *backup;
    char *map;
    int fd;
    
    fd = open(file, O_RDONLY);
    if (fd == -1)
        return (NULL);
    map = ft_strdup("");
    while((fichier = get_next_line(fd)))
    {
        if (!file)
            return (NULL);
        backup = map;
        map = ft_strjoin(backup,fichier);
    }
    map_final = ft_split(map,'\n');
    free(map);
    close(fd);
    return(map_final);
}

t_game map_final_init(t_game *map,t_map info)
{
    map->win_width = (info.col + 1) * IMG_SIZE;
    //ft_printf("%i\n",map->win_width);
    map->win_height = (info.row + 1) * IMG_SIZE;
    //ft_printf("%i\n",map->win_height);
    map->img_height = IMG_SIZE;
    map->img_width = IMG_SIZE;
    map->moves = 0;
    map->collectable = info.collectible_count;
    map->collected = 0;
    return(*map);
}