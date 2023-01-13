/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmessmer <wmessmer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 11:19:57 by wmessmer          #+#    #+#             */
/*   Updated: 2023/01/13 17:58:22 by wmessmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

int **blanktab(t_game *game)
{
    int **grid;
    int i;
    int j;

    grid = malloc((game->mappy.row) * sizeof(int *));
    i = 0;
    j = 0;
    while (i < game->mappy.row)
    {
        grid[i] = malloc((game->mappy.col) * sizeof(int));
        j = 0;
        while (j < game->mappy.col)
        {
            grid[i][j] = 0;
            j++;
        }
        i++;
    }
    return (grid);
}

int pathfinder(t_game *game,int i, int j,int **grid)
{
    //printf("x : %d, y : %d c : %d\n",i, j,grid[i][j]);
    if (!(i > 0 && i < game->mappy.row - 1 && j > 0 && j < game->mappy.col - 1))
        return(game->collectable_valid);
    if (!(game->map[i][j] != '1' && game->map[i][j] != 'E' && game->map[i][j] != 'M'))
        return(game->collectable_valid);
    if ((game->end_game_ok == 1) || (exit_exist(game,grid) == 1))
        game->end_game_ok = 1;
    if (game->map[i][j] == 'C' && grid[i][j] != 1)
        game->collectable_valid++;
    if (grid[i][j] == 1)
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

    game->end_game_ok = 0;
    game->collectable_valid = 0;
    grid = blanktab(game);
    if (pathfinder(game, game->player_x,game->player_y,grid) != game->mappy.collectible_count)
    {
        ft_map_destroyer_int(grid,game);
        return (ft_printf("Can't collect everything\n"),0);
    }
    if (game->end_game_ok != 1)
    {
        ft_map_destroyer_int(grid,game);
        return (ft_printf("Can't reach the exit\n"),0);
    }
    ft_map_destroyer_int(grid,game);
    return (1);
}

int exit_exist(t_game *game, int **truc)
{
    exit_init(game);
    if (truc[game->exit_y - 1][game->exit_x] == 1)
        return (1);
    if (truc[game->exit_y + 1][game->exit_x] == 1)
        return (1);
    if (truc[game->exit_y][game->exit_x - 1] == 1)
        return (1);
    if (truc[game->exit_y][game->exit_x + 1] == 1)
        return (1);
    return(0);
}

