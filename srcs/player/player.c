/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmessmer <wmessmer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 11:56:16 by wmessmer          #+#    #+#             */
/*   Updated: 2022/12/19 12:23:37 by wmessmer         ###   ########.fr       */
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
                player->x = i;
                player->y = j;
            }
            j++;
        }
        i++;
    }
}