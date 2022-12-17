/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verification.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmessmer <wmessmer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 17:55:23 by wmessmer          #+#    #+#             */
/*   Updated: 2022/12/16 18:27:14 by wmessmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int ber_verification(char *file)
{
    int i;
    
    i = ft_strlen(file);
    if (file == 0)
        return (0);
    if (i < 5)
        return (0);
    if (strcmp(file + i - 4, ".ber") != 0)
        return (0);
    return (1);
}

int map_verification_wall(char **file)
{
    int size_max= nb_ligne(file[1]) - 1;
    int line_count = 0;
    int fd = open(file[1], O_RDONLY);
    char *line;
    int ba = count_size_line(file[1],size_max,1);
    printf("%d",ba);
   /* if (line_count == 0 || line_count == size_max)
    {
        while (/bufer++ != 'n')
        {
            if (buffer != '1)
                return (0);
        }
    }
    else
    {
        
    }*/
    return(1);
}

int map_verification_path(char **file)
{
    return (1);
}