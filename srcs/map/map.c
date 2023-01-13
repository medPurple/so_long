/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmessmer <wmessmer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 18:15:10 by wmessmer          #+#    #+#             */
/*   Updated: 2023/01/13 18:33:41 by wmessmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

int map_check(t_game *game, char *file)
{
    map_init(game);
    if (!game->map)
        return (0);
    if (ber_extension(file) == 1)
    {
        if(content_verification(game->map) == 1)
        {
            if ((wall_verification(game,file)) == 1)
            {
                if (content_nb_verification(game) == 1)
                {
                        return(1);
                }
            }
        }
    }
   return (0); 
}

void map_init(t_game *game)
{
    game->mappy.col = 0;
    game->mappy.row = 0;
    game->mappy.start_count = 0;
    game->mappy.collectible_count = 0;
    game->mappy.exit_count = 0;
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
        if (!fichier)
            return (NULL);
        backup = map;
        map = ft_strjoin(backup,fichier);
        free(fichier);
    }
    map_final = ft_split(map,'\n');
    free(map);
    close(fd);
    return(map_final);
}

void map_final_init(t_game *game)
{
    game->win_width = (game->mappy.col + 1) * IMG_SIZE;
    game->win_height = (game->mappy.row) * IMG_SIZE;
    game->img_height = IMG_SIZE;
    game->img_width = IMG_SIZE;
    game->moves = 0;
    game->collectable = game->mappy.collectible_count;
    game->collected = 0;
}