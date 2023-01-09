/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmessmer <wmessmer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 17:33:23 by wmessmer          #+#    #+#             */
/*   Updated: 2023/01/08 19:20:09 by wmessmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

int map_error(int i)
{
    if (i == 0)
        ft_printf("Wrong arg number, u can only put 1 map\nHeard about a spider cartographer.  He makes web-based maps.");
    if (i == 1)
        ft_printf("The map as no .ber, try again with another file and drink a beer");
    if (i == 2)
        ft_printf("The map walls are invalid, try another one (insert funny joke)");
    if (i == 3)
        ft_printf("The player can't reach the exit, or he is dumb");
    if (i == 4)
        ft_printf("Invalid characters on the map, just use 0,1,P,C,E");
    if (i == 5)
        ft_printf("Not a rectangle... bro please, simple geometry");
    if (i == 6)
        ft_printf("The map miss something in it...maybe his ex ???");
    return (0);
}

int mlx_error(int i)
{
    if (i == 1)
        ft_printf("Bro mlx can't create the window... cringe");
    return (0);
}

