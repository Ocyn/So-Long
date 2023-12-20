/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcuzin <jcuzin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 18:19:18 by jcuzin            #+#    #+#             */
/*   Updated: 2023/05/11 20:08:40 by jcuzin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

int	ft_check_ber(char *path, char *check)
{
	int		i;
	int		i2;

	i = 0;
	while (path[i])
	{
		i2 = 0;
		while (path[i] == check[i2] && i2 <= 4)
		{
			if (i2 == 4 && path[i] == check[i2])
				return (1);
			i2++;
			i++;
		}
		i++;
	}
	return (0);
}

int	ft_check_path(t_map *map, char *path)
{
	int		fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (close(fd), 0);
	if (ft_check_ber(path, ".ber") == 0)
		return (close(fd), 0);
	map->path = path;
	return (close(fd), 1);
}

int	ft_is_empty(char *path)
{
	int		fd;
	char	*l;

	fd = open(path, O_RDONLY);
	l = get_next_line(fd);
	if (!l || !l[0])
		return (close(fd), free(l), 0);
	return (close(fd), free(l), 1);
}

int	ft_parse_map(char *path)
{
	t_map	map;
	int		ls_nb;

	ls_nb = ft_count_l(path) - 1;
	map.y_max = ft_count_l(path);
	if (ft_check_path(&map, path) == 0)
		return (ft_printf("\nError\n\"%s\" is not a valid path\n", path), 0);
	if (ft_is_empty(path) == 0 || ls_nb < 2)
		return (ft_printf("\nError\nEmpty map or new lines before map\n"), 0);
	if (ft_check_lines(open(path, O_RDONLY), ls_nb, 0, 0) == 0)
		return (ft_printf("\nError\nMisaligned lines\n"), 0);
	if (ft_check_entity(open(path, O_RDONLY), ls_nb, 0, 0) == 0)
		return (ft_printf("\nError\nInvalid entity (or many) in the map\n"), 0);
	if (ft_save_map(&map, ls_nb) == 0)
		return (ft_printf("\nError\nMap cannot be saved\n"), 0);
	if (ft_check_rep(open(path, O_RDONLY), 0) == 0 || ft_count_coin(map) == 0)
	{
		map.y_max--;
		return (ft_printf("\nError\nInvalid entities\n"), ft_free_map(&map), 0);
	}
	if (ft_check_borders(map, ls_nb) == 0)
		return (ft_printf("\nError\nMissing map's borders\n"), 0);
	if (ft_is_finishable(path, ls_nb) == 0)
		return (ft_printf("\nError\nGame unfinishable\n"), 0);
	return (ft_printf("\nMap OK"), 1);
}
