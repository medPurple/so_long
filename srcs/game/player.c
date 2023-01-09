/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmessmer <wmessmer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 11:56:16 by wmessmer          #+#    #+#             */
/*   Updated: 2023/01/08 19:17:16 by wmessmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"
void player_init(t_game *player)
{
    int i;
    int j;

    i = 0;
    while (player->map[i])
    {
        j = 0;
        while (player->map[i][j])
        {
            if (player->map[i][j] == 'P')
            {
                player->player_y = i;
                player->player_x = j;
            }
            j++;
        }
        i++;
    }
    player->moves = 0;
}