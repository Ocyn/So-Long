/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_map_finishable.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcuzin <jcuzin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 04:03:59 by jcuzin            #+#    #+#             */
/*   Updated: 2023/05/11 20:08:24 by jcuzin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

int	ft_count_elements(t_map map)
{
	int	result;

	result = 0;
	map.x = 0;
	map.y = 0;
	while (map.id[map.y] && map.id[map.y][map.x])
	{
		if (map.id[map.y][map.x] != '1' && map.id[map.y][map.x] != '\n')
			result++;
		if (map.id[map.y][map.x] == '\n' && map.id[map.y])
		{
			map.x = 0;
			map.y++;
		}
		map.x++;
	}
	return (result);
}

int	ft_find_entity(t_map *map, char entity)
{
	map->x = 0;
	map->y = 0;
	while (map->id[map->y][++map->x])
	{
		if (map->id[map->y][map->x] == '\n')
		{
			map->x = 0;
			map->y++;
		}
		if (map->id[map->y][map->x] == entity)
			return (1);
	}
	map->x = 0;
	map->y = 0;
	return (0);
}

char	**ft_diffusion(t_map map)
{
	if (map.entities == 0)
		return (map.id);
	if (map.id[map.y][map.x] == 'C' \
	|| map.id[map.y][map.x] == '0' || map.id[map.y][map.x] == 'P')
	{
		if (map.id[map.y][map.x] == 'C' || map.id[map.y][map.x] == 'E')
			map.entities--;
		map.id[map.y][map.x] = '*';
		map.x++;
		ft_diffusion(map);
		map.x -= 2;
		ft_diffusion(map);
		map.x++;
		map.y++;
		ft_diffusion(map);
		map.y -= 2;
		ft_diffusion(map);
		map.y++;
	}
	return (map.id);
}

int	ft_check_diffusion_result(t_map map)
{
	map.x = -1;
	map.y = 0;
	while (map.id[map.y] && map.id[map.y][++map.x])
	{
		if (map.id[map.y][map.x] != '1' && map.id[map.y][map.x] != '\n' \
		&& map.id[map.y][map.x] != '*' && map.id[map.y][map.x] != 'E')
			return (0);
		if (map.id[map.y][map.x] == '\n')
		{
			map.x = -1;
			map.y++;
		}
	}
	return (1);
}

int	ft_is_finishable(char *path, int end_l)
{
	t_map	map;

	map.x = 0;
	map.y = 0;
	map.x_max = end_l;
	map.path = path;
	map.y_max = ft_count_l(path);
	if (ft_save_map(&map, end_l) == 0)
		return (0);
	map.entities = ft_count_elements(map);
	if (ft_find_entity(&map, 'P') == 0)
		return (ft_free_map(&map), 0);
	map.id = ft_diffusion(map);
	if (ft_check_diffusion_result(map) == 0)
		return (ft_free_map(&map), 0);
	ft_free_map(&map);
	return (1);
}
