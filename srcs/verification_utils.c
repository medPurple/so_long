/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verification_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmessmer <wmessmer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 13:04:58 by wmessmer          #+#    #+#             */
/*   Updated: 2022/12/16 18:23:46 by wmessmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int nb_ligne(char *path)
{
	int		file;
	int		count;
	char	buf[1];
	int 	wc;

	file = open(path, O_RDWR);
	if (file == -1)
		return -1;
	count = 0;
	while ((wc = read(file, buf, 1)))
	{
		//write(1, buf, 1);
		if (*buf == '\n')
			count++;
	}
	close(file);
	return (count);
} 

int count_size_line(char *path,int max, int line)
{
	int		count;
	char 	buf[1];
	int 	line_count;
	int 	file;
	int 	wc;

	line_count = 0;
	count = 0;
	file = open(path, O_RDWR);
	if (file == -1)
		return -1;
	while ((wc = read(file, buf, 1)) && line_count <= max)
	{
		count++;
		if (*buf == '\n')
		{
			line_count++;
			if (line_count == line)
				break;
			count = 0;
		}
		wc = read(file, buf, 1);
	}
	close(file);
	return (count);
}