/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_save_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcuzin <jcuzin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 15:39:46 by jcuzin            #+#    #+#             */
/*   Updated: 2023/05/11 20:09:08 by jcuzin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"
#include <stdio.h>

int	ft_save_map(t_map *map, int lines_count)
{
	int	fd;

	map->x = 0;
	map->y = 0;
	fd = open(map->path, O_RDONLY);
	if (fd == -1)
		return (0);
	map->id = malloc(sizeof(char *) * (lines_count + 2));
	if (!map->id)
		return (close(fd), 0);
	while (map->y <= lines_count)
	{
		map->id[map->y] = get_next_line(fd);
		map->y++;
	}
	map->id[map->y] = 0;
	map->x_max = ft_strlen(map->id[0]) - 1;
	close(fd);
	return (1);
}
