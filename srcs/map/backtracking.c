/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmessmer <wmessmer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 11:19:57 by wmessmer          #+#    #+#             */
/*   Updated: 2023/01/10 10:57:31 by wmessmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

int **blanktab(t_map *map)
{
    int ** grid;
    int i;
    int j;

    grid = malloc((map->row) * sizeof(int *));
    i = 0;
    j = 0;
    while (i < map->row)
    {
        grid[i] = malloc((map->col) * sizeof(int));
        j = 0;
        while (j < map->col)
        {
            grid[i][j] = 0;
            j++;
        }
        i++;
    }
    return (grid);
}

int pathfinder(t_game *game,int i, int j,int **grid,t_map *map)
{
    if (!(i >= 0 && i < map->row && j > 0 && j < map->col && game->map[i][j] != '1'))
        return(game->collectable_valid);
    if (game->map[i][j] == 'E')
        game->end_game_ok = 1;
    if (game->map[i][j] == 'C' && grid[i][j] != 1)
        game->collectable_valid++;
    if (grid[i][j] == 1)
        return(game->collectable_valid);
    grid[i][j] = 1;
    
    game->collectable_valid= pathfinder(game, i + 1, j, grid,map);
    game->collectable_valid= pathfinder(game, i, j + 1, grid, map);
    game->collectable_valid= pathfinder(game, i - 1, j, grid, map);
    game->collectable_valid= pathfinder(game, i, j- 1, grid, map);
    return(game->collectable_valid);
}

int map_verification_path(t_game *game,t_map *map)
{
    int **grid;

    
    game->end_game_ok = 0;
    game->collectable_valid = 0;
    grid = blanktab(map);
    if (pathfinder(game,game->player_x,game->player_y,grid, map) != map->collectible_count)
        return (ft_printf("Can't collect everything"),0);
    free(grid);
    if (game->end_game_ok != 1)
        return (ft_printf("Can't reach the exit"),0);
    return (1);
}