/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmessmer <wmessmer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 17:33:23 by wmessmer          #+#    #+#             */
/*   Updated: 2022/12/16 12:03:35 by wmessmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int map_error(int i)
{
    if (i == 0)
        ft_printf("Wrong arg number, u can only put 1 map\n");
    if (i == 1)
        ft_printf("The map as no .ber, try again with another file");
    if (i == 2)
        ft_printf("The map walls are invalid, try another one");
    if (i == 3)
        ft_printf("The player can't reach the exit");
    return (0);
}