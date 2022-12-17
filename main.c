/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmessmer <wmessmer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 13:15:05 by wmessmer          #+#    #+#             */
/*   Updated: 2022/12/16 18:09:08 by wmessmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long.h"

int main(int ac, char **av)
{   
    if (ac != 2)
        return (map_error(0));
    else if (ber_verification(av[1]) != 1)
        return (map_error(1));
    else if (map_verification_wall(av) != 1)
        return (map_error(2));
    else if (map_verification_path(av) != 1)
        return (map_error(3));
    
    
    return (0);
}