/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmessmer <wmessmer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 11:19:57 by wmessmer          #+#    #+#             */
/*   Updated: 2023/01/09 18:41:17 by wmessmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

int **blanktab(t_map *map)
{
    int ** grid;
    int i;
    int j;

    grid = malloc((map->row + 1) * sizeof(int));
    i = 0;
    j = 0;
    while (i < map->row)
    {
        grid[i] = malloc((map->col + 1) * sizeof(int));
        j = 0;
        while (j < map->row)
        {
            grid[i][j] = 0;
            j++;
        }
        grid[i][j] = '\0';
        i++;
    }
    grid[i] = NULL;
    return (grid);
}

int pathfinder(t_game *game,int i, int j,int **grid)
{
    t_map *map;
    
    if (game->map[i][j] == 'E')
        game->end_game_ok = 1;
    if (game->map[i][j] == 'C' && grid[i][j] != 1)
        game->collectable_valid++;
    ft_printf("ok");
    if (grid[i][j] == 1)
        return(game->collectable_valid);
    ft_printf("ok2");
    if (!(i >= 0 && i < map->row && j > 0 && j < map->col && game->map[i][j] != '1'))
        return(game->collectable_valid);
    grid[i][j] = 1;
    
    game->collectable_valid= pathfinder(game, i + 1, j, grid);
    game->collectable_valid= pathfinder(game, i, j + 1, grid);
    game->collectable_valid= pathfinder(game, i - 1, j, grid);
    game->collectable_valid= pathfinder(game, i, j- 1, grid);
    return(game->collectable_valid);
}

int map_verification_path(t_game *game)
{
    int **grid;
    t_map map;
    
    game->end_game_ok = 0;
    game->collectable_valid = 0;
    grid = blanktab(&map);
    ft_printf("%d\n",game->player_x);
    ft_printf("%d\n",game->player_x);
    if (pathfinder(game,game->player_x,game->player_y,grid) != map.collectible_count)
        return (ft_printf("Can't collect everything"),0);
    free(grid);
    if (game->end_game_ok != 1)
        return (ft_printf("Can't reach the exit"),0);
    return (1);
}