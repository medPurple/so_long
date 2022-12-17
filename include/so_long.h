/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmessmer <wmessmer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 18:04:43 by wmessmer          #+#    #+#             */
/*   Updated: 2022/12/16 18:09:32 by wmessmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../lib/mlx/mlx.h"
# include "../lib/42-libft/include/libft.h"

/*map*/
int map_verification_wall(char **file);
int map_verification_path(char **file);
int map_error(int i);

/*verif*/
int ber_verification(char *file);

/*utils*/
int nb_ligne(char *path);
int count_size_line(char *path,int max, int line);



#endif